// Nolan Holden
// 12 OCT 2017

#include <stdio.h>
#include "sstring.h"
#include "sstring_util.h"


void main_method1(void);
void main_method2(void);

int main(void) {
  main_method1();
  main_method2();
  return 0;
}

void main_method1(void) {
  const char* content = "Johnathon";
  const int john_length = 9;

  printf(content);
  char buffer[john_length];
  sstring_create_reverse_cstring(content, john_length, buffer);
  printf("\n\n");
  buffer[john_length] = '\0';
  printf(buffer);
}

void main_method2(void) {
  char* text = "Johnathon";
  const int john_length = 9;
  sstring_t* john = (sstring_t*)malloc(sizeof(sstring_t));
  john->c_string = text;
  sstring_t* john2 = sstring_create_reverse_sstring(john);
  
  printf("\n\n");
  printf(john->c_string);
  //printf(john2->c_string);
}