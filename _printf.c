#include "main.h"
#include <stddef.h>
#include <stdarg.h>

/**
 * _printf - Implementation of _printf function
 * @format: Format string containing the text and format specifier
 * @...: Additional arguments to be formatted and printed
 * Return: The total number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list list;
    int printed_chars = 0;

    if (format == NULL || (format[0] == '%' && format[1] == '\0'))
        return (-1);

    va_start(list, format);

    for (; *format != '\0'; format++)
    {
        if (*format != '%')
        {
            sam_charwriter(*format);
            printed_chars++;
        }
        else
        {
            format++;

            if (*format == 'c')
            {
                char sam_ch = va_arg(list, int);
                sam_charwriter(sam_ch);
                printed_chars++;
            }
            else if (*format == '%')
            {
                sam_charwriter('%');
                printed_chars++;
            }
            else if (*format == 's')
            {
                printed_chars += sam_str_print(va_arg(list, char *));
            }
            else if (*format == 'd' || *format == 'i')
            {
                int sam_num = va_arg(list, int);
                printed_chars += Sam_negative(sam_num);
            }
        }
    }

    va_end(list);

    return (printed_chars);
}
