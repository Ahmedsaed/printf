#include <limits.h>
#include <stdio.h>
#include "../main.h"

#define TEST_ALL 0
#define TEST_NUMERIC 0
#define TEST_STRING 0
#define TEST_INTEGER 0
#define TEST_OTHER 0
#define TEST_BINARY 0
#define TEST_OCTAL 0
#define TEST_HEX 0
#define TEST_UNSIGNED 0
#define TEST_FLAGS 0
#define TEST_REVERSE 0
#define TEST_ROTATION 1

/* Function Prototypes */
void test_print_string(void);
void test_print_integer(void);
void test_print_other(void);
void test_print_binary(void);
void test_print_octal(void);
void test_print_hex(void);
void test_print_uint(void);
void test_print_flags(void);
void test_print_reverse(void);
void test_print_rotation(void);

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
#if TEST_ALL || TEST_STRING
	printf("\n\nTesting string: \n");
	test_print_string();
#endif
#if TEST_ALL || TEST_INTEGER || TEST_NUMERIC
	printf("\n\nTesting integer: \n");
	test_print_integer();
#endif
#if TEST_ALL || TEST_BINARY || TEST_NUMERIC
	printf("\n\nTesting binary: \n");
	test_print_binary();
#endif
#if TEST_ALL || TEST_OCTAL || TEST_NUMERIC
	printf("\n\nTesting octal: \n");
	test_print_octal();
#endif
#if TEST_ALL || TEST_HEX || TEST_NUMERIC
	printf("\n\nTesting hex: \n");
	test_print_hex();
#endif
#if TEST_ALL || TEST_UNSIGNED || TEST_NUMERIC
	printf("\n\nTesting unsigned: \n");
	test_print_uint();
#endif
#if TEST_ALL || TEST_OTHER
	printf("\n\nTesting other: \n");
	test_print_other();
#endif
#if TEST_ALL || TEST_FLAGS
	printf("\n\nTesting flags: \n");
	test_print_flags();
#endif
#if TEST_ALL || TEST_REVERSE
	printf("\n\nTesting reverse: \n");
	test_print_reverse();
#endif
#if TEST_ALL || TEST_ROTATION
	printf("\n\nTesting rotation: \n");
	test_print_rotation();
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

	len = _printf("String:[%s]\n", "I am a string !");
	len2 = printf("String:[%s]\n", "I am a string !");
	printf("Length:[%d, %d]\n", len, len2);

	len = _printf("Character:[%c]\n", 'H');
	len2 = printf("Character:[%c]\n", 'H');
	printf("Length:[%d, %d]\n", len, len2);

	len = _printf("");
	len2 = printf("");
	printf("Length:[%d, %d]\n", len, len2);

	len = _printf("%s", "");
	len2 = printf("%s", "");
	printf("Length:[%d, %d]\n", len, len2);

	len = _printf("%c", '\n');
	len2 = printf("%c", '\n');
	printf("Length:[%d, %d]\n", len, len2);

	printf("%%\n");
	_printf("%%\n");
	printf("%%%s\n", "hello");
	_printf("%%%s\n", "hello");

	printf("%%c\n", 'a');
	_printf("%%c\n", 'a');

	printf("\"%s\"\n", "hello");
	_printf("\"%s\"\n", "hello");

	_printf("String:[%s]\n", NULL);
	printf("String:[%s]\n", NULL);

	len = _printf("String:[%s]\n", "hallo\nWorld");
	len2 = printf("String:[%s]\n", "hallo\nWorld");
	printf("Length:[%d, %d]\n", len, len2);

	len = _printf("String:[%S]\n", "hallo\nWorld");
	len2 = printf("String:[hallo\\x0AWorld]\n");
	printf("Length:[%d, %d]\n", len, len2);
}

/**
 * test_print_integer - test print integer
 *
 * Return: void
 */
void test_print_integer(void)
{
	int len, len2;

	len = _printf("Negative:[%d]\n", -762534);
	len2 = printf("Negative:[%d]\n", -762534);
	printf("Len:[%d, %d]\n", len, len2);

	len = _printf("Negative:[%i]\n", -76);
	len2 = printf("Negative:[%i]\n", -76);
	printf("Len:[%d, %d]\n", len, len2);

	len = _printf("Positive:[%i]\n", 76);
	len2 = printf("Positive:[%i]\n", 76);
	printf("Len:[%d, %d]\n", len, len2);

	len = _printf("Int:[%i], Decimal:[%d]\n", 0x33, 033);
	len2 = printf("Int:[%i], Decimal:[%d]\n", 0x33, 033);
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

	_printf("Address:[%p]\n", NULL);
	printf("Address:[%p]\n", NULL);
}


/**
 * test_print_binary - test print binary
 *
 * Return: void
 */
void test_print_binary(void)
{
	int len, len2;

	len = _printf("Binary:[%b]\n", 98);
	len2 = printf("Binary:[%b]\n", 98);
	printf("Len:[%d, %d]\n", len, len2);

	len = _printf("Binary:[%b]\n", 1024);
	len2 = printf("Binary:[%b]\n", 1024);
	printf("Len:[%d, %d]\n", len, len2);
}

/**
 * test_print_octal - test print octal
 *
 * Return: void
 */
