#ifndef STRING_H
#define STRING_H

unsigned int get_string_length(const char* str);
int compare_string(const char* lhs, const char* rhs);
int compare_n_string(const char* lhs, const char* rhs, const int count);
char* copy_string(char* dest, const char* src);
char* copy_n_string(char* dest, const char* src, const int count);
char* concat_string(char* dest, const char* src);
char* concat_n_string(char* dest, const char* src, const int count);
const char* has_string(const char* str, const char* substr);
char* tokenize_string(char* strOrNull, const char* delims);

#endif /* STRING_H */
