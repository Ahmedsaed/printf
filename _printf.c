#include "main.h"

/**
 * _printf - prints formated strings to output stream
 *
 * @format: string of characters
 *
 * Return: int - number of characters printed (excluding the
 * null byte used to end output to strings)
 */
int _printf(const char *format, ...)
{
	int counter = 0, i;
	va_list args;

	va_start(args, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			counter += evaluate_flag(format[i], args);
		}
		else
		{
			counter++;
			_putchar(format[i]);
		}
	}

	va_end(args);

	return (counter);
}

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
	int j, counter = 1;
	char *s;

	switch (flag)
	{
		case 'c':
			_putchar(va_arg(args, int));
			break;
		case 's':
			s = va_arg(args, char *);

			for (j = 0; s[j] != '\0'; j++)
			{
				counter++;
				_putchar(s[j]);
			}

			counter--;
			break;
		case '%':
			_putchar('%');
			break;
		default:
			_putchar('%');
			_putchar(flag);
			break;
	}

	return (counter);
}
