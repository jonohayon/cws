load("@rules_foreign_cc//foreign_cc:defs.bzl", "make")

make(
  name = 'llhttp',
  build_data = ['@llhttp//:all_srcs'],
  out_static_libs = ['lib/libllhttp.a']
)
