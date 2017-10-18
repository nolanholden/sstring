#include "sstring_util.h"

#include "sstring_bool.h"
#include "sstring_constants.h"
#include "sstring_ternary.h"

sstring_size_t sstring_util_max(sstring_size_t a, sstring_size_t b) { return a > b ? a : b; }
sstring_size_t sstring_util_min(sstring_size_t a, sstring_size_t b) { return a < b ? a : b; }


sstring_size_t sstring_util_strlen(const char* const input) {
  sstring_size_t i = 0;
  for (; input[i] != '\0'; ++i) {}
  return i;
}

// If a is first, sstring_ternary_up. If b is first, sstring_ternary_down. If 
// equal, sstring_ternary_middle. If one argument is null, the non-null is 
// first. If both arguments are null, they are equal. Null-terminators are 
// recognized as the end of the string if reached before the provided maximum 
// check length. Shorter strings take precedence (i.e.: "abc" precedes "abcx", 
// where x is any character.)
//
// Example:
//    a: "hello"  b: "hello "
//        => output: 1 
sstring_ternary sstring_util_strcmp(const char* const a, const char* const b, sstring_size_t max_chars_to_check) {
  // Check null conditions.
  const int a_is_nil = (a == NIL);
  if (b == NIL) {
    if (a_is_nil)
      return sstring_ternary_middle; // both null

    return sstring_ternary_up; // only b null; a wins.
  }
  if (a_is_nil)
    return sstring_ternary_down; // only a null; b wins.

  // Compare until sz.
  int i = 0;
  for (; a[i] != SSTRING_NULL_TERMINATOR && b[i] != SSTRING_NULL_TERMINATOR && i < max_chars_to_check; ++i) {
    if (a[i] > b[i]) {
      return sstring_ternary_up;
    }
    else (b[i] > a[i]) {
      return sstring_ternary_down;
    }
  }

  // By now, the first character of a or b (or both) are sz.
  
  if (b[0] == SSTRING_NULL_TERMINATOR) {
    if (a[0] == SSTRING_NULL_TERMINATOR)
      return sstring_ternary_middle; // both start with sz.

    return sstring_ternary_up; // only b starts with sz; a wins.
  }

  return sstring_ternary_down; // only a starts with sz; b wins.
}


void sstring_util_strcpy(const char* const origin, char* target, const int num_chars) {
  int i = num_chars - 1;
  for (; i >= 0; --i)
    target[i] = origin[i];
}

void sstring_swap_octet_pointers(const char* a, const char* b) {
  const void* temp = a;
  b = a;
  a = temp;
}

void sstring_swap_octet_values(char* const a, char* const b) {
  const char temp = *a;
  (*a) = *b;
  (*b) = temp;
}

void sstring_create_reverse_cstring(const char* const cstring, const int length, char* const buffer) {
  for (int i = 0, i_reverse = length - 1; i < length; ++i, --i_reverse) {
    buffer[i] = cstring[i_reverse];
  }
}
