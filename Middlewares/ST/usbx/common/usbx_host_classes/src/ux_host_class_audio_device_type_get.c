/**************************************************************************/
/*                                                                        */
/*       Copyright (c) Microsoft Corporation. All rights reserved.        */
/*                                                                        */
/*       This software is licensed under the Microsoft Software License   */
/*       Terms for Microsoft Azure RTOS. Full text of the license can be  */
/*       found in the LICENSE file at https://aka.ms/AzureRTOS_EULA       */
/*       and in the root directory of this software.                      */
/*                                                                        */
/**************************************************************************/


/**************************************************************************/
/**************************************************************************/
/**                                                                       */ 
/** USBX Component                                                        */ 
/**                                                                       */
/**   Audio Class                                                         */
/**                                                                       */
/**************************************************************************/
/**************************************************************************/


/* Include necessary system files.  */

#define UX_SOURCE_CODE

#include "ux_api.h"
#include "ux_host_class_audio.h"
#include "ux_host_stack.h"


/**************************************************************************/ 
/*                                                                        */ 
/*  FUNCTION                                               RELEASE        */ 
/*                                                                        */ 
/*    _ux_host_class_audio_device_type_get                PORTABLE C      */ 
/*                                                           6.1          */
/*  AUTHOR                                                                */
/*                                                                        */
/*    Chaoqiong Xiao, Microsoft Corporation                               */
/*                                                                        */
/*  DESCRIPTION                                                           */
/*                                                                        */ 
/*    This function obtains the device type.                              */ 
/*                                                                        */ 
/*  INPUT                                                                 */ 
/*                                                                        */ 
/*    audio                                 Pointer to audio class        */ 
/*                                                                        */ 
/*  OUTPUT                                                                */ 
/*                                                                        */ 
/*    Completion Status                                                   */ 
/*                                                                        */ 
/*  CALLS                                                                 */ 
/*                                                                        */ 
/*    _ux_utility_descriptor_parse          Parse descriptor              */ 
/*                                                                        */ 
/*  CALLED BY                                                             */ 
/*                                                                        */ 
/*    Audio Class                                                         */ 
/*                                                                        */ 
/*  RELEASE HISTORY                                                       */ 
/*                                                                        */ 
/*    DATE              NAME                      DESCRIPTION             */ 
/*                                                                        */ 
/*  05-19-2020     Chaoqiong Xiao           Initial Version 6.0           */
/*  09-30-2020     Chaoqiong Xiao           Modified comment(s),          */
/*                                            resulting in version 6.1    */
/*                                                                        */
/**************************************************************************/
UINT  _ux_host_class_audio_device_type_get(UX_HOST_CLASS_AUDIO *audio)
{

UCHAR *                                         descriptor;
UX_INTERFACE_DESCRIPTOR                         interface_descriptor;
UX_HOST_CLASS_AUDIO_OUTPUT_TERMINAL_DESCRIPTOR  output_interface_descriptor;
UX_HOST_CLASS_AUDIO_INPUT_TERMINAL_DESCRIPTOR   input_interface_descriptor;
ULONG                                           total_descriptor_length;
ULONG                                           descriptor_length;
ULONG                                           descriptor_type;
ULONG                                           descriptor_subtype;
ULONG                                           descriptor_found;
    

    /* Get the descriptor to the entire configuration.  */
    descriptor =               audio -> ux_host_class_audio_configuration_descriptor;
    total_descriptor_length =  audio -> ux_host_class_audio_configuration_descriptor_length;
    
    /* Default is Interface descriptor not yet found.  */    
    descriptor_found =  UX_FALSE;
    
    /* Scan the descriptor for the Audio Streaming interface.  */
    while (total_descriptor_length)
    {

        /* Gather the length, type and subtype of the descriptor.  */
        descriptor_length =   *descriptor;
        descriptor_type =     *(descriptor + 1);
        descriptor_subtype =  *(descriptor + 2);

        /* Make sure this descriptor has at least the minimum length.  */
        if (descriptor_length < 3)
        {

            /* Error trap. */
            _ux_system_error_handler(UX_SYSTEM_LEVEL_THREAD, UX_SYSTEM_CONTEXT_CLASS, UX_DESCRIPTOR_CORRUPTED);

            /* If trace is enabled, insert this event into the trace buffer.  */
            UX_TRACE_IN_LINE_INSERT(UX_TRACE_ERROR, UX_DESCRIPTOR_CORRUPTED, descriptor, 0, 0, UX_TRACE_ERRORS, 0, 0)

            return(UX_DESCRIPTOR_CORRUPTED);
        }

        /* Process relative to the descriptor type.  */
        switch (descriptor_type)
        {


        case UX_INTERFACE_DESCRIPTOR_ITEM:

            /* Parse the interface descriptor and make it machine independent.  */
            _ux_utility_descriptor_parse(descriptor, _ux_system_interface_descriptor_structure,
                                            UX_INTERFACE_DESCRIPTOR_ENTRIES, (UCHAR *) &interface_descriptor);

            /* Ensure we have the correct interface for Audio Control.  */
            if ((interface_descriptor.bInterfaceClass == UX_HOST_CLASS_AUDIO_CLASS) &&
                (interface_descriptor.bInterfaceSubClass == UX_HOST_CLASS_AUDIO_SUBCLASS_CONTROL))
            {

                /* Mark we have found it.  */
                descriptor_found =  UX_TRUE;

                /* Get the interface number of this descriptor and save it in the audio 
                   instance. This will be useful to program the audio controls.  */
                audio -> ux_host_class_audio_control_interface_number =  interface_descriptor.bInterfaceNumber;
            }
            else
            {

                descriptor_found =  UX_FALSE;
            }
            break;
                

        case UX_HOST_CLASS_AUDIO_CS_INTERFACE:

            /* First make sure we have found the correct generic interface descriptor.  */
            if (descriptor_found == UX_TRUE)
            {

                /* Check the sub type.  */
                switch (descriptor_subtype)
                {


                case UX_HOST_CLASS_AUDIO_CS_INPUT_TERMINAL:
                                        
                    /* Make the descriptor machine independent.  */
                    _ux_utility_descriptor_parse(descriptor, _ux_system_class_audio_input_terminal_descriptor_structure,
                                            UX_HOST_CLASS_AUDIO_INPUT_TERMINAL_DESCRIPTOR_ENTRIES, (UCHAR *) &input_interface_descriptor);
                                                        
                    /* Make sure we have the right terminal link.  */
                    if (input_interface_descriptor.bTerminalID == audio -> ux_host_class_audio_terminal_link)
                    {

                        audio -> ux_host_class_audio_type =  UX_HOST_CLASS_AUDIO_OUTPUT;

                        /* Return successful completion.  */
                        return(UX_SUCCESS);
                    }

                    break;

                case UX_HOST_CLASS_AUDIO_CS_OUTPUT_TERMINAL:

                    /* Make the descriptor machine independent.  */
                    _ux_utility_descriptor_parse(descriptor, _ux_system_class_audio_output_terminal_descriptor_structure,
                                            UX_HOST_CLASS_AUDIO_OUTPUT_TERMINAL_DESCRIPTOR_ENTRIES, (UCHAR *) &output_interface_descriptor);
                                                        
                    /* Make sure we have the right terminal link.  */
                    if (output_interface_descriptor.bTerminalID == audio -> ux_host_class_audio_terminal_link)
                    {

                        audio -> ux_host_class_audio_type =  UX_HOST_CLASS_AUDIO_INPUT;

                        /* Return successful completion.  */
                        return(UX_SUCCESS);
                    }
                }
            }
            break;
        }       

        /* Verify if the descriptor is still valid.  */
        if (descriptor_length > total_descriptor_length)
        {

            /* Error trap. */
            _ux_system_error_handler(UX_SYSTEM_LEVEL_THREAD, UX_SYSTEM_CONTEXT_CLASS, UX_DESCRIPTOR_CORRUPTED);

            /* If trace is enabled, insert this event into the trace buffer.  */
            UX_TRACE_IN_LINE_INSERT(UX_TRACE_ERROR, UX_DESCRIPTOR_CORRUPTED, descriptor, 0, 0, UX_TRACE_ERRORS, 0, 0)

            return(UX_DESCRIPTOR_CORRUPTED);
        }            

        /* Jump to the next descriptor if we have not reached the end.  */
        descriptor +=  descriptor_length;

        /* And adjust the length left to parse in the descriptor.  */
        total_descriptor_length -=  descriptor_length;
    }

    /* Error trap. */
    _ux_system_error_handler(UX_SYSTEM_LEVEL_THREAD, UX_SYSTEM_CONTEXT_CLASS, UX_HOST_CLASS_AUDIO_WRONG_TYPE);

    /* We get here when either the report descriptor has a problem or we could
       not find the right audio device.  */
    return(UX_HOST_CLASS_AUDIO_WRONG_TYPE);
}

