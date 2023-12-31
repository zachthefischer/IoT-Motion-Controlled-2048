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
/**   OHCI Controller Driver                                              */
/**                                                                       */
/**************************************************************************/
/**************************************************************************/


/* Include necessary system files.  */

#define UX_SOURCE_CODE

#include "ux_api.h"
#include "ux_hcd_ohci.h"
#include "ux_host_stack.h"


/**************************************************************************/ 
/*                                                                        */ 
/*  FUNCTION                                               RELEASE        */ 
/*                                                                        */ 
/*    _ux_hcd_ohci_port_reset                             PORTABLE C      */ 
/*                                                           6.1          */
/*  AUTHOR                                                                */
/*                                                                        */
/*    Chaoqiong Xiao, Microsoft Corporation                               */
/*                                                                        */
/*  DESCRIPTION                                                           */
/*                                                                        */ 
/*     This function will reset a specific port attached to the root HUB. */ 
/*                                                                        */ 
/*  INPUT                                                                 */ 
/*                                                                        */ 
/*    hcd_ohci                              Pointer to OHCI controller    */ 
/*    port_index                            Port index                    */ 
/*                                                                        */ 
/*  OUTPUT                                                                */ 
/*                                                                        */ 
/*    Completion Status                                                   */ 
/*                                                                        */ 
/*  CALLS                                                                 */ 
/*                                                                        */ 
/*    _ux_hcd_ohci_register_read            OHCI register read            */ 
/*    _ux_hcd_ohci_register_write           OHCI register write           */ 
/*    _ux_utility_delay_ms                  Delay                         */ 
/*                                                                        */ 
/*  CALLED BY                                                             */ 
/*                                                                        */ 
/*    OHCI Controller Driver                                              */ 
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
UINT  _ux_hcd_ohci_port_reset(UX_HCD_OHCI *hcd_ohci, ULONG port_index)
{

ULONG       ohci_register_port_status;
UINT        index_loop;


    /* Check to see if this port is valid on this controller.  */
    if (hcd_ohci -> ux_hcd_ohci_nb_root_hubs < port_index)
    {

        /* Error trap. */
        _ux_system_error_handler(UX_SYSTEM_LEVEL_THREAD, UX_SYSTEM_CONTEXT_HCD, UX_PORT_INDEX_UNKNOWN);

        /* If trace is enabled, insert this event into the trace buffer.  */
        UX_TRACE_IN_LINE_INSERT(UX_TRACE_ERROR, UX_PORT_INDEX_UNKNOWN, port_index, 0, 0, UX_TRACE_ERRORS, 0, 0)

        return(UX_PORT_INDEX_UNKNOWN);
    }
    
    /* Ensure that the downstream port has a device attached. It is unnatural
       to perform a port reset if there is no device.  */
    ohci_register_port_status =  _ux_hcd_ohci_register_read(hcd_ohci, OHCI_HC_RH_PORT_STATUS + port_index);
                                    
    /* Check Device Connection Status.  */
    if ((ohci_register_port_status & OHCI_HC_PS_CCS) == 0)
    {
    
        /* Error trap. */
        _ux_system_error_handler(UX_SYSTEM_LEVEL_THREAD, UX_SYSTEM_CONTEXT_HCD, UX_NO_DEVICE_CONNECTED);

        /* If trace is enabled, insert this event into the trace buffer.  */
        UX_TRACE_IN_LINE_INSERT(UX_TRACE_ERROR, UX_NO_DEVICE_CONNECTED, port_index, 0, 0, UX_TRACE_ERRORS, 0, 0)

        return(UX_NO_DEVICE_CONNECTED);
    }
    
    /* Now we can safely issue a RESET command to this port.  */
    _ux_hcd_ohci_register_write(hcd_ohci, OHCI_HC_RH_PORT_STATUS + port_index, OHCI_HC_PS_PRS);

    /* Normally, a port reset lasts for around 10ms. When the reset is completed
       the controller will set the PRSC bit. We need to invert this bit by rewriting 
       a 1 to the PRSC field.  */
    for (index_loop = 0; index_loop < UX_OHCI_PORT_RESET_RETRY; index_loop++)
    {

        /* Perform the necessary delay to let the port reset properly.  */
        _ux_utility_delay_ms(UX_OHCI_PORT_RESET_DELAY);
        
        /* Read the root HUB status change register.  */
        ohci_register_port_status =  _ux_hcd_ohci_register_read(hcd_ohci, OHCI_HC_RH_PORT_STATUS + port_index);

        /* Reset completed? */
        if (ohci_register_port_status & OHCI_HC_PS_PRSC)
        {

            /* The reset phase is complete, rewrite that bit to clear it and
               return to the root HUB driver.  */
            _ux_hcd_ohci_register_write(hcd_ohci, OHCI_HC_RH_PORT_STATUS + port_index, OHCI_HC_PS_PRSC);

            /* Return successful completion.  */
            return(UX_SUCCESS);
        }
    }

    /* If trace is enabled, insert this event into the trace buffer.  */
    UX_TRACE_IN_LINE_INSERT(UX_TRACE_ERROR, UX_PORT_RESET_FAILED, port_index, 0, 0, UX_TRACE_ERRORS, 0, 0)

    /* The reset failed! Inform the root HUB driver. This should not really happen in a 1.x controller.  */
    return(UX_PORT_RESET_FAILED);       
}

