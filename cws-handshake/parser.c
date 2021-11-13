#include <stdio.h>

#include "cws-handshake/parser.h"
#include "cws-utils/utils.h"

uint16_t get_port() {
  return 3316;
}

cws_status_code_t parse_client_handshake(char *client_handshake) {
  cws_status_code_t retval = SUCCESS;
  cws_string_list_t values = {
    .length = 1
  };

  ASSERT_NON_NULL(client_handshake);

  create_string_list(&values);
  parse_comma_separated_list(client_handshake, &values);

  for (size_t i = 0; i < values.length; i++) {
    printf("%s\n", values.strings[i].data);
  }

cleanup:
  if (0 != values.length) {
    release_string_list(&values);
  }

  return retval;
}
