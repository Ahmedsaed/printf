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
			counter += handle_flags(format, &i, args, buffer, &buffer_index);
		else
			counter += print_char(format[i], buffer, &buffer_index, (void *)NULL);
	}

	counter += flush_buffer(buffer, &buffer_index);

	va_end(args);

	return (counter);
}

/**
 * handle_flags - evaluates print flags
 *
 * @format: string of characters to print
 * @f_i: index of format
 * @args: arguments list
 * @buffer: char array - buffer to print
 * @b_i: current index of buffer
 *
 * Return: int
 */
int handle_flags(const char *format, int *f_i,
				va_list args, char *buffer, int *b_i)
{
	int counter = 0;
	char specifier = format[++(*f_i)];
	flags_t flags = get_flags(format, f_i);

	specifier = format[(*f_i)];

	if (specifier == 'c')
		counter += print_char(va_arg(args, int), buffer, b_i, &flags);
	else if (specifier == 's')
		counter += print_str(va_arg(args, char *), buffer, b_i, &flags);
	else if (specifier == 'S')
		counter += print_non_printable(va_arg(args, char *), buffer, b_i, &flags);
	else if (specifier == '%')
		counter += print_char('%', buffer, b_i, &flags);
	else if (specifier == 'd' || specifier == 'i')
		counter += print_integer(va_arg(args, int), buffer, b_i, &flags);
	else if (specifier == 'u')
		counter += print_integer(va_arg(args, unsigned int), buffer, b_i, &flags);
	else if (specifier == 'b')
		counter += print_binary(va_arg(args, unsigned int), buffer, b_i, &flags);
	else if (specifier == 'o')
		counter += print_octal(va_arg(args, unsigned int), buffer, b_i, &flags);
	else if (specifier == 'x')
		counter += print_hex(va_arg(args, unsigned int), 0, buffer, b_i, &flags);
	else if (specifier == 'p')
		counter += print_address(va_arg(args, void *), buffer, b_i, &flags);
	else if (specifier == 'X')
		counter += print_hex(va_arg(args, unsigned int), 1, buffer, b_i, &flags);
	else
	{
		counter += print_char('%', buffer, b_i, &flags);
		counter += print_char(specifier, buffer, b_i, &flags);
	}

	return (counter);
}

/**
 * get_flags - gets the flags
 *
 * @format: string of characters to print
 * @f_i: index of format
 *
 * Return: flags_t
 */
flags_t get_flags(const char *format, int *f_i)
{
	flags_t flags;

	flags.show_sign = 0;
	flags.space = 0;
	flags.left_align = 0;
	flags.zero_pad = 0;
	flags.width = 0;
	flags.precision = 0;

	while (
		format[*f_i] == '+' ||
		format[*f_i] == ' ' ||
		format[*f_i] == '#'
	)
	{
		if (format[*f_i] == '+')
			flags.show_sign = 1;
		else if (format[*f_i] == ' ')
			flags.space = 1;
		else if (format[*f_i] == '#')
			flags.show_base = 1;

		(*f_i)++;
	}

	return (flags);
}
