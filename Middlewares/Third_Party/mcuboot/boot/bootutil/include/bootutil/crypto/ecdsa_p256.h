/*
 * This module provides a thin abstraction over some of the crypto
 * primitives to make it easier to swap out the used crypto library.
 *
 * At this point, there are two choices: MCUBOOT_USE_MBED_TLS, or
 * MCUBOOT_USE_TINYCRYPT.  It is a compile error there is not exactly
 * one of these defined.
 */

#ifndef __BOOTUTIL_CRYPTO_ECDSA_P256_H_
#define __BOOTUTIL_CRYPTO_ECDSA_P256_H_

#include "mcuboot_config/mcuboot_config.h"

#if (defined(MCUBOOT_USE_TINYCRYPT) + \
     defined(MCUBOOT_USE_CC310) + \
     defined(MCUBOOT_USE_MBED_TLS)) != 1
    #error "One crypto backend must be defined: either CC310 or TINYCRYPT"
#endif

#if defined(MCUBOOT_USE_TINYCRYPT)
    #include <tinycrypt/ecc_dsa.h>
    #include <tinycrypt/constants.h>
    #define BOOTUTIL_CRYPTO_ECDSA_P256_HASH_SIZE (4 * 8)
#endif /* MCUBOOT_USE_TINYCRYPT */

#if defined(MCUBOOT_USE_CC310)
    #include <cc310_glue.h>
    #define BOOTUTIL_CRYPTO_ECDSA_P256_HASH_SIZE (4 * 8)
#endif /* MCUBOOT_USE_CC310 */

#ifdef __cplusplus
extern "C" {
#endif
#if defined(MCUBOOT_USE_MBED_TLS)
typedef mbedtls_ecp_keypair bootutil_ecdsa_p256_context;
static inline void bootutil_ecdsa_p256_init(bootutil_ecdsa_p256_context *ctx)
{
    mbedtls_ecp_keypair_init(ctx);
}
#define BITS_TO_BYTES(bits) (((bits) + 7) / 8)

static inline int bootutil_ecdsa_p256_verify(bootutil_ecdsa_p256_context *ctx, const uint8_t *pk, int len, const uint8_t *hash, const uint8_t *sig)
{
    int rc=-1;
    mbedtls_mpi r, s;
    size_t curve_bytes;

    rc = mbedtls_ecp_group_load(&ctx->grp,  MBEDTLS_ECP_DP_SECP256R1);
    if (rc)
        return -1;
    /*  size is hardcoded required  */
    rc = mbedtls_ecp_point_read_binary( &ctx->grp, &ctx->Q,
			pk, 65);
    if (rc) return -4;
    /* Check that the point is on the curve. */
	rc = mbedtls_ecp_check_pubkey( &ctx->grp, &ctx->Q );
    if (rc) return -5;
    /* set signature   */
	mbedtls_mpi_init( &r );
	mbedtls_mpi_init( &s );
    curve_bytes = BITS_TO_BYTES( ctx->grp.pbits );
    rc = mbedtls_mpi_read_binary(&r,sig, curve_bytes);
    if (rc) goto out;
    rc = mbedtls_mpi_read_binary(&s,sig + curve_bytes, curve_bytes);
    if (rc) goto out;
    rc = mbedtls_ecdsa_verify( &ctx->grp, hash , NUM_ECC_BYTES,
			&ctx->Q, &r, &s );
out:
    mbedtls_mpi_free( &r );
    mbedtls_mpi_free( &s );
    return rc;
}
static inline void bootutil_ecdsa_p256_drop(bootutil_ecdsa_p256_context *ctx)
{
    mbedtls_ecp_keypair_free(ctx);
}


#endif
#if defined(MCUBOOT_USE_TINYCRYPT)
typedef mbedtls_ecp_keypair bootutil_ecdsa_p256_context;
static inline void bootutil_ecdsa_p256_init(bootutil_ecdsa_p256_context *ctx)
{
    mbedtls_ecp_keypair_init(ctx);
    
}

static inline void bootutil_ecdsa_p256_drop(bootutil_ecdsa_p256_context *ctx)
{
    (void)ctx;
}

static inline int bootutil_ecdsa_p256_verify(bootutil_ecdsa_p256_context *ctx, const uint8_t *pk, const uint8_t *hash, const uint8_t *sig)
{
    int rc;
    rc = mbedtls_ecp_group_load(&ctx->grp,  MBEDTLS_ECP_DP_SECP256R1)
    if (rc)
        return -1;
    mbedtls_ecp_point_read_binary( &ecp.grp, &ecp.Q,
			pk, (end - pubkey));
    
        ;rc = uECC_verify(pk, hash, BOOTUTIL_CRYPTO_ECDSA_P256_HASH_SIZE, sig, uECC_secp256r1());
    if (rc != TC_CRYPTO_SUCCESS) {
        return -1;
    }
    return 0;
}
#endif /* MCUBOOT_USE_TINYCRYPT */

#if defined(MCUBOOT_USE_CC310)
typedef uintptr_t bootutil_ecdsa_p256_context;
static inline void bootutil_ecdsa_p256_init(bootutil_ecdsa_p256_context *ctx)
{
    (void)ctx;
}

static inline void bootutil_ecdsa_p256_drop(bootutil_ecdsa_p256_context *ctx)
{
    (void)ctx;
}

static inline int bootutil_ecdsa_p256_verify(bootutil_ecdsa_p256_context *ctx, uint8_t *pk, uint8_t *hash, uint8_t *sig)
{
    (void)ctx;
    return cc310_ecdsa_verify_secp256r1(hash, pk, sig, BOOTUTIL_CRYPTO_ECDSA_P256_HASH_SIZE);
}
#endif /* MCUBOOT_USE_CC310 */

#ifdef __cplusplus
}
#endif

#endif /* __BOOTUTIL_CRYPTO_ECDSA_P256_H_ */
