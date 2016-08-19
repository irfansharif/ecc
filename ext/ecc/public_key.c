#include <ruby.h>
#include "public_key.h"

VALUE public_key_create(int argc, VALUE* argv, VALUE self) {
  // TODO(irfansharif): don't rebuild context each time, sign and ctx
  VALUE private_key, compressed;
  rb_scan_args(argc, argv, "11", &private_key, &compressed);

  if (RSTRING_LEN(private_key) != 32)
    rb_raise(rb_eRuntimeError, "Private key length is invalid");
  const unsigned char* private_key_buffer = StringValuePtr(private_key);

  if (TYPE(compressed) != T_FALSE)
    compressed = Qtrue;
  unsigned int flags = compressed == Qtrue ? SECP256K1_EC_COMPRESSED : SECP256K1_EC_UNCOMPRESSED;

  secp256k1_pubkey public_key;
  secp256k1_context *sign = secp256k1_context_create(SECP256K1_CONTEXT_SIGN);
  secp256k1_context *ctx = secp256k1_context_create(SECP256K1_CONTEXT_SIGN | SECP256K1_CONTEXT_VERIFY);

  if(secp256k1_ec_pubkey_create(sign, &public_key, private_key_buffer) == 0)
    rb_raise(rb_eRuntimeError, "Private key was invalid, try again");

  unsigned char output[65];
  size_t output_length = 65;
  secp256k1_ec_pubkey_serialize(ctx, output, &output_length, &public_key, flags);

  return rb_str_new(output, output_length);
}

VALUE public_key_convert(int argc, VALUE* argv, VALUE self) {
  // TODO(irfansharif): don't rebuild context each time, sign and ctx
  VALUE public_key, compressed;
  rb_scan_args(argc, argv, "11", &public_key, &compressed);

  size_t public_key_length = RSTRING_LEN(public_key);
  if (public_key_length != 33 && public_key_length != 65)
    rb_raise(rb_eRuntimeError, "Public key length is invalid");
  const unsigned char* public_key_buffer = StringValuePtr(public_key);

  if (TYPE(compressed) != T_FALSE)
    compressed = Qtrue;
  unsigned int flags = compressed == Qtrue ? SECP256K1_EC_COMPRESSED : SECP256K1_EC_UNCOMPRESSED;

  secp256k1_pubkey converted_public_key;
  secp256k1_context *sign = secp256k1_context_create(SECP256K1_CONTEXT_SIGN);
  secp256k1_context *ctx = secp256k1_context_create(SECP256K1_CONTEXT_SIGN | SECP256K1_CONTEXT_VERIFY);

  if (secp256k1_ec_pubkey_parse(sign, &converted_public_key, public_key_buffer, public_key_length) == 0)
    rb_raise(rb_eRuntimeError, "The public key could not be parsed or is invalid");

  unsigned char output[65];
  size_t output_length = 65;
  secp256k1_ec_pubkey_serialize(ctx, output, &output_length, &converted_public_key, flags);

  return rb_str_new(output, output_length);
}

VALUE public_key_verify(VALUE self, VALUE public_key) {
  size_t public_key_length = RSTRING_LEN(public_key);
  if (public_key_length != 33 && public_key_length != 65)
    rb_raise(rb_eRuntimeError, "Public key length is invalid");

  const unsigned char* public_key_buffer = StringValuePtr(public_key);

  secp256k1_pubkey parsed_public_key;
  int result = secp256k1_ec_pubkey_parse(secp_ctx, &parsed_public_key, public_key_buffer, public_key_length);
  return result ? Qtrue : Qfalse;
}

VALUE public_key_tweak_add(int argc, VALUE* argv, VALUE self) {
  // TODO(irfansharif): don't rebuild context each time, sign and ctx
  VALUE public_key, tweak, compressed;
  rb_scan_args(argc, argv, "21", &public_key, &tweak, &compressed);

  size_t public_key_length = RSTRING_LEN(public_key);
  if (public_key_length != 33 && public_key_length != 65)
    rb_raise(rb_eRuntimeError, "Public key length is invalid");
  if (RSTRING_LEN(tweak) != 32)
    rb_raise(rb_eRuntimeError, "Tweak length is invalid");
  if (TYPE(compressed) != T_FALSE)
    compressed = Qtrue;

  unsigned int flags = compressed == Qtrue ? SECP256K1_EC_COMPRESSED : SECP256K1_EC_UNCOMPRESSED;
  const unsigned char* public_key_buffer = StringValuePtr(public_key);
  const unsigned char* tweak_buffer = StringValuePtr(tweak);

  secp256k1_context *sign = secp256k1_context_create(SECP256K1_CONTEXT_SIGN);
  secp256k1_context *ctx = secp256k1_context_create(SECP256K1_CONTEXT_SIGN | SECP256K1_CONTEXT_VERIFY);

  secp256k1_pubkey parsed_public_key;
  if (secp256k1_ec_pubkey_parse(sign, &parsed_public_key, public_key_buffer, public_key_length) == 0)
    rb_raise(rb_eRuntimeError, "The public key could not be parsed or is invalid");

  if (secp256k1_ec_pubkey_tweak_add(ctx, &parsed_public_key, tweak_buffer) == 0)
    rb_raise(rb_eRuntimeError, "Tweak out of range or resulting public key is invalid");

  unsigned char output[65];
  size_t output_length = 65;
  secp256k1_ec_pubkey_serialize(ctx, output, &output_length, &parsed_public_key, flags);

  return rb_str_new(output, output_length);
}

