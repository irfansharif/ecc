#ifndef ECDSA
#define ECDSA

VALUE sign(int, VALUE*, VALUE);
VALUE verify(VALUE, VALUE, VALUE, VALUE);
VALUE recover(int, VALUE*, VALUE);

#endif
