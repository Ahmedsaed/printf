#include <limits.h>
#include <stdio.h>
#include "../main.h"

#define TEST_STRING 0
#define TEST_INTEGER 1
#define TEST_OTHER 0

void test_print_string(void);
void test_print_integer(void);
void test_print_other(void);

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
#if TEST_STRING == 1
	test_print_string();
#endif
#if TEST_INTEGER == 1
	test_print_integer();
#endif
#if TEST_OTHER == 1
	test_print_other();
#endif

	return (0);
}

/**
 * test_print_string - test print string
 *
 * Return: void
 */
void test_print_string(void)
{
	int len, len2;

	len = _printf("Let's try to printf a simple sentence.\n");
	len2 = printf("Let's try to printf a simple sentence.\n");
	printf("Length:[%d, %d]\n", len, len2);

	len = _printf("This sentence is 36 characters long\n");
	len2 = printf("This sentence is 36 characters long\n");
	printf("Length:[%d, %d]\n", len, len2);


	len = _printf("Percent:[%%]\n");
	len2 = printf("Percent:[%%]\n");
	printf("Length:[%d, %d]\n", len, len2);

	_printf("String:[%s]\n", "I am a string !");
	printf("String:[%s]\n", "I am a string !");

	_printf("Character:[%c]\n", 'H');
	printf("Character:[%c]\n", 'H');

	printf("%%\n");
	_printf("%%\n");
	printf("%%s\n", "hello");
	_printf("%%s\n", "hello");

	printf("%%c\n", 'a');
	_printf("%%c\n", 'a');

	printf("\"%s\"\n", "hello");
	_printf("\"%s\"\n", "hello");

	_printf("String:[%s]\n", NULL);
	printf("String:[%s]\n", NULL);
}

/**
 * test_print_integer - test print integer
 *
 * Return: void
 */
void test_print_integer(void)
{
	int len, len2;

	_printf("Negative:[%d]\n", -762534);
	printf("Negative:[%d]\n", -762534);

	_printf("Negative:[%i]\n", -76);
	printf("Negative:[%i]\n", -76);

	len2 = printf("Len: %d\n", 5);
	len = _printf("Len: %d\n", 5);
	printf("Len:[%d, %d]\n", len, len2);
}

/**
 * test_print_other - test print other
 *
 * Return: void
 */
void test_print_other(void)
{
	unsigned int ui;
	void *addr;

	ui = (unsigned int)INT_MAX + 1024;
	addr = (void *)0x7ffe637541f0;

	_printf("Unknown:[%r]\n");
	printf("Unknown:[%r]\n");
	_printf("%\n");
	printf("%\n");

	_printf("Unsigned:[%u]\n", ui);
	printf("Unsigned:[%u]\n", ui);
	_printf("Unsigned octal:[%o]\n", ui);
	printf("Unsigned octal:[%o]\n", ui);
	_printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
	printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);

	_printf("Address:[%p]\n", addr);
	printf("Address:[%p]\n", addr);
}
