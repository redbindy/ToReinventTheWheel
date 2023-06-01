#include <assert.h>

#include "string.h"

unsigned int get_string_length(const char* str)
{
    const char* p_str = str;

    while (*p_str != '\0') {
        ++p_str;
    }

    return p_str - str;
}

int compare_string(const char* lhs, const char* rhs)
{
    const char* p_lhs = lhs;
    const char* p_rhs = rhs;

    while (*p_lhs != '\0' && *p_lhs == *p_rhs) {
        ++p_lhs;
        ++p_rhs;
    }

    return *p_lhs - *p_rhs;
}

int compare_n_string(const char* lhs, const char* rhs, const int count)
{
    const char* p_lhs = lhs;
    const char* p_rhs = rhs;

    while (*p_lhs != '\0' && *p_lhs == *p_rhs && p_lhs - lhs < count) {
        ++p_lhs;
        ++p_rhs;
    }

    return *p_lhs - *p_rhs;
}

char* copy_string(char* dest, const char* src)
{
    char* p_dest = dest;
    const char* p_src = src;

    while (*p_src != '\0') {
        *p_dest++ = *p_src++;
    }
    *p_dest = '\0';

    return dest;
}

char* copy_n_string(char* dest, const char* src, const int count)
{
    char* p_dest = dest;
    const char* p_src = src;

    while (*p_src != '\0' && p_src - src < count) {
        *p_dest++ = *p_src++;
    }
    *p_dest = '\0';

    return dest;
}

char* concat_string(char* dest, const char* src)
{
    char* p_dest = dest;

    while (*p_dest != '\0') {
        ++p_dest;
    }

    copy_string(p_dest, src);

    return dest;
}

char* concat_n_string(char* dest, const char* src, const int count)
{
    char* p_dest = dest;

    while (*p_dest != '\0') {
        ++p_dest;
    }

    copy_n_string(p_dest, src, count);

    return dest;
}

const char* has_string(const char* str, const char* substr)
{
    const char* p_str;

    if (*substr == '\0') {
        return str;
    }

    for (p_str = str; *p_str != '\0'; ++p_str) {
        
        const char* p_tmp_str = p_str;

        const char* p_substr = substr;

        while (*p_substr != '\0' && *p_substr == *p_tmp_str) {
            ++p_substr;
            ++p_tmp_str;
        }

        if (*p_substr == '\0') {
            return p_str;
        }
    }

    return NULL;
}

char* tokenize_string(char* strOrNull, const char* delims)
{
    static char* s_p_last_pos = NULL;
    char* p_ret_pos = NULL;

    int delims_map[128];
    const char* p_delims;

    if (strOrNull != NULL) {
        s_p_last_pos = strOrNull;
    } else if (s_p_last_pos == NULL || *s_p_last_pos == '\0') {
        return NULL;
    }

    p_ret_pos = s_p_last_pos;

    if (*p_ret_pos == '\0') {
        return NULL;
    }

    p_delims = delims;
    while (*p_delims != '\0') {
        delims_map[(int) (*p_delims++)] = 1;
    }

    while (*s_p_last_pos != '\0') {

        if (delims_map[(int) (*s_p_last_pos)] == 1) {
            *s_p_last_pos = '\0';

            ++s_p_last_pos;

            break;
        }

        ++s_p_last_pos;
    }

    return p_ret_pos;
}
