#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int _printf(const char *format, ...);
int evaluate_flag(char flag, va_list args, char *buffer, int *index);
int print_char(char c, char *buffer, int *index);
int print_str(char *s, char *buffer, int *index);
int print_integer(long int n, char *buffer, int *index);
unsigned int print_binary(unsigned int k, char *buffer, int *index);
unsigned int print_octal(unsigned int k, char *buffer, int *index);
unsigned int print_hex(unsigned int k, int char_case, char *buffer, int *index);
int flush_buffer(char buffer[], int *index);

#endif
