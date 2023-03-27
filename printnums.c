#include "main.h"

/**
 * print_integer - prints an integer
 *
 * @n: integer to print
 * @buffer: char array - buffer to print
 * @index: current index of buffer
 *
 * Return: int - count
 */
int print_integer(long int n, char *buffer, int *index)
{
	int count = 0;
	unsigned int n1;
	char *str;

	if (n < 0)
	{
		count += print_char('-', buffer, index);
		n1 = -n;
	}
	else
		n1 = n;

	str = convert(n1, 10, 0);

	count += print_str(str, buffer, index);

	return (count);
}

/**
 * print_binary - prints a binary number
 *
 * @k: unsigned int
 * @buffer: char array - buffer to print
 * @index: current index of buffer
 *
 * Return: count - unsigned int
 */
unsigned int print_binary(unsigned int k, char *buffer, int *index)
{
	unsigned int count = 0;
	char *str;

	str = convert(k, 2, 0);

	count += print_str(str, buffer, index);

	return (count);
}


/**
 * print_octal - prints an octal number
 *
 * @k: unsigned int
 * @buffer: char array - buffer to print
 * @index: current index of buffer
 *
 * Return: count - unsigned int
 */
unsigned int print_octal(unsigned int k, char *buffer, int *index)
{
	unsigned int count = 0;
	char *str;

	str = convert(k, 8, 0);

	count += print_str(str, buffer, index);

	return (count);
}

/**
 * print_hex - prints a hex number
 *
 * @k: unsigned int
 * @char_case: 0 for lowercase, 1 for uppercase
 * @buffer: char array - buffer to print
 * @index: current index of buffer
 *
 * Return: count - unsigned int
 */
unsigned int print_hex(unsigned int k, int char_case, char *buffer, int *index)
{
	unsigned int count = 0;
	char *str;

	str = convert(k, 16, char_case);

	count += print_str(str, buffer, index);

	return (count);
}
