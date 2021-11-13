cws
===

> A simple WebSocket server built in C with libuv.

## Why?
I wanted to learn how to build a project using Bazel and Conan together, and to
train my C programming abilities.

## Design
The code will be built in a modular fashion, split into different packages:
 - `cws-server` is the main package, exporting functions that allow you to write
   a server that handles WebSocket connections with ease.
 - `cws-protocol` is the WebSocket protocol implementation, exporting functions
   that allow you to parse and encode WebSocket protocol messages as defined in
   RFC6455.
 - `cws-handshake` is the HTTP handshake parser, given a client handshake request
   it generates the server handshake response.
