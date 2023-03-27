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

	hex = convert(address, 16, 0);

	count += print_char('0', buffer, index);
	count += print_char('x', buffer, index);
	count += print_str(hex, buffer, index);

	return (count);
}

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
	static char buffer[50];
	char *ptr;

	ptr = &buffer[49];
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
