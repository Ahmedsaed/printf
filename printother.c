#include "main.h"

/**
 * print_address - prints the address of a pointer
 *
 * @p: pointer to print
 * @buffer: char array - buffer to print
 * @index: current index of buffer
 *
 * Return: int - count
 */
int print_address(void *p, char *buffer, int *index)
{
	int count = 0;
	unsigned long int address = (unsigned long int)p;
	char *hex;

	if (p == NULL)
		return (print_str("(nil)", buffer, index));

	hex = convert(address, 16, 0);

	count += print_char('0', buffer, index);
	count += print_char('x', buffer, index);
	count += print_str(hex, buffer, index);

	return (count);
}
