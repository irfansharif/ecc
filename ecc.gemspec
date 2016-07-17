# coding: utf-8
lib = File.expand_path('../lib', __FILE__)
$LOAD_PATH.unshift(lib) unless $LOAD_PATH.include?(lib)
require 'ecc/version'

Gem::Specification.new do |spec|
  spec.name          = "ecc"
  spec.version       = Ecc::VERSION
  spec.authors       = ["Irfan Sharif"]
  spec.email         = ["irfanmahmoudsharif@gmail.com"]

  spec.summary       = %q{Ruby bindings for an Optimized C library for EC operations on curve secp256k1}
  spec.description   = %q{Ruby bindings to Elliptic Curve Digital Signature Algorithm secp256k1 functions}
  spec.homepage      = "https://github.com/irfansharif/ecc"
  spec.license       = "MIT"

  # Prevent pushing this gem to RubyGems.org. To allow pushes either set the 'allowed_push_host'
  # to allow pushing to a single host or delete this section to allow pushing to any host.
  if spec.respond_to?(:metadata)
    spec.metadata['allowed_push_host'] = "TODO: Set to 'http://mygemserver.com'"
  else
    raise "RubyGems 2.0 or newer is required to protect against public gem pushes."
  end

  spec.files         = `git ls-files -z`.split("\x0").reject { |f| f.match(%r{^(test|spec|features)/}) }
  spec.bindir        = "exe"
  spec.executables   = spec.files.grep(%r{^exe/}) { |f| File.basename(f) }
  spec.extensions = %w[ext/ecc/extconf.rb]
  spec.require_paths = ["lib"]

  spec.add_development_dependency "bundler", "~> 1.12"
  spec.add_development_dependency "rake", "~> 10.0"
  spec.add_development_dependency "minitest", "~> 5.0"
end
