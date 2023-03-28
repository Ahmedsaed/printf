#include "main.h"

/**
 * print_integer - prints an integer
 *
 * @args: arguments list
 * @buffer: char array - buffer to print
 * @index: current index of buffer
 * @flags: struct containing flags data
 *
 * Return: int - count
 */
int print_integer(va_list args, char *buffer, int *index, flags_t *flags)
{
	long int count = 0, n;
	unsigned int n1;
	char *str;

	if (flags->length_modifier == 1 && flags->is_uint == 1)
		n = va_arg(args, unsigned long int);
	else if (flags->length_modifier == 1 && flags->is_uint == 0)
		n = va_arg(args, long int);
	else if (flags->length_modifier == 0 && flags->is_uint == 1)
		n = va_arg(args, unsigned int);
	else if (flags->length_modifier == 0 && flags->is_uint == 0)
		n = va_arg(args, int);
	else
		n = va_arg(args, int);

	if (n < 0)
	{
		count += print_char('-', buffer, index, flags);
		n1 = -n;
	}
	else if (n >= 0)
	{
		if (flags->show_sign)
			count += print_char('+', buffer, index, flags);
		else if (flags->space == 1 && flags->show_sign == 0)
			count += print_char(' ', buffer, index, flags);
		n1 = n;
	}

	str = convert(n1, 10, 0);

	count += print_str(str, buffer, index, flags);

	return (count);
}

/**
 * print_binary - prints a binary number
 *
 * @k: unsigned int
 * @buffer: char array - buffer to print
 * @index: current index of buffer
 * @flags: struct containing flags data
 *
 * Return: count - unsigned int
 */
unsigned int print_binary(unsigned int k, char *buffer,
						int *index, flags_t *flags)
{
	unsigned int count = 0;
	char *str;

	str = convert(k, 2, 0);

	count += print_str(str, buffer, index, flags);

	return (count);
}


/**
 * print_octal - prints an octal number
 *
 * @k: unsigned int
 * @buffer: char array - buffer to print
 * @index: current index of buffer
 * @flags: struct containing flags data
 *
 * Return: count - unsigned int
 */
unsigned int print_octal(unsigned long int k, char *buffer,
						int *index, flags_t *flags)
{
	unsigned int count = 0;
	char *str;

	str = convert(k, 8, 0);

	if (flags->show_base && str[0] != '0')
		count += print_char('0', buffer, index, flags);

	count += print_str(str, buffer, index, flags);

	return (count);
}

/**
 * print_hex - prints a hex number
 *
 * @k: unsigned int
 * @char_case: 0 for lowercase, 1 for uppercase
 * @buffer: char array - buffer to print
 * @index: current index of buffer
 * @flags: struct containing flags data
 *
 * Return: count - unsigned int
 */
unsigned int print_hex(unsigned long int k, int char_case, char *buffer,
					int *index, flags_t *flags)
{
	unsigned int count = 0;
	char *str;

	str = convert(k, 16, char_case);

	if (flags->show_base && str[0] != '0')
		count += print_str((char_case) ? "0X" : "0x",
							buffer, index, flags);

	count += print_str(str, buffer, index, flags);

	return (count);
}
