#ifndef __GNUTLS_PRIVKEY_H
#define __GNUTLS_PRIVKEY_H

#include <stdarg.h>
#include <gnutls/gnutls.h>
#include <gnutls/x509.h>
#include <gnutls/pkcs11.h>
#include <gnutls/openpgp.h>

struct gnutls_privkey_st;
typedef struct gnutls_privkey_st* gnutls_privkey_t;

int gnutls_privkey_init (gnutls_privkey_t * key);
void gnutls_privkey_deinit (gnutls_privkey_t key);
int gnutls_privkey_get_pk_algorithm (gnutls_privkey_t key, unsigned int* bits);
gnutls_privkey_type_t gnutls_privkey_get_type (gnutls_privkey_t key);

#define GNUTLS_PRIVKEY_IMPORT_AUTO_RELEASE 1
int gnutls_privkey_import_pkcs11 (gnutls_privkey_t pkey, gnutls_pkcs11_privkey_t key, unsigned int flags);
int gnutls_privkey_import_x509 (gnutls_privkey_t pkey, gnutls_x509_privkey_t key, unsigned int flags);
int gnutls_privkey_import_openpgp (gnutls_privkey_t pkey, gnutls_openpgp_privkey_t key, unsigned int flags);

int gnutls_privkey_sign_data(gnutls_privkey_t signer,
				gnutls_digest_algorithm_t hash,
				unsigned int flags,
				const gnutls_datum_t * data,
				gnutls_datum_t * signature);
int gnutls_privkey_sign_hash (gnutls_privkey_t key,
				 const gnutls_datum_t * hash,
				 gnutls_datum_t * signature);

int gnutls_privkey_decrypt_data(gnutls_privkey_t signer,
				unsigned int flags,
				const gnutls_datum_t * ciphertext,
				gnutls_datum_t * plaintext);

int gnutls_x509_crt_privkey_sign (gnutls_x509_crt_t crt, gnutls_x509_crt_t issuer,
			     gnutls_privkey_t issuer_key,
			     gnutls_digest_algorithm_t dig,
			     unsigned int flags);

int gnutls_x509_crl_privkey_sign (gnutls_x509_crl_t crl,
			     gnutls_x509_crt_t issuer,
			     gnutls_privkey_t issuer_key,
			     gnutls_digest_algorithm_t dig,
			     unsigned int flags);

int gnutls_x509_crq_privkey_sign (gnutls_x509_crq_t crq,
			     gnutls_privkey_t key,
			     gnutls_digest_algorithm_t dig,
			     unsigned int flags);

#endif
