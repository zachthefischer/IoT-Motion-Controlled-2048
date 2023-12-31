#ifndef LISTENING_PORTS_READER_H
#define LISTENING_PORTS_READER_H

/* Generated by flatcc 0.6.1-dev FlatBuffers schema compiler for C by dvide.com */

#ifndef FLATBUFFERS_COMMON_READER_H
#include "flatbuffers_common_reader.h"
#endif
#ifndef PROTOCOL_READER_H
#include "protocol_reader.h"
#endif
#include "flatcc/flatcc_flatbuffers.h"
#ifndef __alignas_is_defined
#include <stdalign.h>
#endif
#include "flatcc/flatcc_prologue.h"
#ifndef flatbuffers_identifier
#define flatbuffers_identifier 0
#endif
#ifndef flatbuffers_extension
#define flatbuffers_extension ".bin"
#endif

typedef struct AzureIoTSecurity_ListeningPortsCommon AzureIoTSecurity_ListeningPortsCommon_t;
typedef const AzureIoTSecurity_ListeningPortsCommon_t *AzureIoTSecurity_ListeningPortsCommon_struct_t;
typedef AzureIoTSecurity_ListeningPortsCommon_t *AzureIoTSecurity_ListeningPortsCommon_mutable_struct_t;
typedef const AzureIoTSecurity_ListeningPortsCommon_t *AzureIoTSecurity_ListeningPortsCommon_vec_t;
typedef AzureIoTSecurity_ListeningPortsCommon_t *AzureIoTSecurity_ListeningPortsCommon_mutable_vec_t;
typedef struct AzureIoTSecurity_ListeningPortsV4 AzureIoTSecurity_ListeningPortsV4_t;
typedef const AzureIoTSecurity_ListeningPortsV4_t *AzureIoTSecurity_ListeningPortsV4_struct_t;
typedef AzureIoTSecurity_ListeningPortsV4_t *AzureIoTSecurity_ListeningPortsV4_mutable_struct_t;
typedef const AzureIoTSecurity_ListeningPortsV4_t *AzureIoTSecurity_ListeningPortsV4_vec_t;
typedef AzureIoTSecurity_ListeningPortsV4_t *AzureIoTSecurity_ListeningPortsV4_mutable_vec_t;
typedef struct AzureIoTSecurity_ListeningPortsV6 AzureIoTSecurity_ListeningPortsV6_t;
typedef const AzureIoTSecurity_ListeningPortsV6_t *AzureIoTSecurity_ListeningPortsV6_struct_t;
typedef AzureIoTSecurity_ListeningPortsV6_t *AzureIoTSecurity_ListeningPortsV6_mutable_struct_t;
typedef const AzureIoTSecurity_ListeningPortsV6_t *AzureIoTSecurity_ListeningPortsV6_vec_t;
typedef AzureIoTSecurity_ListeningPortsV6_t *AzureIoTSecurity_ListeningPortsV6_mutable_vec_t;

