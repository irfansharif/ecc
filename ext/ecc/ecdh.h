#include "ecc.h"

#ifndef ECDH
#define ECDH

extern secp_ctx_t* secp_ctx;

VALUE ecdh(VALUE, VALUE, VALUE);

#endif