VALUE public_key_tweak_multiply(int argc, VALUE* argv, VALUE self) {
  // TODO(irfansharif): don't rebuild context each time, sign and ctx
  VALUE public_key, tweak, compressed;
  rb_scan_args(argc, argv, "21", &public_key, &tweak, &compressed);

  size_t public_key_length = RSTRING_LEN(public_key);
  if (public_key_length != 33 && public_key_length != 65)
    rb_raise(rb_eRuntimeError, "Public key length is invalid");
  if (RSTRING_LEN(tweak) != 32)
    rb_raise(rb_eRuntimeError, "Tweak length is invalid");
  if (TYPE(compressed) != T_FALSE)
    compressed = Qtrue;

  unsigned int flags = compressed == Qtrue ? SECP256K1_EC_COMPRESSED : SECP256K1_EC_UNCOMPRESSED;
  const unsigned char* public_key_buffer = StringValuePtr(public_key);
  const unsigned char* tweak_buffer = StringValuePtr(tweak);

  secp256k1_context *sign = secp256k1_context_create(SECP256K1_CONTEXT_SIGN);
  secp256k1_context *ctx = secp256k1_context_create(SECP256K1_CONTEXT_SIGN | SECP256K1_CONTEXT_VERIFY);

  secp256k1_pubkey parsed_public_key;
  if (secp256k1_ec_pubkey_parse(sign, &parsed_public_key, public_key_buffer, public_key_length) == 0)
    rb_raise(rb_eRuntimeError, "The public key could not be parsed or is invalid");

  if (secp256k1_ec_pubkey_tweak_mul(ctx, &parsed_public_key, tweak_buffer) == 0)
    rb_raise(rb_eRuntimeError, "Tweak out of range or resulting public key is invalid");

  unsigned char output[65];
  size_t output_length = 65;
  secp256k1_ec_pubkey_serialize(ctx, output, &output_length, &parsed_public_key, flags);

  return rb_str_new(output, output_length);
}

VALUE public_key_combine(int argc, VALUE* argv, VALUE self) {
  VALUE public_keys, compressed, public_key;
  rb_scan_args(argc, argv, "11", &public_keys, &compressed);
  if (TYPE(compressed) != T_FALSE)
    compressed = Qtrue;

  unsigned int flags = compressed == Qtrue ? SECP256K1_EC_COMPRESSED : SECP256K1_EC_UNCOMPRESSED;
  int key_count = RARRAY_LEN(public_keys);
  size_t public_key_length;

  secp256k1_context *sign = secp256k1_context_create(SECP256K1_CONTEXT_SIGN);
  secp256k1_context *ctx = secp256k1_context_create(SECP256K1_CONTEXT_SIGN | SECP256K1_CONTEXT_VERIFY);

  /* std::unique_ptr<secp256k1_pubkey[]> public_keys_buffer(new secp256k1_pubkey[key_count]); */
  secp256k1_pubkey public_keys_buffer[key_count];
  secp256k1_pubkey* ins[key_count];
  /* std::unique_ptr<secp256k1_pubkey*[]> ins(new secp256k1_pubkey*[key_count]); */
  for (unsigned int i = 0; i < key_count; ++i) {
    public_key = rb_ary_entry(public_keys, i);
    public_key_length = RSTRING_LEN(public_key);
    if (public_key_length != 33 && public_key_length != 65)
      rb_raise(rb_eRuntimeError, "Public key length is invalid");

    const unsigned char* public_key_buffer = StringValuePtr(public_key);
    if (secp256k1_ec_pubkey_parse(sign, &public_keys_buffer[i], public_key_buffer, public_key_length) == 0)
      rb_raise(rb_eRuntimeError, "The public key could not be parsed or is invalid");

    ins[i] = &public_keys_buffer[i];
  }

  secp256k1_pubkey combined_public_key;
  if (secp256k1_ec_pubkey_combine(ctx, &combined_public_key, ins, key_count) == 0)
    rb_raise(rb_eRuntimeError, "Public key combinations failed");

  unsigned char output[65];
  size_t output_length = 65;
  secp256k1_ec_pubkey_serialize(ctx, output, &output_length, &combined_public_key, flags);

  return rb_str_new(output, output_length);
}
