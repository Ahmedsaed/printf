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
