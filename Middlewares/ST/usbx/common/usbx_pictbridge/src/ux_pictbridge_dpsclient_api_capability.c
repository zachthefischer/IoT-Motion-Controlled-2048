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
/**   Pictbridge Application                                              */
/**                                                                       */
/**************************************************************************/
/**************************************************************************/


/* Include necessary system files.  */

#define UX_SOURCE_CODE

#include "ux_api.h"
#include "ux_pictbridge.h"
#include "ux_device_class_pima.h"


/**************************************************************************/ 
/*                                                                        */ 
/*  FUNCTION                                               RELEASE        */ 
/*                                                                        */ 
/*    _ux_pictbridge_dpsclient_api_capability             PORTABLE C      */ 
/*                                                           6.1          */
/*  AUTHOR                                                                */
/*                                                                        */
/*    Chaoqiong Xiao, Microsoft Corporation                               */
/*                                                                        */
/*  DESCRIPTION                                                           */
/*                                                                        */ 
/*    This function creates the tag lines of the configure_print_service  */ 
/*    request and then output the request to the printer.                 */ 
/*                                                                        */ 
/*  INPUT                                                                 */ 
/*                                                                        */ 
/*    pictbridge                            Pictbridge instance           */ 
/*    capability_code                       What capability to get        */ 
/*    capability_parameter                  Optional parameter            */ 
/*                                                                        */ 
/*  OUTPUT                                                                */ 
/*                                                                        */ 
/*    Completion Status                                                   */ 
/*                                                                        */ 
/*  CALLS                                                                 */ 
/*                                                                        */ 
/*    _ux_utility_delay_ms                  Delay ms                      */ 
/*    _ux_pictbridge_dps_client_input_object_prepare                      */
/*    _ux_utility_event_flags_get                                         */
/*                                                                        */ 
/*  CALLED BY                                                             */ 
/*                                                                        */ 
/*    _ux_pictbridge_dpshost_object_get                                   */ 
/*                                                                        */ 
/*  RELEASE HISTORY                                                       */ 
/*                                                                        */ 
/*    DATE              NAME                      DESCRIPTION             */ 
/*                                                                        */ 
/*  05-19-2020     Chaoqiong Xiao           Initial Version 6.0           */
/*  09-30-2020     Chaoqiong Xiao           Modified comment(s),          */
/*                                            used UX prefix to refer to  */
/*                                            TX symbols instead of using */
/*                                            them directly,              */
/*                                            resulting in version 6.1    */
/*                                                                        */
/**************************************************************************/
UINT _ux_pictbridge_dpsclient_api_capability(UX_PICTBRIDGE *pictbridge, ULONG capability_code, 
                                             ULONG capability_parameter) 
{
UINT                                status;
ULONG                               actual_flags;

    /* Wait for 100 ms to give a chance to the host to send a request before the client can post a Object Added event.  */
    _ux_utility_delay_ms(100);

    /* Prepare the object for capability. */
    status = _ux_pictbridge_dpsclient_input_object_prepare(pictbridge, UX_PICTBRIDGE_OR_GET_CAPABILITY, 
                                                            capability_code, capability_parameter);
    
    /* Check status.  */
    if (status != UX_SUCCESS)
        return(status);

    /* We should wait for the host to send a script with the response.  */
    status =  _ux_utility_event_flags_get(&pictbridge -> ux_pictbridge_event_flags_group, UX_PICTBRIDGE_EVENT_FLAG_CAPABILITY, 
                                        UX_AND_CLEAR, &actual_flags, UX_PICTBRIDGE_EVENT_TIMEOUT);

    /* Check status.  */
    if (status != UX_SUCCESS)
        return(UX_EVENT_ERROR);

    /* Ensure the flag was set.  */
    if (actual_flags & UX_PICTBRIDGE_EVENT_FLAG_CAPABILITY)
        
        /* Return completion status.  */
        return(UX_SUCCESS);    

    else
            
        /* Return completion status.  */
        return(UX_ERROR);    
}

