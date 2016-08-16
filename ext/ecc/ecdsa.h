#include "ecc.h"

#ifndef ECDSA
#define ECDSA

extern secp_ctx_t* secp_ctx;

VALUE sign(int, VALUE*, VALUE);
VALUE verify(VALUE, VALUE, VALUE, VALUE);
VALUE recover(int, VALUE*, VALUE);

#endif
