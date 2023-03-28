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
	int counter = 0, i, buffer_index = 0;
	va_list args;
	char buffer[1024];

	va_start(args, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			i++;
			counter += evaluate_flag(format[i], args, buffer, &buffer_index);
		}
		else
		{
			counter += print_char(format[i], buffer, &buffer_index);
		}
	}

	counter += flush_buffer(buffer, &buffer_index);

	va_end(args);

	return (counter);
}

/**
 * flush_buffer - flushes the buffer
 *
 * @buffer: char array - buffer to print
 * @index: current index of buffer
 *
 * Return: int - number of characters printed
 */
int flush_buffer(char buffer[], int *index)
{
	int count = *index;

	write(1, buffer, *index);
	(*index) = 0;

	return (count);
}
