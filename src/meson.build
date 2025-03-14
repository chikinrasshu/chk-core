core_sources = ['chk/core/format.c', 'chk/core/logging.c']

cwalk_dep = dependency('cwalk', fallback: ['cwalk', 'cwalk_dep'], static: true)

chk_core_lib = library(
  'chk-core',
  core_sources,
  include_directories: core_inc,
  dependencies: [cwalk_dep],
  install: true,
)