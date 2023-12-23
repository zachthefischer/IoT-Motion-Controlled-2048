/*
 * Copyright (c) 2018-2021, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __PSA_SERVICE_H__
#define __PSA_SERVICE_H__

#include <stddef.h>
#include <stdint.h>

#include "psa/error.h"
#include "psa/client.h"

#ifdef __cplusplus
extern "C" {
#endif

/********************** PSA Secure Partition Macros and Types ****************/

/**
 * A timeout value that requests a polling wait operation.
 */
#define PSA_POLL                (0x00000000u)

/**
 * A timeout value that requests a blocking wait operation.
 */
#define PSA_BLOCK               (0x80000000u)

/**
 * A mask value that includes all Secure Partition signals.
 */
#define PSA_WAIT_ANY            (0xFFFFFFFFu)

/**
 * The signal number for the Secure Partition doorbell.
 */
#define PSA_DOORBELL            (0x00000008u)

/* PSA message types */
/* An IPC message type that indicates a new connection. */
#define PSA_IPC_CONNECT         (-1)
/* An IPC message type that indicates the end of a connection. */
#define PSA_IPC_DISCONNECT      (-2)

/* Store a set of one or more Secure Partition signals */
typedef uint32_t psa_signal_t;

/* A type used to temporarily store a previous interrupt state. */
typedef uint32_t psa_irq_status_t;

/**
 * Describe a message received by an RoT Service after calling \ref psa_get().
 */
typedef struct psa_msg_t {
    int32_t type;              /* One of the following values:
                                 * \ref PSA_IPC_CONNECT
                                 * >= 0
                                 * \ref PSA_IPC_DISCONNECT
                                 */
    psa_handle_t handle;        /* A reference generated by the SPM to the
                                 * message returned by psa_get().
                                 */
    int32_t client_id;          /* Partition ID of the sender of the message */
    void *rhandle;              /* Be useful for binding a connection to some
                                 * application-specific data or function
                                 * pointer within the RoT Service
                                 * implementation.
                                 */
    size_t in_size[PSA_MAX_IOVEC]; /* Provide the size of each client input
                                    * vector in bytes.
                                    */
    size_t out_size[PSA_MAX_IOVEC];/* Provide the size of each client output
                                    * vector in bytes.
                                    */
} psa_msg_t;

/************************* PSA Secure Partition API **************************/

/**
 * \brief Return the Secure Partition interrupt signals that have been asserted
 *        from a subset of signals provided by the caller.
 *
 * \param[in] signal_mask       A set of signals to query. Signals that are not
 *                              in this set will be ignored.
 * \param[in] timeout           Specify either blocking \ref PSA_BLOCK or
 *                              polling \ref PSA_POLL operation.
 *
 * \retval >0                   At least one signal is asserted.
 * \retval 0                    No signals are asserted. This is only seen when
 *                              a polling timeout is used.
 */
psa_signal_t psa_wait(psa_signal_t signal_mask, uint32_t timeout);

/**
 * \brief Retrieve the message which corresponds to a given RoT Service signal
 *        and remove the message from the RoT Service queue.
 *
 * \param[in] signal            The signal value for an asserted RoT Service.
 * \param[out] msg              Pointer to \ref psa_msg_t object for receiving
 *                              the message.
 *
 * \retval PSA_SUCCESS          Success, *msg will contain the delivered
 *                              message.
 * \retval PSA_ERROR_DOES_NOT_EXIST Message could not be delivered.
 * \retval "PROGRAMMER ERROR"   The call is invalid because one or more of the
 *                              following are true:
 * \arg                           signal has more than a single bit set.
 * \arg                           signal does not correspond to an RoT Service.
 * \arg                           The RoT Service signal is not currently
 *                                asserted.
 * \arg                           The msg pointer provided is not a valid memory
 *                                reference.
 */
psa_status_t psa_get(psa_signal_t signal, psa_msg_t *msg);

/**
 * \brief Associate some RoT Service private data with a client connection.
 *
 * \param[in] msg_handle        Handle for the client's message.
 * \param[in] rhandle           Reverse handle allocated by the RoT Service.
 *
 * \retval void                 Success, rhandle will be provided with all
 *                              subsequent messages delivered on this
 *                              connection.
 * \retval "PROGRAMMER ERROR"   msg_handle is invalid.
 */
void psa_set_rhandle(psa_handle_t msg_handle, void *rhandle);

/**
 * \brief Read a message parameter or part of a message parameter from a client
 *        input vector.
 *
 * \param[in] msg_handle        Handle for the client's message.
 * \param[in] invec_idx         Index of the input vector to read from. Must be
 *                              less than \ref PSA_MAX_IOVEC.
 * \param[out] buffer           Buffer in the Secure Partition to copy the
 *                              requested data to.
 * \param[in] num_bytes         Maximum number of bytes to be read from the
 *                              client input vector.
 *
 * \retval >0                   Number of bytes copied.
 * \retval 0                    There was no remaining data in this input
 *                              vector.
 * \retval "PROGRAMMER ERROR"   The call is invalid, one or more of the
 *                              following are true:
 * \arg                           msg_handle is invalid.
 * \arg                           msg_handle does not refer to a
 *                                \ref PSA_IPC_CALL message.
 * \arg                           invec_idx is equal to or greater than
 *                                \ref PSA_MAX_IOVEC.
 * \arg                           the memory reference for buffer is invalid or
 *                                not writable.
 */
