#include <ruby.h>
#include "private_key.h"

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
