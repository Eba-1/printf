#include "main.h"

/**
 * get_size - Function that calculates the size for casting the argument
 * @arg: List of arguments to be printed
 * @format: A string format string to print arguments
 * Return: The precision value
 */
int get_size(const char *format, int *arg)
{
	int current = *i + 1, size = 0;

	if (format[current] == 'h')
		size = S_SHORT;
	else if (format[current] == 'l')
		size = S_LONG;

	if (size != 0)
		*arg = current;
	else
		*arg = current - 1;

	return (size);
}
