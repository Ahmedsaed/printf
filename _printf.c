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
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			i++;
			counter += evaluate_flag(format[i], args);
		}
		else
		{
			counter += printchar(format[i]);
		}
	}

	va_end(args);

	return (counter);
}
