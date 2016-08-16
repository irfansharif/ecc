#include "ecc.h"

#ifndef PUBLIC_KEY
#define PUBLIC_KEY

extern secp_ctx_t* secp_ctx;

VALUE public_key_create(int, VALUE*, VALUE);
VALUE public_key_convert(int, VALUE*, VALUE);
VALUE public_key_verify(VALUE);
VALUE public_key_tweak_add(int, VALUE*, VALUE);
VALUE public_key_tweak_multiply(int, VALUE*, VALUE);
VALUE public_key_combine(int, VALUE*, VALUE);

#endif
