#include <stdarg.h>
#include <stdio.h>

int _printf(const char* format, ...) {
    int count;

    va_list args;
    va_start(args, format);

    count = 0;
    while (*format != '\0') {
        count++;
        if (*format == '%') {
            format++;
            switch (*format) {
                // case 'd': {
                //     int num = va_arg(args, int);
                //     printf("%d", num);
                //     break;
                // }
                // case 'f': {
                //     double num = va_arg(args, double);
                //     printf("%f", num);
                //     break;
                // }
                case 's': {
                    char* str = va_arg(args, char*);
                    printf("%s", str);
                    break;
                }
                case 'c': {
                    char ch = va_arg(args, int);
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

    va_end(args);

    return(count);
}
