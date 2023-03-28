#include "main.h"

/**
 * print_address - prints the address of a pointer
 *
 * @p: pointer to print
 * @buffer: char array - buffer to print
 * @index: current index of buffer
 * @flags: struct containing flags data
 *
 * Return: int - count
 */
int print_address(void *p, char *buffer, int *index, flags_t *flags)
{
	int count = 0;
	unsigned long int address = (unsigned long int)p;
	char *hex;

	if (p == NULL)
		return (print_str("(nil)", buffer, index, flags));

	hex = convert(address, 16, 0);

	count += print_char('0', buffer, index, flags);
	count += print_char('x', buffer, index, flags);
	count += print_str(hex, buffer, index, flags);

	return (count);
}

/**
 * print_ROT13 - prints in an encoding method
 *
 * @s: pointer to a string of characters
 * @buffer: char array - buffer to print
 * @index: current index of buffer
 * @flags: struct containing flags data
 *
 * Return: int - count
 */
int print_ROT13(char *s, char *buffer, int *index, flags_t *flags)
{
	char *rot13 = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char *ROT13 = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	int i, j, count = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] < 'A' || s[i] > 'z' || (s[i] > 'Z' && s[i] < 'a'))
			count += print_char(s[i], buffer, index, flags);
		else
		{
			for (j = 0; j < 53; j++)
			{
				if (s[i] == rot13[j])
					count += print_char(ROT13[j], buffer, index, flags);
			}
		}
	}

	return (count);
}
