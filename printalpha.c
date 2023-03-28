#include "main.h"

/**
 * print_str - prints a string to stdio
 *
 * @s: pointer to a string of characters
 * @buffer: char array - buffer to print
 * @index: current index of buffer
 *
 * Return: int - count
 */
int print_str(char *s, char *buffer, int *index)
{
	int i, count = 0;

	if (s == NULL)
		s = "(null)";

	for (i = 0; s[i] != '\0'; i++)
	{
		count += print_char(s[i], buffer, index);
	}

	return (count);
}

/**
 * print_char - writes the character c to stdout
 *
 * @c: The character to print
 * @buffer: char array - buffer to print
 * @index: current index of buffer
 *
 * Return: int - count
 */
int print_char(char c, char *buffer, int *index)
{
	int count = 0;

	buffer[*index] = c;
	(*index)++;

	if (*index == 1024)
	{
		count += flush_buffer(buffer, index);
	}

	return (count);
}

/**
 * print_non_printable - prints non printable characters
 *
 * @str: string to print
 * @buffer: char array - buffer to print
 * @index: current index of buffer
 *
 * Return: int - count
 */
int print_non_printable(char *str, char *buffer, int *index)
{
	int i, count = 0;
	char *hex = "0123456789ABCDEF";

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			count += print_char('\\', buffer, index);
			count += print_char('x', buffer, index);
			count += print_char(hex[str[i] / 16], buffer, index);
			count += print_char(hex[str[i] % 16], buffer, index);
		}
		else
		{
			count += print_char(str[i], buffer, index);
		}
	}

	return (count);
}
