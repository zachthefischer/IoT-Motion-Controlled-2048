#ifndef PAYLOAD_JSON_PARSER_H
#define PAYLOAD_JSON_PARSER_H

/* Generated by flatcc 0.6.1-dev FlatBuffers schema compiler for C by dvide.com */

#include "flatcc/flatcc_json_parser.h"
#ifndef LOG_JSON_PARSER_H
#include "log_json_parser.h"
#endif
#ifndef PROCESS_JSON_PARSER_H
#include "process_json_parser.h"
#endif
#ifndef BASELINE_JSON_PARSER_H
#include "baseline_json_parser.h"
#endif
#ifndef HEARTBEAT_JSON_PARSER_H
#include "heartbeat_json_parser.h"
#endif
#ifndef LISTENING_PORTS_JSON_PARSER_H
#include "listening_ports_json_parser.h"
#endif
#ifndef SYSTEM_INFORMATION_JSON_PARSER_H
#include "system_information_json_parser.h"
#endif
#ifndef NETWORK_ACTIVITY_JSON_PARSER_H
#include "network_activity_json_parser.h"
#endif
#include "flatcc/flatcc_prologue.h"

static const char *AzureIoTSecurity_Payload_parse_json_union(flatcc_json_parser_t *ctx, const char *buf, const char *end, uint8_t type, flatcc_builder_ref_t *pref);
static int AzureIoTSecurity_Payload_json_union_accept_type(uint8_t type);
static const char *AzureIoTSecurity_Payload_parse_json_enum(flatcc_json_parser_t *ctx, const char *buf, const char *end,
        int *value_type, uint64_t *value, int *aggregate);
static const char *payload_local_json_parser_enum(flatcc_json_parser_t *ctx, const char *buf, const char *end,
int *value_type, uint64_t *value, int *aggregate);
static const char *payload_local_AzureIoTSecurity_json_parser_enum(flatcc_json_parser_t *ctx, const char *buf, const char *end,
int *value_type, uint64_t *value, int *aggregate);
static const char *payload_global_json_parser_enum(flatcc_json_parser_t *ctx, const char *buf, const char *end,
        int *value_type, uint64_t *value, int *aggregate);

static const char *AzureIoTSecurity_Payload_parse_json_union(flatcc_json_parser_t *ctx, const char *buf, const char *end, uint8_t type, flatcc_builder_ref_t *result)
{

    *result = 0;
    switch (type) {
    case 0: /* NONE */
        return flatcc_json_parser_none(ctx, buf, end);
    case 1: /* NetworkActivity */
        buf = AzureIoTSecurity_NetworkActivity_parse_json_table(ctx, buf, end, result);
        break;
    case 2: /* SystemInformation */
        buf = AzureIoTSecurity_SystemInformation_parse_json_table(ctx, buf, end, result);
        break;
    case 3: /* ListeningPorts */
        buf = AzureIoTSecurity_ListeningPorts_parse_json_table(ctx, buf, end, result);
        break;
    case 4: /* Heartbeat */
        buf = AzureIoTSecurity_Heartbeat_parse_json_table(ctx, buf, end, result);
        break;
    case 5: /* Baseline */
        buf = AzureIoTSecurity_Baseline_parse_json_table(ctx, buf, end, result);
        break;
    case 6: /* Process */
        buf = AzureIoTSecurity_Process_parse_json_table(ctx, buf, end, result);
        break;
    case 7: /* Log */
        buf = AzureIoTSecurity_Log_parse_json_table(ctx, buf, end, result);
        break;
    default:
        if (!(ctx->flags & flatcc_json_parser_f_skip_unknown)) {
            return flatcc_json_parser_set_error(ctx, buf, end, flatcc_json_parser_error_unknown_union);
        } else {
            return flatcc_json_parser_generic_json(ctx, buf, end);
        }
    }
    if (ctx->error) return buf;
    if (!*result) {
        return flatcc_json_parser_set_error(ctx, buf, end, flatcc_json_parser_error_runtime);
    }
    return buf;
}

