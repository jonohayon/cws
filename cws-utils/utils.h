#include <stdint.h>

#ifndef CWS_UTILS__UTILS_H
#define CWS_UTILS__UTILS_H

typedef struct cws_string_s {
  char *data;
  uint32_t length;
} cws_string_t;

#endif // CWS_UTILS__UTILS_H
