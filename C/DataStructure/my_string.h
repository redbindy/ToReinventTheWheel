#ifndef MY_STRING_H
#define MY_STRING_H

#include "string.h"

typedef struct {

    char* pa_str;
    
    unsigned int capacity;
    unsigned int length;

} string_t;

string_t get_string_malloc(const char* chars, const unsigned int capacity);
void destroy_string(string_t* string);
void reverse_string(string_t* string);
string_t interleave_malloc(string_t* str1, string_t* str2);

#endif /* MY_STRING_H */
