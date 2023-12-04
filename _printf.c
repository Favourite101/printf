#include <stdarg.h>
#include <stdio.h>

/**
 * _printf - prints anything
 * @format: list of argument types passed to the function
 * 
 * Return: number of characters printed
 */
int _printf(const char* format, ...) {
    int count;

    va_list input;
    va_start(input, format);

    count = 0;
    while (*format != '\0') {
        count++;
        if (*format == '%') {
            format++;
            switch (*format) {
                case 's': {
                    char* st = va_arg(input, char*);
                    printf("%s", st);
                    break;
                }
                case 'c': {
                    char ch = va_arg(input, int);
                    printf("%c", ch);
                    break;
                }
                default:
                    putchar(*format);
            }
        } else {
            putchar(*format);
        }

        format++;
    }

    va_end(input);

    return(count);
}
