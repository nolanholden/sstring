#include "sstring.h"

#include "sstring_bool.h"
#include "sstring_constants.h"
#include "sstring_ternary.h"
#include "sstring_util.h"

#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define NIL 0

sstring_t* sstring_init_with_capacity(const sstring_size_t initial_capacity) {
  sstring_t* s = NIL;

  if (initial_capacity < 0)
    return s;
  
  s = (sstring_t*)malloc(sizeof(sstring_t));
  if (s == NIL)
    return s;

  s->c_string = (char*)malloc(sizeof(char) * initial_capacity);
  if (s->c_string == NIL) {
    free(s);
    return s;
  }

  // Now, input is validated and memory allocated.
  s->capacity = initial_capacity;
  s->length = 0;

  return s;
}

sstring_t* sstring_init(void) {
  return sstring_init_with_capacity(SSTRING_DEFAULT_INITIAL_CAPACITY);
}

void sstring_free(sstring_t* str) {
  if (str != NIL) {
    free(str->c_string);
    free(str);
  }
}

short sstring_compare(const sstring_t* const a, const sstring_t* const b) {

}

// If either a or b are null, returns -1. 
short sstring_equal(const sstring_t* const a, const sstring_t* const b) {
  if (a == NIL || b == NIL)
    return -1;

  return sstring_util_strcmp(a->c_string, b->c_string, );
}



//
// CONSTRUCTION:

sstring_t* sstring_new_empty_sstring_of_length(const int length_without_nil_terminator) {
  sstring_t* s = (sstring_t*)malloc(sizeof(sstring_t));
  s->length = length_without_nil_terminator;
  s->c_string = (char*)malloc(sizeof(1 + s->length));
}

sstring_t* sstring_new_sstring_shallow(char* initial_content){
  sstring_t* s = (sstring_t*)malloc(sizeof(sstring_t));
  s->c_string = initial_content;
  s->length = sstring_util_sstring_util_strlen(initial_content);
  return s;
}
sstring_t* sstring_new_sstring_deep(const char* const initial_content) {
  const int length = sstring_util_sstring_util_strlen(initial_content);
  return sstring_new_sstring_deep_oflength(initial_content, length);
}
sstring_t* sstring_new_sstring_shallow_of_length(char* initial_content, const int length) {
  sstring_t* s = sstring_new_sstring_shallow(initial_content);
  s->c_string[length] = '\0';
}
sstring_t* sstring_new_sstring_deep_of_length(const char* const initial_content, const int length) {
  sstring_t* s = sstring_new_empty_sstring_of_length(length);
  s->c_string[length] = '\0';
  sstring_util_strcpy(initial_content, s->c_string, length);
  return s;
}


//
// CLONING:

sstring_t* sstring_clone_shallow(const sstring_t* const origin);
sstring_t* sstring_clone_deep(const sstring_t* const origin);


//
// OTHER:

sstring_t* sstring_create_reverse_sstring(const sstring_t* const origin) {
  sstring_t* result = (sstring_t*)malloc(sizeof(sstring_t));
  sstring_create_reverse_cstring(origin->c_string, origin->length, result->c_string);
}


//
// DESTRUCTION:

void sstring_free(sstring_t* const s) {
  free(s->c_string);
  free(s);
}
