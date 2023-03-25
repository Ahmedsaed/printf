#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
int _putchar(char c);
int _printf(const char *format, ...);
char *parser(const char * format, va_list args);
int arg_count(char *f);

#endif
