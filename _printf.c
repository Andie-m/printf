#include "main.h"
#include <unistd.h>

/**
* _putchar - writes a character to stdout
* @c: the character to write
* Return: 1 on success, -1 on error
*/
int _putchar(char c)
{
return (write(1, &c, 1));
}

/**
* print_char - prints a char argument
* @args: the argument list
* Return: the number of characters printed
*/
int print_char(va_list args)
{
char c;

c = va_arg(args, int);
_putchar(c);
return (1);
}

/**
* print_string - prints a string argument
* @args: the argument list
* Return: the number of characters printed
*/
int print_string(va_list args)
{
char *s;
int i, len;

s = va_arg(args, char *);
if (s == NULL)
s = "(null)";
len = 0;
for (i = 0; s[i] != '\0'; i++)
{
_putchar(s[i]);
len++;
}
return (len);
}

/**
* print_percent - prints a percent sign
* @args: the argument list
* Return: the number of characters printed
*/
int print_percent(va_list args)
{
(void)args;
_putchar('%');
return (1);
}

/**
* _printf - produces output according to a format
* @format: the format string
* Return: the number of characters printed
*/
int _printf(const char *format, ...)
{
va_list args;
int i, j, len;
format_handler_t handlers[] = {
{'c', print_char},
{'s', print_string},
{'%', print_percent},
{0, NULL}
};

if (format == NULL)
return (-1);

va_start(args, format);
len = 0;
for (i = 0; format[i] != '\0'; i++)
{
if (format[i] == '%')
{
if (format[i + 1] == '\0')
return (-1);
for (j = 0; handlers[j].specifier != 0; j++)
{
if (format[i + 1] == handlers[j].specifier)
{
len += handlers[j].handler(args);
i++;
break;
}
}
if (handlers[j].specifier == 0)
{
_putchar(format[i]);
len++;
}
}
else
{
_putchar(format[i]);
len++;
}
}
va_end(args);
return (len);
}
#include "main.h"
#include <stdio.h>

int main(void)
{
int len1, len2;

len1 = _printf("Hello %s!\n", "world");
len2 = printf("Hello %s!\n", "world");

_printf("My printf: %d\n", len1);
printf("Standard printf: %d\n", len2);

return (0);
}
