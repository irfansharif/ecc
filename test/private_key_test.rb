require 'test_helper'

class PrivateKeyTest < Minitest::Test
  def setup
    @private_key = SecureRandom.random_bytes(32)
    @tweak       = SecureRandom.random_bytes(32)
  end

  def test_private_key_verify
    private_key = @private_key
    Timeout::timeout(5) do
      until ECC::SECP256K1.private_key_verify(private_key) do
        private_key = SecureRandom.random_bytes(32) 
      end
    end

    exception = assert_raises(RuntimeError) do 
      ECC::SECP256K1.private_key_verify(SecureRandom.random_bytes(31))
    end
    assert_equal "Private key length is invalid", exception.message
  end

  def test_private_key_tweak_add
    until ECC::SECP256K1.private_key_verify(@private_key) do
      @private_key = SecureRandom.random_bytes(32) 
    end

    exception = assert_raises(RuntimeError) do 
      ECC::SECP256K1.private_key_tweak_add(SecureRandom.random_bytes(31), @tweak)
    end
    assert_equal "Private key length is invalid", exception.message

    exception = assert_raises(RuntimeError) do 
      ECC::SECP256K1.private_key_tweak_add(@private_key, SecureRandom.random_bytes(31))
    end
    assert_equal "Tweak length is invalid", exception.message
  end

  def test_private_key_tweak_multiply
    until ECC::SECP256K1.private_key_verify(@private_key) do
      @private_key = SecureRandom.random_bytes(32) 
    end

    exception = assert_raises(RuntimeError) do 
      ECC::SECP256K1.private_key_tweak_multiply(SecureRandom.random_bytes(31), @tweak)
    end
    assert_equal "Private key length is invalid", exception.message

    exception = assert_raises(RuntimeError) do 
      ECC::SECP256K1.private_key_tweak_multiply(@private_key, SecureRandom.random_bytes(31))
    end
    assert_equal "Tweak length is invalid", exception.message
  end
end
