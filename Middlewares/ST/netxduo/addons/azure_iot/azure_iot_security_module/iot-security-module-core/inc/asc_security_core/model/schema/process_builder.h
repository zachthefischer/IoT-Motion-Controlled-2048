#ifndef PROCESS_BUILDER_H
#define PROCESS_BUILDER_H

/* Generated by flatcc 0.6.1-dev FlatBuffers schema compiler for C by dvide.com */

#ifndef PROCESS_READER_H
#include "process_reader.h"
#endif
#ifndef FLATBUFFERS_COMMON_BUILDER_H
#include "flatbuffers_common_builder.h"
#endif
#ifndef PROCESS_EVENT_TYPE_BUILDER_H
#include "process_event_type_builder.h"
#endif
#include "flatcc/flatcc_prologue.h"
#ifndef flatbuffers_identifier
#define flatbuffers_identifier 0
#endif
#ifndef flatbuffers_extension
#define flatbuffers_extension ".bin"
#endif

static const flatbuffers_voffset_t __AzureIoTSecurity_Process_required[] = { 0 };
typedef flatbuffers_ref_t AzureIoTSecurity_Process_ref_t;
static AzureIoTSecurity_Process_ref_t AzureIoTSecurity_Process_clone(flatbuffers_builder_t *B, AzureIoTSecurity_Process_table_t t);
__flatbuffers_build_table(flatbuffers_, AzureIoTSecurity_Process, 8)

#define __AzureIoTSecurity_Process_formal_args ,\
  flatbuffers_string_ref_t v0, uint32_t v1, uint32_t v2, uint32_t v3,\
  flatbuffers_string_ref_t v4, flatbuffers_string_ref_t v5, AzureIoTSecurity_ProcessEventType_enum_t v6, uint32_t v7
#define __AzureIoTSecurity_Process_call_args ,\
  v0, v1, v2, v3,\
  v4, v5, v6, v7
static inline AzureIoTSecurity_Process_ref_t AzureIoTSecurity_Process_create(flatbuffers_builder_t *B __AzureIoTSecurity_Process_formal_args);
__flatbuffers_build_table_prolog(flatbuffers_, AzureIoTSecurity_Process, AzureIoTSecurity_Process_file_identifier, AzureIoTSecurity_Process_type_identifier)

__flatbuffers_build_string_field(0, flatbuffers_, AzureIoTSecurity_Process_executable, AzureIoTSecurity_Process)
__flatbuffers_build_scalar_field(1, flatbuffers_, AzureIoTSecurity_Process_process_id, flatbuffers_uint32, uint32_t, 4, 4, UINT32_C(0), AzureIoTSecurity_Process)
__flatbuffers_build_scalar_field(2, flatbuffers_, AzureIoTSecurity_Process_parent_process_id, flatbuffers_uint32, uint32_t, 4, 4, UINT32_C(0), AzureIoTSecurity_Process)
__flatbuffers_build_scalar_field(3, flatbuffers_, AzureIoTSecurity_Process_user_id, flatbuffers_uint32, uint32_t, 4, 4, UINT32_C(0), AzureIoTSecurity_Process)
__flatbuffers_build_string_field(4, flatbuffers_, AzureIoTSecurity_Process_user_name, AzureIoTSecurity_Process)
__flatbuffers_build_string_field(5, flatbuffers_, AzureIoTSecurity_Process_commandline, AzureIoTSecurity_Process)
__flatbuffers_build_scalar_field(6, flatbuffers_, AzureIoTSecurity_Process_event_type, AzureIoTSecurity_ProcessEventType, AzureIoTSecurity_ProcessEventType_enum_t, 1, 1, INT8_C(0), AzureIoTSecurity_Process)
__flatbuffers_build_scalar_field(7, flatbuffers_, AzureIoTSecurity_Process_hit_count, flatbuffers_uint32, uint32_t, 4, 4, UINT32_C(1), AzureIoTSecurity_Process)

static inline AzureIoTSecurity_Process_ref_t AzureIoTSecurity_Process_create(flatbuffers_builder_t *B __AzureIoTSecurity_Process_formal_args)
{
    if (AzureIoTSecurity_Process_start(B)
        || AzureIoTSecurity_Process_executable_add(B, v0)
        || AzureIoTSecurity_Process_process_id_add(B, v1)
        || AzureIoTSecurity_Process_parent_process_id_add(B, v2)
        || AzureIoTSecurity_Process_user_id_add(B, v3)
        || AzureIoTSecurity_Process_user_name_add(B, v4)
        || AzureIoTSecurity_Process_commandline_add(B, v5)
        || AzureIoTSecurity_Process_hit_count_add(B, v7)
        || AzureIoTSecurity_Process_event_type_add(B, v6)) {
        return 0;
    }
    return AzureIoTSecurity_Process_end(B);
}

static AzureIoTSecurity_Process_ref_t AzureIoTSecurity_Process_clone(flatbuffers_builder_t *B, AzureIoTSecurity_Process_table_t t)
{
    __flatbuffers_memoize_begin(B, t);
    if (AzureIoTSecurity_Process_start(B)
        || AzureIoTSecurity_Process_executable_pick(B, t)
        || AzureIoTSecurity_Process_process_id_pick(B, t)
        || AzureIoTSecurity_Process_parent_process_id_pick(B, t)
        || AzureIoTSecurity_Process_user_id_pick(B, t)
        || AzureIoTSecurity_Process_user_name_pick(B, t)
        || AzureIoTSecurity_Process_commandline_pick(B, t)
        || AzureIoTSecurity_Process_hit_count_pick(B, t)
        || AzureIoTSecurity_Process_event_type_pick(B, t)) {
        return 0;
    }
    __flatbuffers_memoize_end(B, t, AzureIoTSecurity_Process_end(B));
}

#include "flatcc/flatcc_epilogue.h"
#endif /* PROCESS_BUILDER_H */
