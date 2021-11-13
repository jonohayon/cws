#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "cws-utils/utils.h"

#define ASSERT_NON_EMPTY_STRING_LIST(_string_list) do { \
    ASSERT_NON_NULL((_string_list)); \
    ASSERT_NON_NULL((_string_list)->strings); \
    ASSERT(0 != (_string_list)->length, ZERO_SIZED_LIST); \
    ASSERT(0 != (_string_list)->max_size, ZERO_SIZED_LIST); \
  } while (0)

const char COMMA[] = ",";

/**
 * Removes the whitespace from the beginning and end of the given string. Done in-place.
 *
 * @param [in,out] str The string to trim
 * @param [out] output_length The length of the trimmed string
 * @returns The status of the trim operation
 */
static cws_status_code_t trim_string(char *input, size_t *output_length) {
  cws_status_code_t retval = SUCCESS;

  ASSERT_NON_NULL(input);
  ASSERT_NON_NULL(output_length);

  size_t string_length = strlen(input);

  // Remove the spaces from the length count
  for (; isspace(input[string_length - 1]); string_length--);

  *output_length = string_length;

  // Eat up the whitespace from the start of the string
  for (; isspace(*input); input++);

cleanup:
  return retval;
}

cws_status_code_t create_string_list(cws_string_list_t *string_list) {
  cws_status_code_t retval = SUCCESS;

  ASSERT_NON_NULL(string_list);

  ASSERT(0 != string_list->length, ZERO_SIZED_LIST);

  string_list->strings = (cws_string_t *) calloc(string_list->length, sizeof(cws_string_t));
  string_list->max_size = string_list->length;

cleanup:
  return retval;
}

cws_status_code_t add_string_to_list(cws_string_list_t *string_list, char *in_string,
    size_t string_length) {
  cws_status_code_t retval = SUCCESS;
  cws_string_t *new_string = NULL;

  ASSERT_NON_EMPTY_STRING_LIST(string_list);

  // Resize the list if it's already full
  if (string_list->length == string_list->max_size) {
    string_list->max_size *= 2;
    string_list->strings = (cws_string_t *) realloc(string_list->strings, string_list->max_size * sizeof(cws_string_t));

    ASSERT_NON_EMPTY_STRING_LIST(string_list);
  }

  new_string = &string_list->strings[string_list->length];
  new_string->data = in_string;
  new_string->length = string_length;
  string_list->length++;

cleanup:
  return retval;
}

cws_status_code_t release_string_list(cws_string_list_t *string_list) {
  cws_status_code_t retval = SUCCESS;

  ASSERT_NON_EMPTY_STRING_LIST(string_list);

  free(string_list->strings);

cleanup:
  return retval;
}

cws_status_code_t parse_comma_separated_list(char *in_values, cws_string_list_t *out_list) {
  cws_status_code_t retval = SUCCESS;

  ASSERT_NON_NULL(in_values);
  ASSERT_NON_NULL(out_list);

  size_t trimmed_size = 0;
  char *current_value = strtok(in_values, COMMA);
  while (NULL != current_value) {
    retval = trim_string(current_value, &trimmed_size);
    ASSERT_SUCCESS();

    retval = add_string_to_list(out_list, current_value, trimmed_size);
    ASSERT_SUCCESS();
  }

cleanup:
  return retval;
}
