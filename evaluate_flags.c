#include "main.h"

/**
 * evaluate_flag - evaluates print flags
 *
 * @flag: char
 * @args: arguments list
 *
 * Return: int
 */
int evaluate_flag(char flag, va_list args)
{
	int counter = 0;

	switch (flag)
	{
		case 'c':
			counter += printchar(va_arg(args, int));
			break;
		case 's':
			counter += printstr(va_arg(args, char *));
			break;
		case '%':
			counter += printchar('%');
			break;
		case 'd':
		case 'i':
			counter += print_integer(va_arg(args, int));
			break;
		case 'b':
			counter += print_integer(decimal_to_binary(va_arg(args, unsigned int)));
			break;
		default:
			counter += printchar('%');
			counter += printchar(flag);
			break;
	}

	return (counter);
}