static int AzureIoTSecurity_Payload_json_union_accept_type(uint8_t type)
{
    switch (type) {
    case 0: return 1; /* NONE */
    case 1: return 1; /* NetworkActivity */
    case 2: return 1; /* SystemInformation */
    case 3: return 1; /* ListeningPorts */
    case 4: return 1; /* Heartbeat */
    case 5: return 1; /* Baseline */
    case 6: return 1; /* Process */
    case 7: return 1; /* Log */
    default: return 0;
    }
}

static const char *AzureIoTSecurity_Payload_parse_json_enum(flatcc_json_parser_t *ctx, const char *buf, const char *end,
        int *value_sign, uint64_t *value, int *aggregate)
{
    const char *unmatched = buf;
    const char *mark;
    uint64_t w;

    w = flatcc_json_parser_symbol_part(buf, end);
    if (w < 0x4c6f670000000000) { /* branch "Log" */
        if (w < 0x4865617274626561) { /* branch "Heartbea" */
            if (w == 0x426173656c696e65) { /* "Baseline" */
                buf = flatcc_json_parser_match_constant(ctx, (mark = buf), end, 8, aggregate);
                if (buf != mark) {
                    *value = UINT64_C(5), *value_sign = 0;
                } else {
                    return unmatched;
                }
            } else { /* "Baseline" */
                return unmatched;
            } /* "Baseline" */
        } else { /* branch "Heartbea" */
            if (w == 0x4865617274626561) { /* descend "Heartbea" */
                buf += 8;
                w = flatcc_json_parser_symbol_part(buf, end);
                if ((w & 0xff00000000000000) == 0x7400000000000000) { /* "t" */
                    buf = flatcc_json_parser_match_constant(ctx, (mark = buf), end, 1, aggregate);
                    if (buf != mark) {
                        *value = UINT64_C(4), *value_sign = 0;
                    } else {
                        return unmatched;
                    }
                } else { /* "t" */
                    return unmatched;
                } /* "t" */
            } else { /* descend "Heartbea" */
                if (w == 0x4c697374656e696e) { /* descend "Listenin" */
                    buf += 8;
                    w = flatcc_json_parser_symbol_part(buf, end);
                    if ((w & 0xffffffffffff0000) == 0x67506f7274730000) { /* "gPorts" */
                        buf = flatcc_json_parser_match_constant(ctx, (mark = buf), end, 6, aggregate);
                        if (buf != mark) {
                            *value = UINT64_C(3), *value_sign = 0;
                        } else {
                            return unmatched;
                        }
                    } else { /* "gPorts" */
                        return unmatched;
                    } /* "gPorts" */
                } else { /* descend "Listenin" */
                    return unmatched;
                } /* descend "Listenin" */
            } /* descend "Heartbea" */
        } /* branch "Heartbea" */
    } else { /* branch "Log" */
        if (w < 0x4e6574776f726b41) { /* branch "NetworkA" */
            if ((w & 0xffffffff00000000) == 0x4e4f4e4500000000) { /* "NONE" */
                buf = flatcc_json_parser_match_constant(ctx, (mark = buf), end, 4, aggregate);
                if (buf != mark) {
                    *value = UINT64_C(0), *value_sign = 0;
                } else {
                    return unmatched;
                }
            } else { /* "NONE" */
                if ((w & 0xffffff0000000000) == 0x4c6f670000000000) { /* "Log" */
                    buf = flatcc_json_parser_match_constant(ctx, (mark = buf), end, 3, aggregate);
                    if (buf != mark) {
                        *value = UINT64_C(7), *value_sign = 0;
                    } else {
                        return unmatched;
                    }
                } else { /* "Log" */
                    return unmatched;
                } /* "Log" */
            } /* "NONE" */
        } else { /* branch "NetworkA" */
            if (w < 0x50726f6365737300) { /* branch "Process" */
                if (w == 0x4e6574776f726b41) { /* descend "NetworkA" */
                    buf += 8;
                    w = flatcc_json_parser_symbol_part(buf, end);
                    if ((w & 0xffffffffffffff00) == 0x6374697669747900) { /* "ctivity" */
                        buf = flatcc_json_parser_match_constant(ctx, (mark = buf), end, 7, aggregate);
                        if (buf != mark) {
                            *value = UINT64_C(1), *value_sign = 0;
                        } else {
                            return unmatched;
                        }
                    } else { /* "ctivity" */
                        return unmatched;
                    } /* "ctivity" */
                } else { /* descend "NetworkA" */
                    return unmatched;
                } /* descend "NetworkA" */
            } else { /* branch "Process" */
                if ((w & 0xffffffffffffff00) == 0x50726f6365737300) { /* "Process" */
                    buf = flatcc_json_parser_match_constant(ctx, (mark = buf), end, 7, aggregate);
                    if (buf != mark) {
                        *value = UINT64_C(6), *value_sign = 0;
                    } else {
                        goto pfguard1;
                    }
                } else { /* "Process" */
                    goto pfguard1;
                } /* "Process" */
                goto endpfguard1;
pfguard1:
                if (w == 0x53797374656d496e) { /* descend "SystemIn" */
                    buf += 8;
                    w = flatcc_json_parser_symbol_part(buf, end);
                    if (w == 0x666f726d6174696f) { /* descend "formatio" */
                        buf += 8;
                        w = flatcc_json_parser_symbol_part(buf, end);
                        if ((w & 0xff00000000000000) == 0x6e00000000000000) { /* "n" */
                            buf = flatcc_json_parser_match_constant(ctx, (mark = buf), end, 1, aggregate);
                            if (buf != mark) {
                                *value = UINT64_C(2), *value_sign = 0;
                            } else {
                                return unmatched;
                            }
                        } else { /* "n" */
                            return unmatched;
                        } /* "n" */
                    } else { /* descend "formatio" */
                        return unmatched;
                    } /* descend "formatio" */
                } else { /* descend "SystemIn" */
                    return unmatched;
                } /* descend "SystemIn" */
endpfguard1:
                (void)0;
            } /* branch "Process" */
        } /* branch "NetworkA" */
    } /* branch "Log" */
    return buf;
}

