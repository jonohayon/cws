#include <stdint.h>
#include <stdlib.h>

#ifndef CWS_UTILS__UTILS_H
#define CWS_UTILS__UTILS_H

#define ASSERT(_cond, _retval) do { \
    if (!(_cond)) { \
      retval = (_retval); \
      goto cleanup; \
    } \
  } while (0)

#define ASSERT_NON_NULL(_variable) ASSERT(NULL != (_variable), NULL_POINTER_GIVEN)

#define ASSERT_SUCCESS() ASSERT(SUCCESS == retval, retval)

typedef enum cws_status_code_e {
  SUCCESS = 0,
  NULL_POINTER_GIVEN,
  ZERO_SIZED_LIST,
} cws_status_code_t;

typedef struct cws_string_s {
  char *data;
  size_t length;
  size_t max_size;
} cws_string_t;

typedef struct cws_string_list_s {
  size_t length;
  cws_string_t strings[0];
} cws_string_list_t;

cws_status_code_t create_string_list(cws_string_list_t *string_list);

cws_status_code_t add_string_to_list(cws_string_list_t *string_list, char *in_string,
    size_t string_length);

cws_status_code_t release_string_list(cws_string_list_t *string_list);

/**
 * Parses a given comma-separated list of values into an array of strings.
 * 
 * @param [in] in_values The input comma-separated list of values
 * @param [out] out_list The output list of values from the input list
 */
cws_status_code_t parse_comma_separated_list(char *in_values, cws_string_list_t *out_list);

#endif // CWS_UTILS__UTILS_H
