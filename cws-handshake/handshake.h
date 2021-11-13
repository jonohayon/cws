#include "cws-utils/utils.h"

#ifndef CWS_HANDSHAKE__HANDSHAKE_H
#define CWS_HANDSHAKE__HANDSHAKE_H

#define MAX_REQUESTED_SUBPROTOCOLS (10)

#define MAX_REQUESTED_EXTENSIONS (10)

typedef struct cws_client_handshake_s {
  uint16_t websocket_version;
  char *uri;
  char *key;
  cws_string_t *subprotocols[MAX_REQUESTED_SUBPROTOCOLS];
  cws_string_t *extensions[MAX_REQUESTED_EXTENSIONS];
} cws_client_handshake_t;

typedef struct cws_server_handshake_s {
  cws_string_t *accepted_key;
  cws_string_t *chosen_protocol;
  cws_string_t *chosen_extensions[MAX_REQUESTED_EXTENSIONS];
} cws_server_handshake_t;

#endif // CWS_HANDSHAKE__HANDSHAKE_H
