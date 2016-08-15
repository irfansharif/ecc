#ifndef ECC
#define ECC

#include <ruby.h>
#include "private_key.h"
#include "public_key.h"
#include "signature.h"
#include "ecdsa.h"
#include "ecdh.h"

void Init_ecc();

#endif
