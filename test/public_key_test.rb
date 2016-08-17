require 'test_helper'

class PublicKeyTest < Minitest::Test
  def setup
    loop do
      @private_key = ECC.random_bytes(32)
      break if ECC::SECP256K1.private_key_verify(@private_key)
    end
    @tweak = ECC.random_bytes(32)
  end

  def test_public_key_create
    public_key = ECC::SECP256K1.public_key_create(@private_key, true)
    assert_equal public_key, ECC::SECP256K1.public_key_create(@private_key)
    assert_equal 33, public_key.length
    assert_equal 65, ECC::SECP256K1.public_key_create(@private_key, false).length

    exception = assert_raises(RuntimeError) do
      ECC::SECP256K1.public_key_create(ECC.random_bytes(31), true)
    end
    assert_equal "Private key length is invalid", exception.message
  end
end
