#include "main.h"

/**
 * print_percent - Implement printing a percent sign
 * @kinds: number of arguments listed
 * @buffer: Buffer array to handle print
 * @flags: know active flags
 * @width: total width.
 * @precision: Precision modification
 * @size: Size modifier
 * Return: total number of characters  printed
 */
int print_percent(va_list kinds, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(kinds);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}