size_t psa_read(psa_handle_t msg_handle, uint32_t invec_idx,
                void *buffer, size_t num_bytes);

/**
 * \brief Skip over part of a client input vector.
 *
 * \param[in] msg_handle        Handle for the client's message.
 * \param[in] invec_idx         Index of input vector to skip from. Must be
 *                              less than \ref PSA_MAX_IOVEC.
 * \param[in] num_bytes         Maximum number of bytes to skip in the client
 *                              input vector.
 *
 * \retval >0                   Number of bytes skipped.
 * \retval 0                    There was no remaining data in this input
 *                              vector.
 * \retval "PROGRAMMER ERROR"   The call is invalid, one or more of the
 *                              following are true:
 * \arg                           msg_handle is invalid.
 * \arg                           msg_handle does not refer to a request
 *                                message.
 * \arg                           invec_idx is equal to or greater than
 *                                \ref PSA_MAX_IOVEC.
 */
size_t psa_skip(psa_handle_t msg_handle, uint32_t invec_idx, size_t num_bytes);

/**
 * \brief Write a message response to a client output vector.
 *
 * \param[in] msg_handle        Handle for the client's message.
 * \param[out] outvec_idx       Index of output vector in message to write to.
 *                              Must be less than \ref PSA_MAX_IOVEC.
 * \param[in] buffer            Buffer with the data to write.
 * \param[in] num_bytes         Number of bytes to write to the client output
 *                              vector.
 *
 * \retval void                 Success
 * \retval "PROGRAMMER ERROR"   The call is invalid, one or more of the
 *                              following are true:
 * \arg                           msg_handle is invalid.
 * \arg                           msg_handle does not refer to a request
 *                                message.
 * \arg                           outvec_idx is equal to or greater than
 *                                \ref PSA_MAX_IOVEC.
 * \arg                           The memory reference for buffer is invalid.
 * \arg                           The call attempts to write data past the end
 *                                of the client output vector.
 */
void psa_write(psa_handle_t msg_handle, uint32_t outvec_idx,
               const void *buffer, size_t num_bytes);

/**
 * \brief Complete handling of a specific message and unblock the client.
 *
 * \param[in] msg_handle        Handle for the client's message.
 * \param[in] status            Message result value to be reported to the
 *                              client.
 *
 * \retval void                 Success.
 * \retval "PROGRAMMER ERROR"   The call is invalid, one or more of the
 *                              following are true:
 * \arg                         msg_handle is invalid.
 * \arg                         An invalid status code is specified for the
 *                              type of message.
 */
void psa_reply(psa_handle_t msg_handle, psa_status_t status);

/**
 * \brief Send a PSA_DOORBELL signal to a specific Secure Partition.
 *
 * \param[in] partition_id      Secure Partition ID of the target partition.
 *
 * \retval void                 Success.
 * \retval "PROGRAMMER ERROR"   partition_id does not correspond to a Secure
 *                              Partition.
 */
void psa_notify(int32_t partition_id);

/**
 * \brief Clear the PSA_DOORBELL signal.
 *
 * \retval void                 Success.
 * \retval "PROGRAMMER ERROR"   The Secure Partition's doorbell signal is not
 *                              currently asserted.
 */
void psa_clear(void);

/**
 * \brief Inform the SPM that an interrupt has been handled (end of interrupt).
 *
 * \param[in] irq_signal        The interrupt signal that has been processed.
 *
 * \retval void                 Success.
 * \retval "PROGRAMMER ERROR"   The call is invalid, one or more of the
 *                              following are true:
 * \arg                           irq_signal is not an interrupt signal.
 * \arg                           irq_signal indicates more than one signal.
 * \arg                           irq_signal is not currently asserted.
 */
void psa_eoi(psa_signal_t irq_signal);

/**
 * \brief Terminate execution within the calling Secure Partition and will not
 *        return.
 *
 * \retval "Does not return"
 */
void psa_panic(void);

/**
 * \brief Enable an interrupt.
 *
 * \param[in] irq_signal The signal for the interrupt to be enabled.
 *                       This must have a single bit set, which must be the
 *                       signal value for an interrupt in the calling Secure
 *                       Partition.
 *
 * \retval void
 * \retval "PROGRAMMER ERROR" If one or more of the following are true:
 *                            \ref irq_signal is not an interrupt signal.
 *                            \ref irq_signal indicates more than one signal.
 */
void psa_irq_enable(psa_signal_t irq_signal);

/**
 * \brief Disable an interrupt and return the status of the interrupt prior to
 *        being disabled by this call.
 *
 * \param[in] irq_signal The signal for the interrupt to be disabled.
 *                       This must have a single bit set, which must be the
 *                       signal value for an interrupt in the calling Secure
 *                       Partition.
 *
 * \retval 0                  The interrupt was disabled prior to this call.
 *         1                  The interrupt was enabled prior to this call.
 * \retval "PROGRAMMER ERROR" If one or more of the following are true:
 *                            \ref irq_signal is not an interrupt signal.
 *                            \ref irq_signal indicates more than one signal.
 *
 * \note The current implementation always return 1. Do not use the return.
 */
psa_irq_status_t psa_irq_disable(psa_signal_t irq_signal);

#ifdef __cplusplus
}
#endif

#endif /* __PSA_SERVICE_H__ */