typedef const struct AzureIoTSecurity_ListeningPorts_table *AzureIoTSecurity_ListeningPorts_table_t;
typedef struct AzureIoTSecurity_ListeningPorts_table *AzureIoTSecurity_ListeningPorts_mutable_table_t;
typedef const flatbuffers_uoffset_t *AzureIoTSecurity_ListeningPorts_vec_t;
typedef flatbuffers_uoffset_t *AzureIoTSecurity_ListeningPorts_mutable_vec_t;
#ifndef AzureIoTSecurity_ListeningPortsCommon_file_identifier
#define AzureIoTSecurity_ListeningPortsCommon_file_identifier flatbuffers_identifier
#endif
/* deprecated, use AzureIoTSecurity_ListeningPortsCommon_file_identifier */
#ifndef AzureIoTSecurity_ListeningPortsCommon_identifier
#define AzureIoTSecurity_ListeningPortsCommon_identifier flatbuffers_identifier
#endif
#define AzureIoTSecurity_ListeningPortsCommon_type_hash ((flatbuffers_thash_t)0x44925c2e)
#define AzureIoTSecurity_ListeningPortsCommon_type_identifier "\x2e\x5c\x92\x44"
#ifndef AzureIoTSecurity_ListeningPortsV4_file_identifier
#define AzureIoTSecurity_ListeningPortsV4_file_identifier flatbuffers_identifier
#endif
/* deprecated, use AzureIoTSecurity_ListeningPortsV4_file_identifier */
#ifndef AzureIoTSecurity_ListeningPortsV4_identifier
#define AzureIoTSecurity_ListeningPortsV4_identifier flatbuffers_identifier
#endif
#define AzureIoTSecurity_ListeningPortsV4_type_hash ((flatbuffers_thash_t)0x64e0c505)
#define AzureIoTSecurity_ListeningPortsV4_type_identifier "\x05\xc5\xe0\x64"
#ifndef AzureIoTSecurity_ListeningPortsV6_file_identifier
#define AzureIoTSecurity_ListeningPortsV6_file_identifier flatbuffers_identifier
#endif
/* deprecated, use AzureIoTSecurity_ListeningPortsV6_file_identifier */
#ifndef AzureIoTSecurity_ListeningPortsV6_identifier
#define AzureIoTSecurity_ListeningPortsV6_identifier flatbuffers_identifier
#endif
#define AzureIoTSecurity_ListeningPortsV6_type_hash ((flatbuffers_thash_t)0x62e0c1df)
#define AzureIoTSecurity_ListeningPortsV6_type_identifier "\xdf\xc1\xe0\x62"
#ifndef AzureIoTSecurity_ListeningPorts_file_identifier
#define AzureIoTSecurity_ListeningPorts_file_identifier flatbuffers_identifier
#endif
/* deprecated, use AzureIoTSecurity_ListeningPorts_file_identifier */
#ifndef AzureIoTSecurity_ListeningPorts_identifier
#define AzureIoTSecurity_ListeningPorts_identifier flatbuffers_identifier
#endif
#define AzureIoTSecurity_ListeningPorts_type_hash ((flatbuffers_thash_t)0xe92154b7)
#define AzureIoTSecurity_ListeningPorts_type_identifier "\xb7\x54\x21\xe9"


struct AzureIoTSecurity_ListeningPortsCommon {
    /**  Local Port */
    alignas(2) uint16_t local_port;
    /**  Protocol (TCP/UDP) */
    alignas(1) AzureIoTSecurity_Protocol_enum_t protocol;
};
static_assert(sizeof(AzureIoTSecurity_ListeningPortsCommon_t) == 4, "struct size mismatch");

static inline const AzureIoTSecurity_ListeningPortsCommon_t *AzureIoTSecurity_ListeningPortsCommon__const_ptr_add(const AzureIoTSecurity_ListeningPortsCommon_t *p, size_t i) { return p + i; }
static inline AzureIoTSecurity_ListeningPortsCommon_t *AzureIoTSecurity_ListeningPortsCommon__ptr_add(AzureIoTSecurity_ListeningPortsCommon_t *p, size_t i) { return p + i; }
static inline AzureIoTSecurity_ListeningPortsCommon_struct_t AzureIoTSecurity_ListeningPortsCommon_vec_at(AzureIoTSecurity_ListeningPortsCommon_vec_t vec, size_t i)
__flatbuffers_struct_vec_at(vec, i)
static inline size_t AzureIoTSecurity_ListeningPortsCommon__size(void) { return 4; }
static inline size_t AzureIoTSecurity_ListeningPortsCommon_vec_len(AzureIoTSecurity_ListeningPortsCommon_vec_t vec)
__flatbuffers_vec_len(vec)
__flatbuffers_struct_as_root(AzureIoTSecurity_ListeningPortsCommon)

__flatbuffers_define_struct_scalar_field(AzureIoTSecurity_ListeningPortsCommon, local_port, flatbuffers_uint16, uint16_t)
__flatbuffers_define_struct_scalar_field(AzureIoTSecurity_ListeningPortsCommon, protocol, AzureIoTSecurity_Protocol, AzureIoTSecurity_Protocol_enum_t)

struct AzureIoTSecurity_ListeningPortsV4 {
    /**  Local IPv4 Address */
    alignas(4) uint32_t local_address;
    alignas(2) AzureIoTSecurity_ListeningPortsCommon_t common;
};
static_assert(sizeof(AzureIoTSecurity_ListeningPortsV4_t) == 8, "struct size mismatch");

