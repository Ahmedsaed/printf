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
	int counter = 1;
	char *s;

	switch (flag)
	{
		case 'c':
			printchar(va_arg(args, int));
			break;
		case 's':
			s = va_arg(args, char *);

			if (s == NULL)
				s = "(null)";

			counter += printstr(s);

			counter--;
			break;
		case '%':
			printchar('%');
			break;
		case 'd':
		case 'i':
			counter += print_integer(va_arg(args, int));
			counter--;
			break;
		default:
			printchar('%');
			printchar(flag);
			break;
	}

	return (counter);
}
