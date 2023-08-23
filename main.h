

#ifndef MAIN_H
#define MAIN_H
#define BUFF_SIZE 1024
#include <stdarg.h>

int andie_charwriter(char c);
int andie_str_print(char *buffer);
int andie_negative(int num);
int muthukumi_print_i(int num);
int _printf(const char *format, ...);

void handle_format(const char *format,...);
void handle_string(va_list list, int *printed_chars);
void handle_integer(va_list, int *printed_chars);

#endif /* MAIN_H */