void test_print_octal(void)
{
	int len, len2;

	len = _printf("Octal:[%o]\n", 98);
	len2 = printf("Octal:[%o]\n", 98);
	printf("Len:[%d, %d]\n", len, len2);

	len = _printf("Octal:[%o]\n", -98);
	len2 = printf("Octal:[%o]\n", -98);
	printf("Len:[%d, %d]\n", len, len2);

	len = _printf("Octal:[%o]\n", 1024);
	len2 = printf("Octal:[%o]\n", 1024);
	printf("Len:[%d, %d]\n", len, len2);
}

/**
 * test_print_hex - test print hex
 *
 * Return: void
 */
void test_print_hex(void)
{
	int len, len2;

	len = _printf("hex:[%x]\n", 98);
	len2 = printf("hex:[%x]\n", 98);
	printf("Len:[%d, %d]\n", len, len2);

	len = _printf("hex:[%x]\n", 0xA);
	len2 = printf("hex:[%x]\n", 0xA);
	printf("Len:[%d, %d]\n", len, len2);

	len = _printf("hex:[%x]\n", 1024);
	len2 = printf("hex:[%x]\n", 1024);
	printf("Len:[%d, %d]\n", len, len2);

	len = _printf("Hex:[%X]\n", 98);
	len2 = printf("Hex:[%X]\n", 98);
	printf("Len:[%d, %d]\n", len, len2);

	len = _printf("Hex:[%X]\n", 1024);
	len2 = printf("Hex:[%X]\n", 1024);
	printf("Len:[%d, %d]\n", len, len2);
}

/**
 * test_print_uint - test print unsigned
 *
 * Return: void
 */
void test_print_uint(void)
{
	int len, len2;

	len = _printf("Unsigned:[%u]\n", 98);
	len2 = printf("Unsigned:[%u]\n", 98);
	printf("Len:[%d, %d]\n", len, len2);

	len = _printf("Unsigned:[%u]\n", 1024);
	len2 = printf("Unsigned:[%u]\n", 1024);
	printf("Len:[%d, %d]\n", len, len2);

	len = _printf("Unsigned:[%u]\n", -1);
	len2 = printf("Unsigned:[%u]\n", -1);
	printf("Len:[%d, %d]\n", len, len2);
}

/**
 * test_print_flags - test print flags
 *
 * Return: void
 */
void test_print_flags(void)
{
	int len, len2;

	len = _printf("Flag:[%+d]\n", 98);
	len2 = printf("Flag:[%+d]\n", 98);
	printf("Len:[%d, %d]\n", len, len2);

	len = _printf("Flag:[%+d]\n", -98);
	len2 = printf("Flag:[%+d]\n", -98);
	printf("Len:[%d, %d]\n", len, len2);

	len = _printf("Flag:[% d]\n", 98);
	len2 = printf("Flag:[% d]\n", 98);
	printf("Len:[%d, %d]\n", len, len2);

	len = _printf("Flag:[% d]\n", -98);
	len2 = printf("Flag:[% d]\n", -98);
	printf("Len:[%d, %d]\n", len, len2);

	len = _printf("Flag:[%#x]\n", 98);
	len2 = printf("Flag:[%#x]\n", 98);
	printf("Len:[%d, %d]\n", len, len2);

	len = _printf("Flag:[%#x]\n", 0);
	len2 = printf("Flag:[%#x]\n", 0);
	printf("Len:[%d, %d]\n", len, len2);

	len = _printf("Flag:[%#o]\n", 98);
	len2 = printf("Flag:[%#o]\n", 98);
	printf("Len:[%d, %d]\n", len, len2);

	len = _printf("Flag:[%#o]\n", 0);
	len2 = printf("Flag:[%#o]\n", 0);
	printf("Len:[%d, %d]\n", len, len2);

	len = _printf("Flag:[% x]\n", 98);
	len2 = printf("Flag:[% x]\n", 98);
	printf("Len:[%d, %d]\n", len, len2);

	len = _printf("Flag:[%+x]\n", 98);
	len2 = printf("Flag:[%+x]\n", 98);
	printf("Len:[%d, %d]\n", len, len2);

	len = _printf("Flag:[% o]\n", 98);
	len2 = printf("Flag:[% o]\n", 98);
	printf("Len:[%d, %d]\n", len, len2);

	len = _printf("Flag:[%+o]\n", 98);
	len2 = printf("Flag:[%+o]\n", 98);
	printf("Len:[%d, %d]\n", len, len2);
}


/**
 * test_print_reverse - test print reverse
 *
 * Return: void
 */
void test_print_reverse(void)
{
	int len, len2;

	len = _printf("Reverse:[%r]\n", "Holberton");
	len = _printf("Reverse:[%r]\n", "School");
	len = _printf("Reverse:[%r]\n", "Holberton School");
}

/**
 * test_print_rotation - test print reverse
 *
 * Return: void
 */
void test_print_rotation(void)
{
	int len, len2;

	len = _printf("Reverse:[%R]\n", "Holberton Holberton Holberton Holberton Holberton");
	len = _printf("Reverse:[%R]\n", "Holberton School lorem ipsum Holberton School lorem ipsum");
	len = _printf("Reverse:[%R]\n", "Holberton School lorem ipsum");
}