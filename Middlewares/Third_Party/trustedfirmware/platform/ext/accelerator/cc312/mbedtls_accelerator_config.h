/*
 * Copyright (c) 2019, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef MBEDTLS_ACCELERATOR_CONF_H
#define MBEDTLS_ACCELERATOR_CONF_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* RNG Config */
#undef MBEDTLS_TEST_NULL_ENTROPY
#undef MBEDTLS_NO_DEFAULT_ENTROPY_SOURCES

#define MBEDTLS_PLATFORM_ENTROPY
#define MBEDTLS_ENTROPY_C
#define MBEDTLS_CTR_DRBG_C
#define MBEDTLS_AES_C
#define MBEDTLS_ENTROPY_HARDWARE_ALT
#define MBEDTLS_ENTROPY_FORCE_SHA256

/* Main Config */

/* The CC312 does not support CFB mode */
#ifdef MBEDTLS_CIPHER_MODE_CFB
#undef MBEDTLS_CIPHER_MODE_CFB
#endif /* MBEDTLS_CIPHER_MODE_CFB */

#ifdef MBEDTLS_AES_C
#define MBEDTLS_AES_ALT
#define MBEDTLS_AES_SETKEY_ENC_ALT
#define MBEDTLS_AES_SETKEY_DEC_ALT
#define MBEDTLS_AES_ENCRYPT_ALT
#define MBEDTLS_AES_DECRYPT_ALT
#endif /* MBEDTLS_AES_C */

#ifdef MBEDTLS_ARIA_C
#define MBEDTLS_ARIA_ALT
#endif /* MBEDTLS_ARIA_C */

#ifdef MBEDTLS_CCM_C
#define MBEDTLS_CCM_ALT
#endif /* MBEDTLS_CCM_C */

#ifdef MBEDTLS_CHACHA20_C
#define MBEDTLS_CHACHA20_ALT
#endif /* MBEDTLS_CHACHA20_C */

#ifdef MBEDTLS_CHACHAPOLY_C
#define MBEDTLS_CHACHAPOLY_ALT
#endif /* MBEDTLS_CHACHAPOLY_C */

#ifdef MBEDTLS_CMAC_C
#define MBEDTLS_CMAC_ALT
#endif /* MBEDTLS_CMAC_C */

#ifdef MBEDTLS_DHM_C
#define MBEDTLS_DHM_ALT
#endif /* MBEDTLS_DHM_C */

#ifdef MBEDTLS_ECDH_C
#define MBEDTLS_ECDH_ALT
#define MBEDTLS_ECDH_GEN_PUBLIC_ALT
#define MBEDTLS_ECDH_COMPUTE_SHARED_ALT
#endif /* MBEDTLS_ECDH_C */

#ifdef MBEDTLS_ECDSA_C
#define MBEDTLS_ECDSA_ALT
#define MBEDTLS_ECDSA_VERIFY_ALT
#define MBEDTLS_ECDSA_SIGN_ALT

#ifndef CRYPTO_HW_ACCELERATOR_OTP_PROVISIONING
#define MBEDTLS_ECDSA_GENKEY_ALT
#endif
#endif /* MBEDTLS_ECDSA_C */

#ifdef MBEDTLS_GCM_C
#define MBEDTLS_GCM_ALT
#endif /* MBEDTLS_GCM_C */

#ifdef MBEDTLS_NIST_KW_C
#define MBEDTLS_NIST_KW_ALT
#endif /* MBEDTLS_NIST_KW_C */

#ifdef MBEDTLS_POLY1305_C
#define MBEDTLS_POLY1305_ALT
#endif /* MBEDTLS_POLY1305_C */

#ifdef MBEDTLS_RSA_C
#define MBEDTLS_RSA_ALT
#define MBEDTLS_PK_RSA_ALT_SUPPORT
#define MBEDTLS_GENPRIME
#endif /* MBEDTLS_RSA_C */

#ifdef MBEDTLS_SHA1_C
#define MBEDTLS_SHA1_ALT
#define MBEDTLS_SHA1_PROCESS_ALT
#endif /* MBEDTLS_SHA1_C */

#ifdef MBEDTLS_SHA256_C
#define MBEDTLS_SHA256_ALT
#define MBEDTLS_SHA256_PROCESS_ALT
#endif /* MBEDTLS_SHA256_C */

#if defined(MBEDTLS_ECP_C) && defined(MBEDTLS_MD_C)
#define MBEDTLS_ECJPAKE_ALT
#endif /* MBEDTLS_ECP_C && MBEDTLS_MD_C */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* MBEDTLS_ACCELERATOR_CONF_H */
