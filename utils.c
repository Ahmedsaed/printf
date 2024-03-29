#include "main.h"

/**
 * convert - converts a number to a given base
 *
 * @num: number to convert
 * @base: base to convert to
 * @char_case: 0 for lowercase, 1 for uppercase
 *
 * Return: char * - converted number
 */
char *convert(unsigned long int num, int base, int char_case)
{
	static char *rep;
	static char buf[50];
	char *ptr;

	ptr = &buf[49];
	*ptr = '\0';

	if (char_case == 0)
		rep = "0123456789abcdef";
	else
		rep = "0123456789ABCDEF";

	do {
		*--ptr = rep[num % base];
		num /= base;
	} while (num != 0);

	return (ptr);
}

/**
 * flush_buffer - flushes the buffer
 *
 * @buffer: char array - buffer to print
 * @index: current index of buffer
 *
 * Return: int - number of characters printed
 */
int flush_buffer(char buffer[], int *index)
{
	int count = *index;

	write(1, buffer, *index);
	(*index) = 0;

	return (count);
}

/**
 * init_flags - initializes flags struct
 *
 * @flags: struct containing flags data
 *
 * Return: void
 */
void init_flags(flags_t *flags)
{
	flags->show_sign = 0;
	flags->show_base = 0;
	flags->space = 0;
	flags->left_align = 0;
	flags->length_modifier = 0;
	flags->zero_pad = 0;
	flags->width = 0;
	flags->is_uint = 0;
	flags->precision = 0;
}
