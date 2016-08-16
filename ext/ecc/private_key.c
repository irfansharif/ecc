#include <ruby.h>
#include "private_key.h"

VALUE private_key_verify(VALUE self, VALUE private_key) {
  char* private_key_buffer = StringValueCStr(private_key);
  if (RSTRING_LEN(private_key) != 32)
    rb_raise(rb_eRuntimeError, "Private key length is invalid");

  return secp256k1_ec_seckey_verify(secp_ctx, private_key_buffer) ? Qtrue : Qfalse;
}

VALUE private_key_tweak_add(VALUE self, VALUE private_key, VALUE tweak) {
  if (RSTRING_LEN(private_key) != 32)
    rb_raise(rb_eRuntimeError, "Private key length is invalid");
  if (RSTRING_LEN(tweak) != 32)
    rb_raise(rb_eRuntimeError, "Tweak length is invalid");

  unsigned char private_key_buffer[32];
  memcpy(private_key_buffer, StringValueCStr(private_key), 32);
  char* tweak_buffer = StringValueCStr(tweak);

  if (secp256k1_ec_privkey_tweak_add(secp_ctx, private_key_buffer, tweak_buffer) == 0)
    rb_raise(rb_eRuntimeError, "Tweak out of range or resulting private key is invalid");

  return rb_str_new2(private_key_buffer);
}

VALUE private_key_tweak_multiply(VALUE self, VALUE private_key, VALUE tweak) {
  if (RSTRING_LEN(private_key) != 32)
    rb_raise(rb_eRuntimeError, "Private key length is invalid");
  if (RSTRING_LEN(tweak) != 32)
    rb_raise(rb_eRuntimeError, "Tweak length is invalid");

  unsigned char private_key_buffer[32];
  memcpy(private_key_buffer, StringValueCStr(private_key), 32);
  char* tweak_buffer = StringValueCStr(tweak);

  if (secp256k1_ec_privkey_tweak_mul(secp_ctx, private_key_buffer, tweak_buffer) == 0)
    rb_raise(rb_eRuntimeError, "Tweak out of range");

  return rb_str_new2(private_key_buffer);
}
