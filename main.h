#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <string.h>
#include <unistd.h>


int _printf(const char *format, ...);
ssize_t write_int(int fd, int a);

#endif
