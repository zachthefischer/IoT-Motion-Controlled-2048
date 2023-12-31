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
/**                                                                       */
/** USBX Component                                                        */
/**                                                                       */
/**   Device Audio Class                                                  */
/**                                                                       */
/**************************************************************************/
/**************************************************************************/

#define UX_SOURCE_CODE


/* Include necessary system files.  */

#include "ux_api.h"
#include "ux_device_class_audio.h"
#include "ux_device_stack.h"


/**************************************************************************/
/*                                                                        */
/*  FUNCTION                                               RELEASE        */
/*                                                                        */
/*    _ux_device_class_audio_activate                     PORTABLE C      */
/*                                                           6.1          */
/*  AUTHOR                                                                */
/*                                                                        */
/*    Chaoqiong Xiao, Microsoft Corporation                               */
/*                                                                        */
/*  DESCRIPTION                                                           */
/*                                                                        */
/*    This function initializes the USB Audio device.                     */
/*                                                                        */
/*  INPUT                                                                 */
/*                                                                        */
/*    command                               Pointer to audio command      */
/*                                                                        */
/*  OUTPUT                                                                */
/*                                                                        */
/*    Completion Status                                                   */
/*                                                                        */
/*  CALLS                                                                 */
/*                                                                        */
/*    _ux_system_error_handler              System error trap             */
/*                                                                        */
/*  CALLED BY                                                             */
/*                                                                        */
/*    Device Audio Class                                                  */
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
UINT  _ux_device_class_audio_activate(UX_SLAVE_CLASS_COMMAND *command)
{

UX_SLAVE_DEVICE                         *device;
UX_SLAVE_INTERFACE                      *interface;
UX_SLAVE_INTERFACE                      *control_interface;
UX_SLAVE_INTERFACE                      *stream_interface;
UX_DEVICE_CLASS_AUDIO                   *audio;
UX_DEVICE_CLASS_AUDIO_STREAM            *stream;
UX_SLAVE_CLASS                          *class;
ULONG                                    stream_index;


    /* Get the class container.  */
    class =  command -> ux_slave_class_command_class_ptr;

    /* Get the class instance in the container.  */
    audio = (UX_DEVICE_CLASS_AUDIO *) class -> ux_slave_class_instance;

    /* Get the interface that owns this instance.  */
    interface =  (UX_SLAVE_INTERFACE  *) command -> ux_slave_class_command_interface;

    /* Get the device instance.  */
    device = &_ux_system_slave -> ux_system_slave_device;
    audio -> ux_device_class_audio_device = device;

    /* We only support audio interface here.  */
    if (interface -> ux_slave_interface_descriptor.bInterfaceClass != UX_DEVICE_CLASS_AUDIO_CLASS)
        return(UX_NO_CLASS_MATCH);

    /* It's control interface?  */
    if (interface -> ux_slave_interface_descriptor.bInterfaceSubClass == UX_DEVICE_CLASS_AUDIO_SUBCLASS_CONTROL)
    {

        /* Store the interface in the class instance.  */
        audio -> ux_device_class_audio_interface = interface;

        /* Store the class instance into the interface.  */
        interface -> ux_slave_interface_class_instance = (VOID *)audio;
    }
    else
    {

        /* It's streaming interface.  */
        stream_interface = interface;

        /* Separate driver for each interface (IAD not used)?  */
        if (audio -> ux_device_class_audio_interface == UX_NULL)
        {

            /* Always use just 1 stream for 1 interface.  */
            stream_index = 0;
        }

        /* Re-use the same driver (IAD used)?  */
        else
        {

            /* Re-use saved control interface.  */
            control_interface = audio -> ux_device_class_audio_interface;

            /* Calculate stream index.  */
            stream_index  = stream_interface -> ux_slave_interface_descriptor.bInterfaceNumber;
            stream_index -= control_interface -> ux_slave_interface_descriptor.bInterfaceNumber;
            stream_index --;

        }

        /* Sanity check.  */
        if (stream_index >= audio -> ux_device_class_audio_streams_nb)
        {

            /* Error trap!  */
            _ux_system_error_handler(UX_SYSTEM_LEVEL_THREAD, UX_SYSTEM_CONTEXT_CLASS, UX_MEMORY_INSUFFICIENT);
            return(UX_MEMORY_INSUFFICIENT);
        }

        /* Locate stream based on interface number.  */
        stream = &audio -> ux_device_class_audio_streams[stream_index];

        /* Store the interface for the stream.  */
        stream -> ux_device_class_audio_stream_interface = stream_interface;

        /* Store the class instance into the interface.  */
        stream_interface -> ux_slave_interface_class_instance = (VOID *)audio;
    }

    /* If there is a activate function call it.  */
    if (audio -> ux_device_class_audio_callbacks.ux_slave_class_audio_instance_activate != UX_NULL)
    {

        /* Invoke the application.  */
        audio -> ux_device_class_audio_callbacks.ux_slave_class_audio_instance_activate(audio);
    }

    /* Return completion status.  */
    return(UX_SUCCESS);
}

