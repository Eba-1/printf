#include "main.h"
/**
 * get_width - Function that calculates the width of characters
 * @arg: List of arguments to be printed
 * @ls: list of arguments
 * @format: A string format string to print arguments
 * Return: The precision value
 */
int width(const char *format, int *arg, va_list ls)
{
	int current;
	int width = 0;

	for (current = *arg + 1; format[current] != '\0'; current++)
	{
		if (format[current] == '*')
		{
			current++;
			width = va_arg(ls, int);
			break;
		}
		else if (is_digit(format[current]))
		{
			width *= 10;
			width += format[current] - '0';
		}
		else
			break;
	}

	*arg = current - 1;

	return (width);
}
