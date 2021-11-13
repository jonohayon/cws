#include "cws-server/server.h"

#include <stdio.h>

int main(void) {
  cws_server_t *server = init_server();
  printf("Listening on port %d\n", server->port);

  release_server(server);
  return 0;
}
