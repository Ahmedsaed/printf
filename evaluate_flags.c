#include "main.h"

/**
 * evaluate_flag - evaluates print flags
 *
 * @flag: char
 * @args: arguments list
 * @buffer: char array - buffer to print
 * @index: current index of buffer
 *
 * Return: int
 */
int evaluate_flag(char flag, va_list args, char *buffer, int *index)
{
	int counter = 0;

	switch (flag)
	{
		case 'c':
			counter += print_char(va_arg(args, int), buffer, index);
			break;
		case 's':
			counter += print_str(va_arg(args, char *), buffer, index);
			break;
		case '%':
			counter += print_char('%', buffer, index);
			break;
		case 'd':
		case 'i':
			counter += print_integer(va_arg(args, int), buffer, index);
			break;
		case 'u':
			counter += print_integer(va_arg(args, unsigned int), buffer, index);
			break;
		case 'b':
			counter += print_binary(va_arg(args, unsigned int), buffer, index);
			break;
		case 'o':
			counter += print_octal(va_arg(args, unsigned int), buffer, index);
			break;
		case 'x':
			counter += print_hex(va_arg(args, unsigned int), 0, buffer, index);
			break;
		case 'X':
			counter += print_hex(va_arg(args, unsigned int), 1, buffer, index);
			break;
		default:
			counter += print_char('%', buffer, index);
			counter += print_char(flag, buffer, index);
			break;
	}

	return (counter);
}
