project('chk-core', 'c', version: '0.1.1', license: 'MIT')

core_inc = include_directories('include')

subdir('include')
subdir('src')

pkg_mod = import('pkgconfig')
pkg_mod.generate(
  libraries: chk_core_lib,
  name: 'chk-core',
  filebase: 'chk-core',
  description: 'Core libraries for chk projects.',
)