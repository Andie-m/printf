

#ifndef MAIN_H
#define MAIN_H
#define BUFF_SIZE 1024
#include <stdarg.h>

int sam_charwriter(char c);
int sam_str_print(char *buffer);
int Sam_negative(int num);
int kabelo_print_i(int num);
int _printf(const char *format, ...);

void handle_format(const char *format,...);
void handle_string(va_list list, int *printed_chars);
void handle_integer(va_list, int *printed_chars);

#endif /* MAIN_H */
