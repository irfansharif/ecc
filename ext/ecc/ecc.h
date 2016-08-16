#ifndef ECC
#define ECC

#include <ruby.h>
#include <secp256k1.h>
#include "private_key.h"
#include "public_key.h"
#include "signature.h"
#include "ecdsa.h"
#include "ecdh.h"

void Init_ecc();

#endif

typedef struct secp256k1_context secp_ctx_t;
static secp_ctx_t* secp_ctx;
