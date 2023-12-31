/*
 * Copyright (c) 2019-2021, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <stdint.h>
#include "tfm_plat_defs.h"
#include "tfm_plat_crypto_keys.h"
#include "psa/crypto_types.h"
#include "psa/crypto_values.h"

#ifdef SYMMETRIC_INITIAL_ATTESTATION
/*
 * This file contains the hard coded version of the secret key for HMAC.
 *
 * A HMAC-SHA256 key is 32 bytes long.
 *
 * This key is used to sign the initial attestation token in COSE_Mac0.
 * The secret key is stored in raw format, without any encoding(ASN.1, COSE).
 *
 * #######  DO NOT USE THIS KEY IN PRODUCTION #######
 */

/* HMAC-SHA256 by default */
const psa_algorithm_t tfm_attest_hmac_sign_alg = PSA_ALG_HMAC(PSA_ALG_SHA_256);

/* Symmetric initial attestation key in raw format, without any encoding.
 * It is used in HMAC-SHA256.
 * It MUST be present on the device.
 */
TFM_LINK_SET_RO_IN_PARTITION_SECTION("TFM_SP_INITIAL_ATTESTATION", "PSA-ROT")
const uint8_t initial_attestation_hmac_sha256_key[] =
{
    0xA9, 0xB4, 0x54, 0xB2, 0x6D, 0x6F, 0x90, 0xA4,
    0xEA, 0x31, 0x19, 0x35, 0x64, 0xCB, 0xA9, 0x1F,
    0xEC, 0x6F, 0x9A, 0x00, 0x2A, 0x7D, 0xC0, 0x50,
    0x4B, 0x92, 0xA1, 0x93, 0x71, 0x34, 0x58, 0x5F
};

TFM_LINK_SET_RO_IN_PARTITION_SECTION("TFM_SP_INITIAL_ATTESTATION", "PSA-ROT")
const size_t initial_attestation_hmac_sha256_key_size =
        sizeof(initial_attestation_hmac_sha256_key);

TFM_LINK_SET_RO_IN_PARTITION_SECTION("TFM_SP_INITIAL_ATTESTATION", "PSA-ROT")
const char *initial_attestation_kid = "kid@trustedfirmware.example";
#else /* SYMMETRIC_INITIAL_ATTESTATION */
/*
 * This file contains the hard coded version of the ECDSA P-256 secret key in:
 * platform/ext/common/template/tfm_initial_attestation_key.pem
 *
 * As a P-256 key, the private key is 32 bytes long.
 *
 * This key is used to sign the initial attestation token.
 * The secret key is stored in raw format, without any encoding(ASN.1, COSE).
 *
 * #######  DO NOT USE THIS KEY IN PRODUCTION #######
 */

/* Type of the EC curve which the key belongs to, in PSA curve ID form */
TFM_LINK_SET_RO_IN_PARTITION_SECTION("TFM_SP_INITIAL_ATTESTATION", "PSA-ROT")
const psa_ecc_family_t initial_attestation_curve_type = PSA_ECC_CURVE_SECP256R1;

/* Initial attestation private key in raw format, without any encoding.
 * It belongs to the ECDSA P-256 curve.
 * It MUST be present on the device.
 */
TFM_LINK_SET_RO_IN_PARTITION_SECTION("TFM_SP_INITIAL_ATTESTATION", "PSA-ROT")
const uint8_t initial_attestation_private_key[] =
{
    0xA9, 0xB4, 0x54, 0xB2, 0x6D, 0x6F, 0x90, 0xA4,
    0xEA, 0x31, 0x19, 0x35, 0x64, 0xCB, 0xA9, 0x1F,
    0xEC, 0x6F, 0x9A, 0x00, 0x2A, 0x7D, 0xC0, 0x50,
    0x4B, 0x92, 0xA1, 0x93, 0x71, 0x34, 0x58, 0x5F
};

TFM_LINK_SET_RO_IN_PARTITION_SECTION("TFM_SP_INITIAL_ATTESTATION", "PSA-ROT")
const uint32_t initial_attestation_private_key_size =
        sizeof(initial_attestation_private_key);
#endif /* SYMMETRIC_INITIAL_ATTESTATION */
