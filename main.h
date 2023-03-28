#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

/**
 * struct flags - struct to hold flags
 *
 * @show_sign: flag to show sign
 * @space: flag to show space
 * @left_align: flag to left align
 * @zero_pad: flag to zero pad
 * @show_base: flag to show base
 * @width: width of field
 * @precision: precision of field
 * @length_modifier: length modifier
 * @is_uint: flag to show unsigned
 *
 * Description: struct to hold flags
 */
typedef struct flags
{
	int show_sign;
	int space;
	int left_align;
	int zero_pad;
	int show_base;
	int width;
	int precision;
	int length_modifier;
	int is_uint;

} flags_t;

int _printf(const char *format, ...);
int handle_flags(const char *format, int *f_i,
				va_list args, char *buffer, int *b_i);
int handle_print(char specifier, va_list args,
				char *buffer, int *b_i, flags_t flags);
int print_char(char c, char *buffer,
			int *index, flags_t *flags);
int print_str(char *s, char *buffer,
			int *index, flags_t *flags);
int print_integer(va_list args, char *buffer,
					int *index, flags_t *flags);
unsigned int print_binary(unsigned int k, char *buffer,
				int *index, flags_t *flags);
unsigned int print_octal(unsigned long int k, char *buffer,
				int *index, flags_t *flags);
unsigned int print_hex(unsigned long int k, int char_case,
					char *buffer, int *index, flags_t *flags);
int print_address(void *p, char *buffer,
				int *index, flags_t *flags);
int print_non_printable(char *str, char *buffer,
				int *index, flags_t *flags);
flags_t get_flags(const char *format, int *f_i);
int flush_buffer(char buffer[], int *index);
char *convert(unsigned long int num, int base, int char_case);

#endif
