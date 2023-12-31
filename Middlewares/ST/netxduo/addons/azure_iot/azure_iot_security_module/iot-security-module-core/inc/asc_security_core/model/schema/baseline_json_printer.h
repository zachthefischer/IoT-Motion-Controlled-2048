#ifndef BASELINE_JSON_PRINTER_H
#define BASELINE_JSON_PRINTER_H

/* Generated by flatcc 0.6.1-dev FlatBuffers schema compiler for C by dvide.com */

#include "flatcc/flatcc_json_printer.h"
#include "flatcc/flatcc_prologue.h"

static void AzureIoTSecurity_BaselineCheck_print_json_table(flatcc_json_printer_t *ctx, flatcc_json_printer_table_descriptor_t *td);
static void AzureIoTSecurity_Baseline_print_json_table(flatcc_json_printer_t *ctx, flatcc_json_printer_table_descriptor_t *td);

static void AzureIoTSecurity_Result_print_json_enum(flatcc_json_printer_t *ctx, int8_t v)
{

    switch (v) {
    case 0: flatcc_json_printer_enum(ctx, "PASS", 4); break;
    case 1: flatcc_json_printer_enum(ctx, "FAIL", 4); break;
    case 2: flatcc_json_printer_enum(ctx, "ERROR", 5); break;
    default: flatcc_json_printer_int8(ctx, v); break;
    }
}

static void AzureIoTSecurity_Severity_print_json_enum(flatcc_json_printer_t *ctx, int8_t v)
{

    switch (v) {
    case 0: flatcc_json_printer_enum(ctx, "CRITICAL", 8); break;
    case 1: flatcc_json_printer_enum(ctx, "IMPORTANT", 9); break;
    case 2: flatcc_json_printer_enum(ctx, "WARNING", 7); break;
    case 3: flatcc_json_printer_enum(ctx, "INFORMATIONAL", 13); break;
    default: flatcc_json_printer_int8(ctx, v); break;
    }
}

static void AzureIoTSecurity_BaselineCheck_print_json_table(flatcc_json_printer_t *ctx, flatcc_json_printer_table_descriptor_t *td)
{
    flatcc_json_printer_string_field(ctx, td, 0, "id", 2);
    flatcc_json_printer_int8_enum_field(ctx, td, 1, "result", 6, 0, AzureIoTSecurity_Result_print_json_enum);
    flatcc_json_printer_string_field(ctx, td, 2, "error", 5);
    flatcc_json_printer_string_field(ctx, td, 3, "description", 11);
    flatcc_json_printer_int8_enum_field(ctx, td, 4, "severity", 8, 0, AzureIoTSecurity_Severity_print_json_enum);
    flatcc_json_printer_string_field(ctx, td, 5, "remediation", 11);
}

static inline int AzureIoTSecurity_BaselineCheck_print_json_as_root(flatcc_json_printer_t *ctx, const void *buf, size_t bufsiz, const char *fid)
{
    return flatcc_json_printer_table_as_root(ctx, buf, bufsiz, fid, AzureIoTSecurity_BaselineCheck_print_json_table);
}

static void AzureIoTSecurity_Baseline_print_json_table(flatcc_json_printer_t *ctx, flatcc_json_printer_table_descriptor_t *td)
{
    flatcc_json_printer_table_vector_field(ctx, td, 0, "baseline_checks", 15, AzureIoTSecurity_BaselineCheck_print_json_table);
}

static inline int AzureIoTSecurity_Baseline_print_json_as_root(flatcc_json_printer_t *ctx, const void *buf, size_t bufsiz, const char *fid)
{
    return flatcc_json_printer_table_as_root(ctx, buf, bufsiz, fid, AzureIoTSecurity_Baseline_print_json_table);
}

#include "flatcc/flatcc_epilogue.h"
#endif /* BASELINE_JSON_PRINTER_H */
