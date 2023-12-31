#ifndef UUID_JSON_PARSER_H
#define UUID_JSON_PARSER_H

/* Generated by flatcc 0.6.1-dev FlatBuffers schema compiler for C by dvide.com */

#include "flatcc/flatcc_json_parser.h"
#include "flatcc/flatcc_prologue.h"

static const char *AzureIoTSecurity_UUID_parse_json_struct_inline(flatcc_json_parser_t *ctx, const char *buf, const char *end, void *struct_base);
static const char *AzureIoTSecurity_UUID_parse_json_struct(flatcc_json_parser_t *ctx, const char *buf, const char *end, flatcc_builder_ref_t *result);
static const char *uuid_local_json_parser_enum(flatcc_json_parser_t *ctx, const char *buf, const char *end,
int *value_type, uint64_t *value, int *aggregate);
static const char *uuid_local_AzureIoTSecurity_json_parser_enum(flatcc_json_parser_t *ctx, const char *buf, const char *end,
int *value_type, uint64_t *value, int *aggregate);
static const char *uuid_global_json_parser_enum(flatcc_json_parser_t *ctx, const char *buf, const char *end,
        int *value_type, uint64_t *value, int *aggregate);

static const char *AzureIoTSecurity_UUID_parse_json_struct_inline(flatcc_json_parser_t *ctx, const char *buf, const char *end, void *struct_base)
{
    int more;
    flatcc_builder_ref_t ref;
    void *pval;
    const char *mark;
    uint64_t w;

    buf = flatcc_json_parser_object_start(ctx, buf, end, &more);
    while (more) {
        buf = flatcc_json_parser_symbol_start(ctx, buf, end);
        w = flatcc_json_parser_symbol_part(buf, end);
        if ((w & 0xffffffffff000000) == 0x76616c7565000000) { /* "value" */
            buf = flatcc_json_parser_match_symbol(ctx, (mark = buf), end, 5);
            if (mark != buf) {
                size_t count = 16;
                uint8_t *base = (uint8_t *)((size_t)struct_base + 0);
                buf = flatcc_json_parser_array_start(ctx, buf, end, &more);
                while (more) {
                    uint8_t val = 0;
                    static flatcc_json_parser_integral_symbol_f *symbolic_parsers[] = {
                            uuid_local_AzureIoTSecurity_json_parser_enum,
                            uuid_global_json_parser_enum, 0 };
                    buf = flatcc_json_parser_uint8(ctx, (mark = buf), end, &val);
                    if (mark == buf) {
                        buf = flatcc_json_parser_symbolic_uint8(ctx, (mark = buf), end, symbolic_parsers, &val);
                        if (buf == mark || buf == end) goto failed;
                    }
                    if (count) {
                        flatbuffers_uint8_write_to_pe(base, val);
                        --count;
                        ++base;
                    } else if (!(ctx->flags & flatcc_json_parser_f_skip_array_overflow)) {
                        return flatcc_json_parser_set_error(ctx, buf, end, flatcc_json_parser_error_array_overflow);
                    }
                    buf = flatcc_json_parser_array_end(ctx, buf, end, &more);
                }
                if (count) {
                    if (ctx->flags & flatcc_json_parser_f_reject_array_underflow) {
                        return flatcc_json_parser_set_error(ctx, buf, end, flatcc_json_parser_error_array_underflow);
                    }
                    memset(base, 0, count * sizeof(*base));
                }
            } else {
                buf = flatcc_json_parser_unmatched_symbol(ctx, buf, end);
            }
        } else { /* "value" */
            buf = flatcc_json_parser_unmatched_symbol(ctx, buf, end);
        } /* "value" */
        buf = flatcc_json_parser_object_end(ctx, buf, end , &more);
    }
    return buf;
failed:
    return flatcc_json_parser_set_error(ctx, buf, end, flatcc_json_parser_error_runtime);
}

static const char *AzureIoTSecurity_UUID_parse_json_struct(flatcc_json_parser_t *ctx, const char *buf, const char *end, flatcc_builder_ref_t *result)
{
    void *pval;

    *result = 0;
    if (!(pval = flatcc_builder_start_struct(ctx->ctx, 16, 1))) goto failed;
    buf = AzureIoTSecurity_UUID_parse_json_struct_inline(ctx, buf, end, pval);
    if (buf == end || !(*result = flatcc_builder_end_struct(ctx->ctx))) goto failed;
    return buf;
failed:
    return flatcc_json_parser_set_error(ctx, buf, end, flatcc_json_parser_error_runtime);
}

static inline int AzureIoTSecurity_UUID_parse_json_as_root(flatcc_builder_t *B, flatcc_json_parser_t *ctx, const char *buf, size_t bufsiz, int flags, const char *fid)
{
    return flatcc_json_parser_struct_as_root(B, ctx, buf, bufsiz, flags, fid, AzureIoTSecurity_UUID_parse_json_struct);
}

static const char *uuid_local_json_parser_enum(flatcc_json_parser_t *ctx, const char *buf, const char *end,
        int *value_type, uint64_t *value, int *aggregate)
{
    /* Scope has no enum / union types to look up. */
    return buf; /* unmatched; */
}

static const char *uuid_local_AzureIoTSecurity_json_parser_enum(flatcc_json_parser_t *ctx, const char *buf, const char *end,
        int *value_type, uint64_t *value, int *aggregate)
{
    /* Scope has no enum / union types to look up. */
    return buf; /* unmatched; */
}

static const char *uuid_global_json_parser_enum(flatcc_json_parser_t *ctx, const char *buf, const char *end,
        int *value_type, uint64_t *value, int *aggregate)
{
    /* Global scope has no enum / union types to look up. */
    return buf; /* unmatched; */
}

#include "flatcc/flatcc_epilogue.h"
#endif /* UUID_JSON_PARSER_H */
