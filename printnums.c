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

	if (n < 0)
	{
		count += print_char('-', buffer, index);
		n1 = -n;
	}
	else
		n1 = n;

	if (n1 / 10)
		print_integer(n1 / 10, buffer, index);

	count += print_char((n1 % 10) + '0', buffer, index);

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

	if (k > 1)
		count += print_binary(k / 2, buffer, index);

	count += print_char((k % 2) + '0', buffer, index);

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

	if (k > 7)
		count += print_octal(k / 8, buffer, index);

	count += print_char((k % 8) + '0', buffer, index);

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

	if (k > 15)
		count += print_hex(k / 16, char_case, buffer, index);

	if (k % 16 < 10)
		count += print_char((k % 16) + '0', buffer, index);
	else if (char_case == 0)
		count += print_char((k % 16) + 'a' - 10, buffer, index);
	else
		count += print_char((k % 16) + 'A' - 10, buffer, index);

	return (count);
}
