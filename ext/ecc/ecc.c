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

VALUE
private_key_verify(VALUE self, VALUE private_key) {
  return Qfalse;
}

VALUE private_key_tweak_add(VALUE self, VALUE private_key, VALUE tweak) {
  return Qfalse;
}

VALUE private_key_tweak_multiply(VALUE self, VALUE private_key, VALUE tweak) {
  return Qfalse;
}

VALUE public_key_create(int argc, VALUE* argv, VALUE self) {
  return Qfalse;
}

VALUE public_key_convert(int argc, VALUE* argv, VALUE self) {
  return Qfalse;
}

VALUE public_key_verify(VALUE public_key) {
  return Qfalse;
}

VALUE public_key_tweak_add(int argc, VALUE* argv, VALUE self) {
  return Qfalse;
}

VALUE public_key_tweak_multiply(int argc, VALUE* argv, VALUE self) {
  return Qfalse;
}

VALUE public_key_combine(int argc, VALUE* argv, VALUE self) {
  return Qfalse;
}

VALUE signature_normalize(VALUE signature) {
  return Qfalse;
}

VALUE sign(int argc, VALUE* argv, VALUE self) {
  return Qfalse;
}

VALUE verify(VALUE self, VALUE message, VALUE signature, VALUE public_key) {
  return Qfalse;
}

VALUE recover(int argc, VALUE* argv, VALUE self) {
  return Qfalse;
}

VALUE ecdh(VALUE self, VALUE public_key, VALUE private_key) {
  return Qfalse;
}
