#ifndef PROCESS_JSON_PRINTER_H
#define PROCESS_JSON_PRINTER_H

/* Generated by flatcc 0.6.1-dev FlatBuffers schema compiler for C by dvide.com */

#include "flatcc/flatcc_json_printer.h"
#ifndef PROCESS_EVENT_TYPE_JSON_PRINTER_H
#include "process_event_type_json_printer.h"
#endif
#include "flatcc/flatcc_prologue.h"

static void AzureIoTSecurity_Process_print_json_table(flatcc_json_printer_t *ctx, flatcc_json_printer_table_descriptor_t *td);

static void AzureIoTSecurity_Process_print_json_table(flatcc_json_printer_t *ctx, flatcc_json_printer_table_descriptor_t *td)
{
    flatcc_json_printer_string_field(ctx, td, 0, "executable", 10);
    flatcc_json_printer_uint32_field(ctx, td, 1, "process_id", 10, 0);
    flatcc_json_printer_uint32_field(ctx, td, 2, "parent_process_id", 17, 0);
    flatcc_json_printer_uint32_field(ctx, td, 3, "user_id", 7, 0);
    flatcc_json_printer_string_field(ctx, td, 4, "user_name", 9);
    flatcc_json_printer_string_field(ctx, td, 5, "commandline", 11);
    flatcc_json_printer_int8_enum_field(ctx, td, 6, "event_type", 10, 0, AzureIoTSecurity_ProcessEventType_print_json_enum);
    flatcc_json_printer_uint32_field(ctx, td, 7, "hit_count", 9, 1);
}

static inline int AzureIoTSecurity_Process_print_json_as_root(flatcc_json_printer_t *ctx, const void *buf, size_t bufsiz, const char *fid)
{
    return flatcc_json_printer_table_as_root(ctx, buf, bufsiz, fid, AzureIoTSecurity_Process_print_json_table);
}

#include "flatcc/flatcc_epilogue.h"
#endif /* PROCESS_JSON_PRINTER_H */