static const char *payload_local_json_parser_enum(flatcc_json_parser_t *ctx, const char *buf, const char *end,
        int *value_type, uint64_t *value, int *aggregate)
{
    /* Scope has no enum / union types to look up. */
    return buf; /* unmatched; */
}

static const char *payload_local_AzureIoTSecurity_json_parser_enum(flatcc_json_parser_t *ctx, const char *buf, const char *end,
        int *value_type, uint64_t *value, int *aggregate)
{
    const char *unmatched = buf;
    const char *mark;
    uint64_t w;

    w = flatcc_json_parser_symbol_part(buf, end);
    if (w < 0x50726f6365737345) { /* branch "ProcessE" */
        if ((w & 0xffffffffffffff00) == 0x5061796c6f616400) { /* "Payload" */
            buf = flatcc_json_parser_match_scope(ctx, (mark = buf), end, 7);
            if (buf != mark) {
                buf = AzureIoTSecurity_Payload_parse_json_enum(ctx, buf, end, value_type, value, aggregate);
            } else {
                return unmatched;
            }
        } else { /* "Payload" */
            if ((w & 0xffffffffff000000) == 0x4c6576656c000000) { /* "Level" */
                buf = flatcc_json_parser_match_scope(ctx, (mark = buf), end, 5);
                if (buf != mark) {
                    buf = AzureIoTSecurity_Level_parse_json_enum(ctx, buf, end, value_type, value, aggregate);
                } else {
                    return unmatched;
                }
            } else { /* "Level" */
                return unmatched;
            } /* "Level" */
        } /* "Payload" */
    } else { /* branch "ProcessE" */
        if (w < 0x50726f746f636f6c) { /* branch "Protocol" */
            if (w == 0x50726f6365737345) { /* descend "ProcessE" */
                buf += 8;
                w = flatcc_json_parser_symbol_part(buf, end);
                if (w == 0x76656e7454797065) { /* "ventType" */
                    buf = flatcc_json_parser_match_scope(ctx, (mark = buf), end, 8);
                    if (buf != mark) {
                        buf = AzureIoTSecurity_ProcessEventType_parse_json_enum(ctx, buf, end, value_type, value, aggregate);
                    } else {
                        return unmatched;
                    }
                } else { /* "ventType" */
                    return unmatched;
                } /* "ventType" */
            } else { /* descend "ProcessE" */
                return unmatched;
            } /* descend "ProcessE" */
        } else { /* branch "Protocol" */
            if (w < 0x526573756c740000) { /* branch "Result" */
                if (w == 0x50726f746f636f6c) { /* "Protocol" */
                    buf = flatcc_json_parser_match_scope(ctx, (mark = buf), end, 8);
                    if (buf != mark) {
                        buf = AzureIoTSecurity_Protocol_parse_json_enum(ctx, buf, end, value_type, value, aggregate);
                    } else {
                        return unmatched;
                    }
                } else { /* "Protocol" */
                    return unmatched;
                } /* "Protocol" */
            } else { /* branch "Result" */
                if (w == 0x5365766572697479) { /* "Severity" */
                    buf = flatcc_json_parser_match_scope(ctx, (mark = buf), end, 8);
                    if (buf != mark) {
                        buf = AzureIoTSecurity_Severity_parse_json_enum(ctx, buf, end, value_type, value, aggregate);
                    } else {
                        return unmatched;
                    }
                } else { /* "Severity" */
                    if ((w & 0xffffffffffff0000) == 0x526573756c740000) { /* "Result" */
                        buf = flatcc_json_parser_match_scope(ctx, (mark = buf), end, 6);
                        if (buf != mark) {
                            buf = AzureIoTSecurity_Result_parse_json_enum(ctx, buf, end, value_type, value, aggregate);
                        } else {
                            return unmatched;
                        }
                    } else { /* "Result" */
                        return unmatched;
                    } /* "Result" */
                } /* "Severity" */
            } /* branch "Result" */
        } /* branch "Protocol" */
    } /* branch "ProcessE" */
    return buf;
}

