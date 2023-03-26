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
	int num;
	int count = 0;

	if (n < 0)
	{
		count += printchar('-');
		num = -n;
	}
	else
		num = n;

	if (num / 10)
		count += print_integer(num / 10);

	count += printchar((num % 10) + '0');

	return (count);
}
