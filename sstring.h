#ifndef _SSTRING_H_
#define _SSTRING_H_

#include "sstring_constants.h"

#include <stdlib.h>


typedef struct {
  
  // The underlying C string, including null terminator '\0'
  char* c_string;
  
  // The length of the C string, NOT including the null terminator
  sstring_size_t length;

  // The absolute capacity of the underlying C string
  sstring_size_t capacity;
  
} sstring_t;


//
// CONSTRUCTION:

// Create a sstring_t pointing to the provided null-terminated C string.
sstring_t* sstring_new_sstring_shallow(char* initial_content);

// Create an sstring_t with clone of the provided null-terminated C string.
sstring_t* sstring_new_sstring_deep(const char* const initial_content);

// Create a sstring_t pointing to the provided C string to the specified length.
sstring_t* sstring_new_sstring_shallow_oflength(char* initial_content, const sstring_size_t length);

// Create an sstring_t with clone of the provided C string to the specified length.
sstring_t* sstring_new_sstring_deep_oflength(const char* const initial_content, const sstring_size_t length);


//
// CLONING:

sstring_t* sstring_clone_shallow(const sstring_t* const origin);
sstring_t* sstring_clone_deep(const sstring_t* const origin);


//
// OTHER:

sstring_t* sstring_create_reverse_sstring(const sstring_t* const origin);


//
// DESTRUCTION:

void sstring_free(sstring_t* const s);

#endif // _SSTRING_H_
