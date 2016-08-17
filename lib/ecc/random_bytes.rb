module ECC
  def self.random_bytes(n = 32)
    SecureRandom.random_bytes(n)
  end
end
