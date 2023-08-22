#include <stdio.h>
#include <stdarg.h>
#include <main.h>
/**
 * _printf - Custom printf function with limited format specifiers.
 * @format: The format string containing directives.
 * @...: Variable number of and for the directives.
 *
 * This function prints output according to the provided format string,
 * handling the following conversion specifiers: %c, %s, and %%.
 *
 * Return: The number of characters printed (excluding the null byte used
 *         to end output to strings).
 */
int _printf(const char *format, ...)
{
va_list and;
va_start(and, format);
int akm = 0;
while (*format != '\0')
{
if (*format == '%')
{
format++;
switch (*format)
{
case 'c':
putchar(va_arg(and, int));
akm++;
break;
case 's':
{
const char *str = va_arg(and, const char *);
while (*str != '\0')
{
putchar(*str);
str++;
akm++;
}
break;
}
case '%':
putchar('%');
akm++;
break;
}
}
else
{
putchar(*format);
akm++;
}
format++;
}
va_end(and);
return (akm);
}
/**
 * main - this main
 * Return:(0) success
 */
int main(void)
{
_printf("Hello, %s! The answer is %d%c\n", "World", 42, '%');
return (0);
}

