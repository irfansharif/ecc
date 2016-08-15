#ifndef ECC
#define ECC

#include <ruby.h>

void Init_ecc();
VALUE private_key_verify(VALUE, VALUE);
VALUE private_key_tweak_add(VALUE, VALUE, VALUE);
VALUE private_key_tweak_multiply(VALUE, VALUE, VALUE);
VALUE public_key_create(int, VALUE*, VALUE);
VALUE public_key_convert(int, VALUE*, VALUE);
VALUE public_key_verify(VALUE);
VALUE public_key_tweak_add(int, VALUE*, VALUE);
VALUE public_key_tweak_multiply(int, VALUE*, VALUE);
VALUE public_key_combine(int, VALUE*, VALUE);
VALUE signature_normalize(VALUE);
VALUE sign(int, VALUE*, VALUE);
VALUE verify(VALUE, VALUE, VALUE, VALUE);
VALUE recover(int, VALUE*, VALUE);
VALUE ecdh(VALUE, VALUE, VALUE);

#endif
