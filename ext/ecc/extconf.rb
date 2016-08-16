# Extension configuration
# Loads mkmf which is used to make makefiles for Ruby extensions
require 'mkmf'

LIBDIR      = RbConfig::CONFIG['libdir']
INCLUDEDIR  = RbConfig::CONFIG['includedir']

HEADER_DIRS = [
  '/opt/local/include',
  '/usr/local/include',
  INCLUDEDIR,
  '/usr/include',
]

LIB_DIRS = [
  '/usr/local/lib',
  LIBDIR,
  '/usr/lib',
]

unless find_header('secp256k1.h')
  abort 'secp256k1 is missing'
end

unless have_library('secp256k1') && append_library($libs, 'secp256k1')
  abort "Unable to append library secp256k1!"
end

$CFLAGS << ' -std=c99'

dir_config('secp256k1', HEADER_DIRS, LIB_DIRS)

extension_name = 'ecc'
dir_config(extension_name)
create_makefile(extension_name)
