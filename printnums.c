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
 * decimal_to_binary - returns the binary representation of a number
 *
 * @k: number to convert
 * Return: binary representation of k
 */
unsigned int decimal_to_binary(unsigned int k)
{
	if (k == 0)
		return (0);
	if (k == 1)
		return (1);
	return ((k % 2) + 10 * decimal_to_binary(k / 2));
}
