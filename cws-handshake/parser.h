#include "cws-handshake/handshake.h"
#include "cws-utils/utils.h"

#include <stdint.h>

#ifndef CWS_HANDSHAKE__PARSER_H
#define CWS_HANDSHAKE__PARSER_H

uint16_t get_port();

cws_status_code_t parse_client_handshake(char *client_handshake);

#endif // CWS_HANDSHAKE__PARSER_H
