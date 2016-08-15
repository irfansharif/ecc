#ifndef PRIVATE_KEY
#define PRIVATE_KEY

VALUE private_key_verify(VALUE, VALUE);
VALUE private_key_tweak_add(VALUE, VALUE, VALUE);
VALUE private_key_tweak_multiply(VALUE, VALUE, VALUE);

#endif
