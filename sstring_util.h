#ifndef _SSTRING_UTIL_H_
#define _SSTRING_UTIL_H_

// Get the length of the provided null-terminated string, not including the 
// null-terminator.
int sstring_util_strlen(const char* const input);

// Copy the characters from origin to target for the specified number of octets.
void sstring_util_strcpy(const char* const origin, char* target, int num_chars);

void sstring_swap_octet_pointers(const char* a, const char* b);
void sstring_swap_octet_values(char* const a, char* const b);

// Copies the string, starting at the specified pointer, for the length provided.
// This function is agnostic to null terminators, and does not provide a null
// terminator in the output.
void sstring_create_reverse_cstring(const char* const cstring, int length, char* const buffer);

#endif // _SSTRING_UTIL_H_
