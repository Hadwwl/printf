#include main.h

/**
 * print_int - part of printf function that takes care of the Printing integer
 * @kind: list of arguments provided
 * @buffer: Buffer array to handle printing
 * @flags:  Cal active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size modifier
 * Return: Number of characters printed
 */
int print_int(va_list kind, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(kind, long int);
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
