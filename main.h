#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <string.h>
#include <unistd.h>


int _printf(const char *format, ...);
ssize_t write_int(int fd, int a);
int str_len(char *v);
int _putchar(char c);

#endif /* MAIN_H */
