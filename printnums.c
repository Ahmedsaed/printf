#include "main.h"

/**
 * print_integer - prints an integer
 *
 * @n: integer to print
 *
 * Return: int count
 */
int print_integer(int n)
{
	unsigned int n1;
	int count = 0;

	if (n < 0)
	{
		count += printchar('-');
		n1 = -n;
	}
	else
		n1 = n;

	if (n1 / 10)
		count += print_integer(n1 / 10);

	count += printchar((n1 % 10) + '0');

	return (count);
}

/**
 * print_binary - prints a binary number
 *
 * @k: unsigned int
 *
 * Return: count - unsigned int
 */
unsigned int print_binary(unsigned int k)
{
	unsigned int count = 0;

	if (k > 1)
		count += print_binary(k / 2);

	count += printchar((k % 2) + '0');

	return (count);
}


/**
 * print_octal - prints an octal number
 *
 * @k: unsigned int
 *
 * Return: count - unsigned int
 */
unsigned int print_octal(unsigned int k)
{
	unsigned int count = 0;

	if (k > 7)
		count += print_octal(k / 8);

	count += printchar((k % 8) + '0');

	return (count);
}

/**
 * print_hex - prints a hex number
 *
 * @k: unsigned int
 *
 * Return: count - unsigned int
 */
unsigned int print_hex(unsigned int k)
{
	unsigned int count = 0;

	if (k > 15)
		count += print_hex(k / 16);

	if ((k % 16) < 10)
		count += printchar((k % 16) + '0');
	else
		count += printchar((k % 16) + 'a' - 10);

	return (count);
}
