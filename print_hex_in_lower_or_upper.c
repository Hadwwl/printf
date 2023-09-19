#include "main.h"

/**
 * print_hexa - This Prints a hexadecimal number in lowerCase or upperCase
 * @kind:Arguments to provide
 * @map_to: List of Array of values to map the number to
 * @buffer: Buffer array to handle printing
 * @flags:  Calc active flags
 * @flag_ch: Calc active flags
 * @width: get width
 * @precision: Precision modification
 * @size: Size modifier
 * @size: Size modifier
 * Return: Number of characters that was printed
 */
int print_hexa(va_list kind, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(kind, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
