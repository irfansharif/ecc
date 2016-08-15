#include "ecc.h"

void Init_ecc() {
  VALUE ecc = rb_define_module("ECC");
  VALUE secp = rb_define_module_under(ecc, "SECP256K1");

  rb_define_singleton_method(secp, "private_key_verify", private_key_verify, 1);
  rb_define_singleton_method(secp, "private_key_tweak_add", private_key_tweak_add, 2);
  rb_define_singleton_method(secp, "private_key_tweak_multiply", private_key_tweak_multiply, 2);
  rb_define_singleton_method(secp, "public_key_create", public_key_create, -1);
  rb_define_singleton_method(secp, "public_key_convert", public_key_convert, -1);
  rb_define_singleton_method(secp, "public_key_verify", public_key_verify, 1);
  rb_define_singleton_method(secp, "public_key_tweak_add", public_key_tweak_add, 2);
  rb_define_singleton_method(secp, "public_key_tweak_multiply", public_key_tweak_multiply, 2);
  rb_define_singleton_method(secp, "public_key_combine", public_key_combine, -1);
  rb_define_singleton_method(secp, "signature_normalize", signature_normalize, 1);
  rb_define_singleton_method(secp, "sign", sign, -1);
  rb_define_singleton_method(secp, "verify", verify, 3);
  rb_define_singleton_method(secp, "recover", recover, -1);
  rb_define_singleton_method(secp, "ecdh", ecdh, 2);
}
