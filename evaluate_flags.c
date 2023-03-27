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

	if (flag == 'c')
		counter += print_char(va_arg(args, int), buffer, index);
	else if (flag == 's')
		counter += print_str(va_arg(args, char *), buffer, index);
	else if (flag == 'S')
		counter += print_non_printable(va_arg(args, char *), buffer, index);
	else if (flag == '%')
		counter += print_char('%', buffer, index);
	else if (flag == 'd' || flag == 'i')
		counter += print_integer(va_arg(args, int), buffer, index);
	else if (flag == 'u')
		counter += print_integer(va_arg(args, unsigned int), buffer, index);
	else if (flag == 'b')
		counter += print_binary(va_arg(args, unsigned int), buffer, index);
	else if (flag == 'o')
		counter += print_octal(va_arg(args, unsigned int), buffer, index);
	else if (flag == 'x')
		counter += print_hex(va_arg(args, unsigned int), 0, buffer, index);
	else if (flag == 'p')
		counter += print_address(va_arg(args, void *), buffer, index);
	else if (flag == 'X')
		counter += print_hex(va_arg(args, unsigned int), 1, buffer, index);
	else
	{
		counter += print_char('%', buffer, index);
		counter += print_char(flag, buffer, index);
	}


	return (counter);
}
