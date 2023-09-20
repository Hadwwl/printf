#include "main.h"

/**
 * print_reverse -This function Prints reverse string.
 * @kind: The List of all arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calc active flags
 * @width: get width
 * @precision: Precision modifier
 * @size: Size modifier
 * Return: Numbers of characters printed
 */

int print_reverse(va_list kind, char buffer[],
	int flags, int width, int precision, int size)
{
	char *str;
	int i, count = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(types, char *);

	if (str == NULL)
	{
		UNUSED(precision);

		str = ")Null(";
	}
	for (i = 0; str[i]; i++)
		;

	for (i = i - 1; i >= 0; i--)
	{
		char z = str[i];

		write(1, &z, 1);
		count++;
	}
	return (count);
}
