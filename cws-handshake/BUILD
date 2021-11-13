cc_library(
  name = 'handshake-defs',
  srcs = [],
  hdrs = [
    'handshake.h'
  ],
  deps = [
    '//cws-utils:utils',
  ],
  visibility = ['//visibility:private']
)

cc_library(
  name = 'parser',
  srcs = [
    'parser.c'
  ],
  hdrs = [
    'parser.h'
  ],
  deps = [
    ':handshake-defs',
    '//cws-utils:utils',
    '@http_parser//:http_parser'
  ],
  visibility = ['//cws-server:__pkg__']
)
