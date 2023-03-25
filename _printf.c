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
    int counter = 0, i, j;
    va_list args;
    char *s;

    va_start(args, format);

    for (i = 0; format[i] != '\0'; i++)
    {
        if (format[i] == '%')
        {
            i++;
            switch (format[i])
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
            }
            
        }
        else
        {
            _putchar(format[i]);
        }
        
        counter++;
    }

    va_end(args);

    return counter;
}

/**
 * parser - returns evaluated string
 * 
 * @format: string - unformatted string
 * @args: arguments list 
 *
 * Return: char 
char *parser(const char * f, va_list args)
{
    int i;
    char *s
    
    for (i = 0; f[i] != '\0'; i++)
    {
        
    }
    return ("Test");
}
 */

/**
* arg_count - returns number of arguments needed
* 
* @format: string of characters
*
* Return: int
int arg_count(char *f)
{
    int counter = 0, i;

    for (i = 0; f[i] != '\0'; i++)
    {
        if(f[i] == '%')
            counter += 1;
    }

    return (counter);
}
*/