static const char *payload_global_json_parser_enum(flatcc_json_parser_t *ctx, const char *buf, const char *end,
        int *value_type, uint64_t *value, int *aggregate)
{
    const char *unmatched = buf;
    const char *mark;
    uint64_t w;

    w = flatcc_json_parser_symbol_part(buf, end);
    if (w == 0x417a757265496f54) { /* descend "AzureIoT" */
        buf += 8;
        w = flatcc_json_parser_symbol_part(buf, end);
        if (w == 0x5365637572697479) { /* descend "Security" */
            buf += 8;
            w = flatcc_json_parser_symbol_part(buf, end);
            if (w < 0x2e50726f63657373) { /* branch ".Process" */
                if (w == 0x2e5061796c6f6164) { /* ".Payload" */
                    buf = flatcc_json_parser_match_scope(ctx, (mark = buf), end, 8);
                    if (buf != mark) {
                        buf = AzureIoTSecurity_Payload_parse_json_enum(ctx, buf, end, value_type, value, aggregate);
                    } else {
                        return unmatched;
                    }
                } else { /* ".Payload" */
                    if ((w & 0xffffffffffff0000) == 0x2e4c6576656c0000) { /* ".Level" */
                        buf = flatcc_json_parser_match_scope(ctx, (mark = buf), end, 6);
                        if (buf != mark) {
                            buf = AzureIoTSecurity_Level_parse_json_enum(ctx, buf, end, value_type, value, aggregate);
                        } else {
                            return unmatched;
                        }
                    } else { /* ".Level" */
                        return unmatched;
                    } /* ".Level" */
                } /* ".Payload" */
            } else { /* branch ".Process" */
                if (w < 0x2e50726f746f636f) { /* branch ".Protoco" */
                    if (w == 0x2e50726f63657373) { /* descend ".Process" */
                        buf += 8;
                        w = flatcc_json_parser_symbol_part(buf, end);
                        if (w == 0x4576656e74547970) { /* descend "EventTyp" */
                            buf += 8;
                            w = flatcc_json_parser_symbol_part(buf, end);
                            if ((w & 0xff00000000000000) == 0x6500000000000000) { /* "e" */
                                buf = flatcc_json_parser_match_scope(ctx, (mark = buf), end, 1);
                                if (buf != mark) {
                                    buf = AzureIoTSecurity_ProcessEventType_parse_json_enum(ctx, buf, end, value_type, value, aggregate);
                                } else {
                                    return unmatched;
                                }
                            } else { /* "e" */
                                return unmatched;
                            } /* "e" */
                        } else { /* descend "EventTyp" */
                            return unmatched;
                        } /* descend "EventTyp" */
                    } else { /* descend ".Process" */
                        return unmatched;
                    } /* descend ".Process" */
                } else { /* branch ".Protoco" */
                    if (w < 0x2e526573756c7400) { /* branch ".Result" */
                        if (w == 0x2e50726f746f636f) { /* descend ".Protoco" */
                            buf += 8;
                            w = flatcc_json_parser_symbol_part(buf, end);
                            if ((w & 0xff00000000000000) == 0x6c00000000000000) { /* "l" */
                                buf = flatcc_json_parser_match_scope(ctx, (mark = buf), end, 1);
                                if (buf != mark) {
                                    buf = AzureIoTSecurity_Protocol_parse_json_enum(ctx, buf, end, value_type, value, aggregate);
                                } else {
                                    return unmatched;
                                }
                            } else { /* "l" */
                                return unmatched;
                            } /* "l" */
                        } else { /* descend ".Protoco" */
                            return unmatched;
                        } /* descend ".Protoco" */
                    } else { /* branch ".Result" */
                        if ((w & 0xffffffffffffff00) == 0x2e526573756c7400) { /* ".Result" */
                            buf = flatcc_json_parser_match_scope(ctx, (mark = buf), end, 7);
                            if (buf != mark) {
                                buf = AzureIoTSecurity_Result_parse_json_enum(ctx, buf, end, value_type, value, aggregate);
                            } else {
                                goto pfguard1;
                            }
                        } else { /* ".Result" */
                            goto pfguard1;
                        } /* ".Result" */
                        goto endpfguard1;
pfguard1:
                        if (w == 0x2e53657665726974) { /* descend ".Severit" */
                            buf += 8;
                            w = flatcc_json_parser_symbol_part(buf, end);
                            if ((w & 0xff00000000000000) == 0x7900000000000000) { /* "y" */
                                buf = flatcc_json_parser_match_scope(ctx, (mark = buf), end, 1);
                                if (buf != mark) {
                                    buf = AzureIoTSecurity_Severity_parse_json_enum(ctx, buf, end, value_type, value, aggregate);
                                } else {
                                    return unmatched;
                                }
                            } else { /* "y" */
                                return unmatched;
                            } /* "y" */
                        } else { /* descend ".Severit" */
                            return unmatched;
                        } /* descend ".Severit" */
endpfguard1:
                        (void)0;
                    } /* branch ".Result" */
                } /* branch ".Protoco" */
            } /* branch ".Process" */
        } else { /* descend "Security" */
            return unmatched;
        } /* descend "Security" */
    } else { /* descend "AzureIoT" */
        return unmatched;
    } /* descend "AzureIoT" */
    return buf;
}

#include "flatcc/flatcc_epilogue.h"
#endif /* PAYLOAD_JSON_PARSER_H */
