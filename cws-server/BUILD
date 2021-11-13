cc_library(
  name = 'cws-server',
  srcs = [
    'server.c'
  ],
  hdrs = [
    'server.h'
  ],
  deps = [
    '//cws-handshake:parser'
  ]
)

cc_binary(
  name = 'test-server',
  srcs = [
    'bin/test-server.c'
  ],
  visibility = ['//visibility:public'],
  deps = [
    ':cws-server'
  ]
)
