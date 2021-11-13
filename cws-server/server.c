#include <stdlib.h>

#include "cws-handshake/parser.h"
#include "cws-server/server.h"

cws_server_t *init_server() {
  cws_server_t *server = (cws_server_t *) calloc(1, sizeof(cws_server_t));
  server->port = get_port();

  parse_client_handshake("a, b, c");

  return server;
}

void release_server(cws_server_t *server) {
  if (NULL != server) {
    free(server);
  }
}
