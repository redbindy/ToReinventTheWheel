#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "my_string.h"

enum {
    DEFAULT_CAPACITY = 16
};

string_t get_string_malloc(const char* chars, const unsigned int capacity)
{
    string_t string;

    assert(chars != NULL);

    string.length = get_string_length(chars);

    if (string.length >= capacity) {

        if (string.length == 0) {
            string.capacity = DEFAULT_CAPACITY;
        } else {
            string.capacity = string.length << 1;
        }
    } else {
        string.capacity = capacity;
    }

    string.pa_str = malloc(sizeof(char) * string.capacity);

    copy_string(string.pa_str, chars);

    return string;
}

void destroy_string(string_t* string)
{
    free(string->pa_str);
  
    string->pa_str = NULL;
    string->length = -1;
    string->capacity = -1;
}

void reverse_string(string_t* string)
{
    char* p_front;
    char* p_back;

    assert(string != NULL);

    p_front = string->pa_str;
    p_back = string->pa_str + string->length - 1;

    while (p_front < p_back) {

        char tmp = *p_front;
        *p_front = *p_back;
        *p_back = tmp;

        ++p_front;
        --p_back;
    }
}

string_t interleave_malloc(string_t* str1, string_t* str2)
{
    string_t result;
    char* p_result_str;

    const char* p_str1;
    const char* p_str2;

    assert(str1 != NULL && str2 != NULL);

    result.length = str1->length + str2->length;
    result.capacity = result.length << 1;

    result.pa_str = malloc(result.capacity);
    p_result_str = result.pa_str;

    p_str1 = str1->pa.str;
    p_str2 = str2->pa.str;

    while (*p_str1 != '\0' && *p_str2 != '\0') {
        *p_result_str++ = *p_str1++;
        *p_result_str++ = *p_str2++;
    }

    while (*p_str1 != '\0') {
        *p_result_str++ = *p_str1++;
    }

    while (*p_str2 != '\0') {
        *p_result_str++ = *p_str2++;
    }
    *p_result_str = '\0';

    return result;
}

void append(string_t* str, const string_t* str2)
{
    char* p_str;
}