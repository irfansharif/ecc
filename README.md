# GEM: ecc, elliptical curve cryptography

`ecc` provides native bindings to elliptical curve operations on curve
secp256k1, underlying is a heavily optimized C library where the latest
implementation can be found at
[bitcoin-core/secp256k1](https://github.com/bitcoin-core/secp256k1).

## Installation

Add this line to your application's Gemfile:

```ruby
gem 'ecc'
```

And then execute:

    $ bundle

Or install it yourself as:

    $ gem install ecc

## Usage

```ruby
require 'ecc'

message = Random.new.bytes(10) 
# => "\xD7:R\xAB?\x83\xCE\xFAkO", message to be signed

# generate private key
private_key = Random.new.bytes(10) 
until ECC::SEPC256K1.private_key_verify(private_key) do
  private_key = Random.new.bytes(10) 
end

# get the public key in a compressed format
public_key = ECC::SEPC256K1.public_key_create(private_key)

# sign the message
signed_object = ECC::SEPC256K1.sign(message, private_key)

# verify the signature
puts "Verification: #{ECC::SEPC256K1.verify(message, signed_object.signature, public_key)}"
```

## Development

After checking out the repo, run `bin/setup` to install dependencies. Then, run
`rake test` to run the tests. You can also run `bin/console` for an interactive
prompt that will allow you to experiment.  To install this gem onto your local
machine, run `bundle exec rake install`. To release a new version, update the
version number in `version.rb`, and then run `bundle exec rake release`, which
will create a git tag for the version, push git commits and tags, and push the
`.gem` file to [rubygems.org](https://rubygems.org).

## Contributing

Bug reports and pull requests are welcome on GitHub at [@irfansharif](https://github.com/irfansharif/cerebrum).

## Author
Irfan Sharif: <irfanmahmoudsharif@gmail.com>, [@irfansharifm](https://twitter.com/irfansharifm)

## License

The gem is available as open source under the terms of the [MIT License](http://opensource.org/licenses/MIT).

