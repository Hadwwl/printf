#include "main.h"

/**
 * print_int - function Print integer numbers
 * @kinds: List of arguments parsed
 * @buffer: Buffer array to handle print
 * @flags: calc the flags
 * @width: print width of func
 * @precision: Precision modifier
 * @size: Size modifier
 * Return: total Number of characters printed
 */

int print_int(va_list kinds, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(kinds, long int);
	unsigned long int num;

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_number(is_negative, i, buffer, flags, width, precision, size));
}
