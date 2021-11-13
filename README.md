cws
===

> A simple WebSocket server built in C with libuv.

## Why?
I wanted to learn how to build a project using [Bazel](http://bazel.build) and
[Conan](http://conan.io), and to train my C programming abilities.

## Design
The code will be built in a modular fashion, split into different packages:
 - `cws-server` is the main package, exporting functions that allow you to write
   a server that handles WebSocket connections with ease.
 - `cws-protocol` is the WebSocket protocol implementation, exporting functions
   that allow you to parse and encode WebSocket protocol messages as defined in
   RFC6455.
 - `cws-handshake` is the HTTP handshake parser, given a client handshake request
   it generates the server handshake response.
 - `cws-utils` holds general purpose utilities used by all of the other packages.

## Requirements
Currently, the project only supports building on macOS.

### Toolchain requirements
In order to use the [zero-size array GCC extension](https://gcc.gnu.org/onlinedocs/gcc-4.7.2/gcc/Zero-Length.html),
a custom C toolchain was required to compile the project on macOS. Moreover, both
Conan and Bazel are requirements to build the project on macOS. Therefore, before
starting to tinker with the project, you need to install the three from `brew`:
```bash
brew install bazel conan gcc@11
```
(I used GCC 11 because it's what I had installed on my machine prior to development)

### Project requirements
You can install the project's requirements using Conan:
```bash
conan install .
```
This will use the defined dependencies from `conanfile.txt` and generate Bazel build
definitions for them, such that the binaries downloaded from Conan can be linked using
Bazel.

## Building
Building the server libary:
```bash
bazel build cws-server:server
```
This will output the static library `libcws-server.a` in `bazel-bin/cws-server` :)

The test server can be used as follows:
```bash
bazel build cws-server:test-server
./bazel-bin/cws-server/test-server
```
