/**
 * server.h - Defines the main WebSocket server functions and data structures.
 */
#include <stdint.h>

#ifndef CWS_SERVER__SERVER_H
#define CWS_SERVER__SERVER_H

typedef struct cws_server_s {
  uint16_t port;
} cws_server_t;

cws_server_t *init_server();

void release_server(cws_server_t *server);

#endif // CWS_SERVER__SERVER_H
