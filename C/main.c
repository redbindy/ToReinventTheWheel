#define _CRT_SECURE_NO_WARNINGS

#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "DataStructure/string.h"

int main(void)
{
    char str1[] = "apple,banana,cherry";
    char str2[] = "one|two|three|four|five";
    char str3[] = "white space token|other-token|another-token";
    char str4[] = "";
    char str5[] = "token1";

    const char delims1[] = ",";
    const char delims2[] = "|";
    const char delims3[] = " ";

    char* token1;
    char* token2;
    char* token3;
    char* token4;
    char* token5;
    char* token6;
    char* token7;
    char* token8;
    char* token9;
    char* token10;
    char* token11;
    char* token12;
    char* token13;
    char* token14;
    char* token15;
    char* token16;
    char* token17;
    char* token18;
    char* token19;


    // Test 1
    token1 = tokenize_string(str1, delims1);
    assert(strcmp(token1, "apple") == 0);

    // Test 2
    token2 = tokenize_string(NULL, delims1);
    assert(strcmp(token2, "banana") == 0);

    // Test 3
    token3 = tokenize_string(NULL, delims1);
    assert(strcmp(token3, "cherry") == 0);

    // Test 4
    token4 = tokenize_string(NULL, delims1);
    assert(token4 == NULL);

    // Test 5
    token5 = tokenize_string(str2, delims2);
    assert(strcmp(token5, "one") == 0);

    // Test 6
    token6 = tokenize_string(NULL, delims2);
    assert(strcmp(token6, "two") == 0);

    // Test 7
    token7 = tokenize_string(NULL, delims2);
    assert(strcmp(token7, "three") == 0);

    // Test 8
    token8 = tokenize_string(NULL, delims2);
    assert(strcmp(token8, "four") == 0);

    // Test 9
    token9 = tokenize_string(NULL, delims2);
    assert(strcmp(token9, "five") == 0);

    // Test 10
    token10 = tokenize_string(NULL, delims2);
    assert(token10 == NULL);

    // Test 11
    token11 = tokenize_string(str3, delims3);
    assert(strcmp(token11, "white") == 0);

    // Test 12
    token12 = tokenize_string(NULL, delims3);
    assert(strcmp(token12, "space") == 0);

    // Test 13
    token13 = tokenize_string(NULL, delims3);
    assert(strcmp(token13, "token") == 0);

    // Test 14
    token14 = tokenize_string(NULL, delims3);
    assert(strcmp(token14, "other-token") == 0);

    // Test 15
    token15 = tokenize_string(NULL, delims3);
    assert(strcmp(token15, "another-token") == 0);

    // Test 16
    token16 = tokenize_string(NULL, delims3);
    assert(token16 == NULL);

    // Test 17
    token17 = tokenize_string(str4, delims1);
    printf("%s", token17);
    assert(token17 == NULL);

    // Test 18
    token18 = tokenize_string(str5, delims1);
    assert(strcmp(token18, "token1") == 0);

    // Test 19
    token19 = tokenize_string(NULL, delims1);
    assert(token19 == NULL);

    printf("All tests passed successfully!\n");

    return 0;

    return 0;
}

