#include "main.h"

/**
 * printstr - prints a string to stdio
 *
 * @s: pointer to a string of characters
 * @count: pointer to integer
 * Return: Void
 */
void printstr(char *s, int *count)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		(*count)++;
		printchar(s[i]);
	}
}
