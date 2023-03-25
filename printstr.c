#include "main.h"

/**
 * printstr - prints a string to stdio
 *
 * @s: pointer to a string of characters
 *
 * Return: Void
 */
void printstr(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		printchar(s[i]);
	}
}
