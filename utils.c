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
