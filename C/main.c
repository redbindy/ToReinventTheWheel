#define _CRT_SECURE_NO_WARNINGS

#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "DataStructure/string.h"
#include "DataStructure/my_string.h"

enum {
    CAPACITY = 16
};

int main(void)
{
    string_t str1 = get_string_malloc("", 10);
    string_t str2 = get_string_malloc("Hello World!", 10);
    string_t str3 = get_string_malloc("long long long long very long", 10);

    string_t interleaved;
    string_t interleaved1;
    string_t interleaved2;

    printf("S: %s\n  C: %d\n  L: %d\n\n", str1.pa_str, str1.capacity, str1.length);
    printf("S: %s\n  C: %d\n  L: %d\n\n", str2.pa_str, str2.capacity, str2.length);
    printf("S: %s\n  C: %d\n  L: %d\n\n", str3.pa_str, str3.capacity, str3.length);

    interleaved = interleave_malloc(&str1, &str2);
    interleaved1 = interleave_malloc(&str1, &str3);
    interleaved2 = interleave_malloc(&str2, &str3);

    printf("S: %s\n  C: %d\n  L: %d\n\n", interleaved.pa_str, interleaved.capacity, interleaved.length);
    printf("S: %s\n  C: %d\n  L: %d\n\n", interleaved1.pa_str, interleaved1.capacity, interleaved1.length);
    printf("S: %s\n  C: %d\n  L: %d\n\n", interleaved2.pa_str, interleaved2.capacity, interleaved2.length);

    destroy_string(&str1);
    destroy_string(&str2);
    destroy_string(&str3);

    destroy_string(&interleaved);
    destroy_string(&interleaved1);
    destroy_string(&interleaved2);

    return 0;
}

