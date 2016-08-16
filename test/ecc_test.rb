require 'test_helper'

class ECCTest < Minitest::Test
  def test_that_it_has_a_version_number
    refute_nil ::ECC::VERSION
  end

  def test_private_key_api_coverage
    assert ECC::SECP256K1.methods.include? :private_key_verify
    assert ECC::SECP256K1.methods.include? :private_key_tweak_add
    assert ECC::SECP256K1.methods.include? :private_key_tweak_multiply
  end

  def test_public_key_api_coverage
    assert ECC::SECP256K1.methods.include? :public_key_create
    assert ECC::SECP256K1.methods.include? :public_key_convert
    assert ECC::SECP256K1.methods.include? :public_key_verify
    assert ECC::SECP256K1.methods.include? :public_key_tweak_add
    assert ECC::SECP256K1.methods.include? :public_key_tweak_multiply
    assert ECC::SECP256K1.methods.include? :public_key_combine
  end

  def test_signature_api_coverage
    assert ECC::SECP256K1.methods.include? :signature_normalize
  end

  def test_ecdsa_api_coverage
    assert ECC::SECP256K1.methods.include? :sign
    assert ECC::SECP256K1.methods.include? :verify
    assert ECC::SECP256K1.methods.include? :recover
  end

  def test_ecdh_api_coverage
    assert ECC::SECP256K1.methods.include? :ecdh
  end
end
