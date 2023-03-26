#include "main.h"

/**
 * printstr - prints a string to stdio
 *
 * @s: pointer to a string of characters
 *
 * Return: int count
 */
int printstr(char *s)
{
	int count = 0;

	while (*s)
	{
		printchar(*s);
		s++;
		count++;
	}

	return (count);
}

/**
 * printchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int printchar(char c)
{
	return (write(1, &c, 1));
}
