#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _printf(const char *format, ...);

typedef struct format_handler
{
char specifier;
int (*handler)(va_list);
} format_handler_t;

#endif /* MAIN_H */
