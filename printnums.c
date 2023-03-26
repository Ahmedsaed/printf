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
	int count = 0;

	if (n < 0)
	{
		count += printchar('-');
		n = -n;
	}

	if (n / 10)
		count += print_integer(n / 10);

	count += printchar(n % 10 + '0');

	return (count);
}
