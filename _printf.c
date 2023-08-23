#include "main.h"

/*
* _printf = my own printf
* @format = format string
* Return: number of characters printed to standard output
**/

int _printf(const char *format, ...)
{
int char_print = 0;
va_list arg_list;

if (format == NULL)
return (-1);

va_start(arg_list, format);
while (*format)
{
if (*format == '%')
{
format++;
if (*format  == '\0')
break;
char_print += handle_format(format, arg_list);
}
else
{
write(1, format, 1);
char_print++;
}
format++;
}
va_end(arg_list);
return (char_print);
}

/*
* handle_format = handle different format specifiers
* @format = pointer to the current character in the format string
* @arg_list = list of arguments
* Return: number of characters printed for the current specifier
**/

int handle_format(const char *format, va_list arg_list)
{
switch (*format)
{
case '%':
write(1, format, 1);
return (1);
case 'c':
return (print_char(va_arg(arg_list, int)));
case 's':
return (print_string(va_arg(arg_list, char*)));
default:
write(1, format - 1, 2);
return (2);
}
}

/*
* print_char = print a single character
* @c = character to print
* Return: number of characters printed (always 1)
**/

int print_char(char c)
{
write(1, &c, 1);
return (1);
}

/*
* print_string = print a string or "(null)" if NULL
* @str = string to print
* Return: number of characters printed
**/

int print_string(char *str)
{
int len = 0;

if (str == NULL)
str = "(null)";

while (*str)
{
write(1, str, 1);
len++;
str++;
}
return (len);
}
