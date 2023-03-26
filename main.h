#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
int _printf(const char *format, ...);
int printchar(char c);
int evaluate_flag(char flag, va_list args);
void printstr(char *s, int *count);

#endif
