#include "main.h"

/**
 * printd - prints an integer
 * 
 * @n: integer to print
 * @count: pointer to integer
 * 
 * Return: void
 */
void print_integer(int n, int *count)
{
    unsigned int num;

    if (n < 0)
    {
        printchar('-');
        num = -n;
        (*count)++;
    }
    else
    {
        num = n;
    }

    if (num / 10)
    {
        print_integer(num / 10, count);
    }

    printchar((num % 10) + '0');
    (*count)++;
}