static inline const AzureIoTSecurity_ListeningPortsV4_t *AzureIoTSecurity_ListeningPortsV4__const_ptr_add(const AzureIoTSecurity_ListeningPortsV4_t *p, size_t i) { return p + i; }
static inline AzureIoTSecurity_ListeningPortsV4_t *AzureIoTSecurity_ListeningPortsV4__ptr_add(AzureIoTSecurity_ListeningPortsV4_t *p, size_t i) { return p + i; }
static inline AzureIoTSecurity_ListeningPortsV4_struct_t AzureIoTSecurity_ListeningPortsV4_vec_at(AzureIoTSecurity_ListeningPortsV4_vec_t vec, size_t i)
__flatbuffers_struct_vec_at(vec, i)
static inline size_t AzureIoTSecurity_ListeningPortsV4__size(void) { return 8; }
static inline size_t AzureIoTSecurity_ListeningPortsV4_vec_len(AzureIoTSecurity_ListeningPortsV4_vec_t vec)
__flatbuffers_vec_len(vec)
__flatbuffers_struct_as_root(AzureIoTSecurity_ListeningPortsV4)

__flatbuffers_define_struct_scalar_field(AzureIoTSecurity_ListeningPortsV4, local_address, flatbuffers_uint32, uint32_t)
__flatbuffers_define_struct_struct_field(AzureIoTSecurity_ListeningPortsV4, common, AzureIoTSecurity_ListeningPortsCommon_struct_t)

struct AzureIoTSecurity_ListeningPortsV6 {
    /**  Local IPv6 Address */
    alignas(4) uint32_t local_address[4];
    alignas(2) AzureIoTSecurity_ListeningPortsCommon_t common;
};
static_assert(sizeof(AzureIoTSecurity_ListeningPortsV6_t) == 20, "struct size mismatch");

static inline const AzureIoTSecurity_ListeningPortsV6_t *AzureIoTSecurity_ListeningPortsV6__const_ptr_add(const AzureIoTSecurity_ListeningPortsV6_t *p, size_t i) { return p + i; }
static inline AzureIoTSecurity_ListeningPortsV6_t *AzureIoTSecurity_ListeningPortsV6__ptr_add(AzureIoTSecurity_ListeningPortsV6_t *p, size_t i) { return p + i; }
static inline AzureIoTSecurity_ListeningPortsV6_struct_t AzureIoTSecurity_ListeningPortsV6_vec_at(AzureIoTSecurity_ListeningPortsV6_vec_t vec, size_t i)
__flatbuffers_struct_vec_at(vec, i)
static inline size_t AzureIoTSecurity_ListeningPortsV6__size(void) { return 20; }
static inline size_t AzureIoTSecurity_ListeningPortsV6_vec_len(AzureIoTSecurity_ListeningPortsV6_vec_t vec)
__flatbuffers_vec_len(vec)
__flatbuffers_struct_as_root(AzureIoTSecurity_ListeningPortsV6)

__flatbuffers_define_struct_scalar_fixed_array_field(AzureIoTSecurity_ListeningPortsV6, local_address, flatbuffers_uint32, uint32_t, 4)
__flatbuffers_define_struct_struct_field(AzureIoTSecurity_ListeningPortsV6, common, AzureIoTSecurity_ListeningPortsCommon_struct_t)


struct AzureIoTSecurity_ListeningPorts_table { uint8_t unused__; };

static inline size_t AzureIoTSecurity_ListeningPorts_vec_len(AzureIoTSecurity_ListeningPorts_vec_t vec)
__flatbuffers_vec_len(vec)
static inline AzureIoTSecurity_ListeningPorts_table_t AzureIoTSecurity_ListeningPorts_vec_at(AzureIoTSecurity_ListeningPorts_vec_t vec, size_t i)
__flatbuffers_offset_vec_at(AzureIoTSecurity_ListeningPorts_table_t, vec, i, 0)
__flatbuffers_table_as_root(AzureIoTSecurity_ListeningPorts)

__flatbuffers_define_vector_field(0, AzureIoTSecurity_ListeningPorts, ipv4_ports, AzureIoTSecurity_ListeningPortsV4_vec_t, 0)
__flatbuffers_define_vector_field(1, AzureIoTSecurity_ListeningPorts, ipv6_ports, AzureIoTSecurity_ListeningPortsV6_vec_t, 0)


#include "flatcc/flatcc_epilogue.h"
#endif /* LISTENING_PORTS_READER_H */
