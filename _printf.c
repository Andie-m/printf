#include "main.h"
#include <stdarg.h>

int _printf(const char *format, ...) {
    va_list and;
    va_start(and, format);

    int akm = 0;
    while (*format != '\0') {
        if (*format == '%') {
            format++;
            switch (*format) {
                case 'c':
                    putchar(va_arg(and, int));
                    akm++;
                    break;
                case 's': 
                {
                    const char str = va_arg(and, const char );
                    while (*str != '\0') {
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
        } else {
            putchar(*format);
            akm++;
        }
        format++;
    }

    va_end(and);
    return akm;
}

int main() {
    _printf("Hello, %s! The answer is %d%c\n", "World", 42, '%');
    return 0;
}
