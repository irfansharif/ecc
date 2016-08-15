#include <ruby.h>
#include "ecdsa.h"

VALUE sign(int argc, VALUE* argv, VALUE self) {
  return Qfalse;
}

VALUE verify(VALUE self, VALUE message, VALUE signature, VALUE public_key) {
  return Qfalse;
}

VALUE recover(int argc, VALUE* argv, VALUE self) {
  return Qfalse;
}
