#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
int _printf(const char *format, ...);
int printchar(char c);
int evaluate_flag(char flag, va_list args);
int printstr(char *s);
int print_integer(int n);

#endif
