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
	char *s;

	switch (flag)
	{
		case 'c':
			counter += printchar(va_arg(args, int));
			break;
		case 's':
			s = va_arg(args, char *);

			if (s == NULL)
				s = "(null)";

			counter += printstr(s);
			break;
		case '%':
			counter += printchar('%');
			break;
		case 'd':
		case 'i':
			counter += print_integer(va_arg(args, int));
			break;
		default:
			counter += printchar('%');
			counter += printchar(flag);
			break;
	}

	return (counter);
}
