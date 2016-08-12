API Reference:

  - [`private_key_verify(private_key)`](#private_key_verifyprivate_key)
  - [`private_key_tweak_add(private_key, tweak)`](#private_key_tweak_addprivate_key-tweak)
  - [`private_key_tweak_multiply(private_key, tweak)`](#private_key_tweak_multiplyprivate_key-tweak)
  - [`public_key_create(private_key, compressed = true)`](#public_key_createprivate_key--compressed--true)
  - [`public_key_convert(public_key, compressed = true)`](#public_key_convertpublic_key--compressed--true)
  - [`public_key_verify(public_key)`](#public_key_verifypublic_key)
  - [`public_key_tweak_add(public_key, tweak, compressed = true)`](#public_key_tweak_addpublic_key-tweak--compressed--true)
  - [`public_key_tweak_multiply(public_key, tweak, compressed = true)`](##public_key_tweak_multiplypublic_key-tweak--compressed--true)
  - [`public_key_combine(public_keys, compressed = true)`](#public_key_combinepublic_keys--compressed--true)
  - [`signature_normalize(signature)`](#signature_normalizesignature)
  - [`sign(message, private_key, options)`](#signmessage-private_key--options)
  - [`verify(message, signature, public_key)`](#verifymessage-signature-public_key)
  - [`recover(message, signature, recovery, compressed = true)`](#recovermessage-signature-recovery--compressed--true)
  - [`ecdh(public_key, private_key)`](#ecdhpublic_key-private_key)

#####`private_key_verify(private_key)`
  Verify an ECDSA `private_key`.

#####`private_key_tweak_add(private_key, tweak)`
  Tweak a `private_key` by adding `tweak` to it.

#####`private_key_tweak_multiply(private_key, tweak)`
  Tweak a `private_key` by multiplying it by a `tweak`.

#####`public_key_create(private_key [, compressed = true])`
  Compute the public key for a `private_key`.

#####`public_key_convert(public_key [, compressed = true])`
  Convert a `public_key` to compressed or uncompressed form.

#####`public_key_verify(public_key)`
  Verify an ECDSA `public_key`.

#####`public_key_tweak_add(public_key, tweak [, compressed = true])`
  Tweak a `public_key` by adding `tweak` times the generator to it.

#####`public_key_tweak_multiply(public_key, tweak [, compressed = true])`
  Tweak a `public_key` by multiplying it by a `tweak` value.

#####`public_key_combine(public_keys [, compressed = true])`
  Add a given `public_keys` together.

#####`signature_normalize(signature)`
  Convert a `signature` to a normalized lower-S form.

#####`sign(message, private_key [, options])`
  Create an ECDSA signature. Always return low-S signature.

#####`verify(message, signature, public_key)`
  Verify an ECDSA signature.

  Note: return false for high signatures!

#####`recover(message, signature, recovery [, compressed = true])`
  Recover an ECDSA public key from a signature.

#####`ecdh(public_key, private_key)`
  Compute an EC Diffie-Hellman secret and applied SHA-256 to compressed public key.

