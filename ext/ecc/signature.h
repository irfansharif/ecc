#include "ecc.h"

#ifndef SIGNATURE
#define SIGNATURE

extern secp_ctx_t* secp_ctx;

VALUE signature_normalize(VALUE);

#endif
