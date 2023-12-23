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
#include "ux_host_stack.h"
#include "ux_hcd_ohci.h"


/**************************************************************************/ 
/*                                                                        */ 
/*  FUNCTION                                               RELEASE        */ 
/*                                                                        */ 
/*    _ux_hcd_ohci_asynchronous_endpoint_destroy          PORTABLE C      */ 
/*                                                           6.1          */
/*  AUTHOR                                                                */
/*                                                                        */
/*    Chaoqiong Xiao, Microsoft Corporation                               */
/*                                                                        */
/*  DESCRIPTION                                                           */
/*                                                                        */ 
/*     This function will destroy an asynchronous endpoint. The control   */ 
/*     and bulk endpoints fall into this category.                        */ 
/*                                                                        */ 
/*  INPUT                                                                 */ 
/*                                                                        */ 
/*    hcd_ohci                              Pointer to OHCI HCD           */ 
/*    endpoint                              Pointer to endpoint           */ 
/*                                                                        */ 
/*  OUTPUT                                                                */ 
/*                                                                        */ 
/*    Completion Status                                                   */ 
/*                                                                        */ 
/*  CALLS                                                                 */ 
/*                                                                        */ 
/*    _ux_hcd_ohci_register_read            Read OHCI register            */ 
/*    _ux_hcd_ohci_register_write           Write OHCI register           */ 
/*    _ux_utility_virtual_address           Get virtual address           */ 
/*    _ux_utility_delay_ms                  Delay ms                      */ 
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
/*                                            fixed physical and virtual  */
/*                                            address conversion,         */
/*                                            resulting in version 6.1    */
/*                                                                        */
/**************************************************************************/
UINT  _ux_hcd_ohci_asynchronous_endpoint_destroy(UX_HCD_OHCI *hcd_ohci, UX_ENDPOINT *endpoint)
{

UX_OHCI_ED      *ed;
UX_OHCI_ED      *previous_ed;
UX_OHCI_ED      *next_ed;
UX_OHCI_TD      *tail_td;
UX_OHCI_TD      *head_td;
ULONG           value_td;
ULONG           ohci_register;
    

    /* From the endpoint container fetch the OHCI ED descriptor.  */
    ed =  (UX_OHCI_ED*) endpoint -> ux_endpoint_ed;

    /* Check if this physical endpoint has been initialized properly!  */
    if (ed == UX_NULL)
    {
    
        /* Error trap. */
        _ux_system_error_handler(UX_SYSTEM_LEVEL_THREAD, UX_SYSTEM_CONTEXT_HCD, UX_ENDPOINT_HANDLE_UNKNOWN);

        /* If trace is enabled, insert this event into the trace buffer.  */
        UX_TRACE_IN_LINE_INSERT(UX_TRACE_ERROR, UX_ENDPOINT_HANDLE_UNKNOWN, endpoint, 0, 0, UX_TRACE_ERRORS, 0, 0)

        return(UX_ENDPOINT_HANDLE_UNKNOWN);
    }

    /* The endpoint may be active. If so, set the skip bit.  */
    ed -> ux_ohci_ed_dw0 |=  UX_OHCI_ED_SKIP;
    
    /* Wait for the controller to finish the current frame processing.  */
    _ux_utility_delay_ms(1);

    /* Get the previous ED in the list for this ED.  */
    previous_ed =  ed -> ux_ohci_ed_previous_ed;

    /* Get the next ED in the list for this ED.  */
    next_ed =  ed -> ux_ohci_ed_next_ed;

    /* If the previous ED is NULL, we are at trying to remove the head ED.  */
    if (previous_ed == UX_NULL)
    {

        switch ((endpoint -> ux_endpoint_descriptor.bmAttributes) & UX_MASK_ENDPOINT_TYPE)
        {

        case UX_CONTROL_ENDPOINT:

            /* Check if the next control endpoint is NULL.  */
            if (next_ed == UX_NULL)
            {

                ohci_register =   _ux_hcd_ohci_register_read(hcd_ohci, OHCI_HC_CONTROL);
                ohci_register &=  ~OHCI_HC_CR_CLE;
                _ux_hcd_ohci_register_write(hcd_ohci, OHCI_HC_CONTROL, ohci_register);
            }
            
            /* Store the new endpoint in the Control list.  */
            _ux_hcd_ohci_register_write(hcd_ohci, OHCI_HC_CONTROL_HEAD_ED, (ULONG) next_ed);
            break;


        case UX_BULK_ENDPOINT:

            /* Check if the next bulk endpoint is NULL.  */
            if (next_ed == UX_NULL)
            {

                ohci_register =   _ux_hcd_ohci_register_read(hcd_ohci, OHCI_HC_CONTROL);
                ohci_register &=  ~OHCI_HC_CR_BLE;
                _ux_hcd_ohci_register_write(hcd_ohci, OHCI_HC_CONTROL, ohci_register);
            }
            
            /* Store the new endpoint in the Bulk list */
            _ux_hcd_ohci_register_write(hcd_ohci, OHCI_HC_BULK_HEAD_ED, (ULONG) next_ed);
            break;
        }
    }
    else
    {

        /* The previous ED points now to the ED after the ED we are removing.  */
        previous_ed -> ux_ohci_ed_next_ed =  next_ed;
    }

    /* Update the previous ED pointer in the next ED if exists.  */
    if (next_ed != UX_NULL)
        next_ed -> ux_ohci_ed_previous_ed =  previous_ed;

    /* Ensure that the potential Halt bit is removed in the head ED.  */
    value_td =  (ULONG) _ux_utility_virtual_address(ed -> ux_ohci_ed_head_td) & UX_OHCI_ED_MASK_TD;
    head_td =   (UX_OHCI_TD *) value_td;

    /* Remove all the tds from this ED and leave the head and tail pointing
       to the dummy TD.  */
    tail_td =  _ux_utility_virtual_address(ed -> ux_ohci_ed_tail_td);

    /* Free all tds attached to the ED */
    while (head_td != tail_td)
    {

        /* Update the head TD with the next TD.  */
        ed -> ux_ohci_ed_head_td =  head_td -> ux_ohci_td_next_td;

        /* Mark the current head TD as free.  */
        head_td -> ux_ohci_td_status =  UX_UNUSED;

        /* Now the new head TD is the next TD in the chain.  */
        head_td =  _ux_utility_virtual_address(ed -> ux_ohci_ed_head_td);
    }

    /* We need to free the dummy TD that was attached to the ED.  */
    tail_td -> ux_ohci_td_status =  UX_UNUSED;


    /* Now we can safely make the ED free.  */
    ed -> ux_ohci_ed_status =  UX_UNUSED;

    /* Return successful completion.  */
    return(UX_SUCCESS);         
}

