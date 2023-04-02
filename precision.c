#include "main.h"
/**
 * get_precision - Function to calculate the precision for printing
 * @arg: List of arguments to be printed
 * @ls: list of arguments
 * @format: A string format string to print arguments
 * Return: The precision value
 */
int prec(const char *format, int *arg, va_list ls)
{
	int current = *arg + 1, prec = -1;

	if (format[current] != '.')
		return (prec);

	prec = 0;

	for (current += 1; format[current] != '\0'; current++)
	{
		if (is_digit(format[current]))
		{
			prec *= 10;
			prec += format[current] - '0';
		}
		else if (format[current] == '*')
		{
			current++;
			prec = va_arg(ls, int);
			break;
		}
		else
			break;
	}

	*arg = current - 1;

	return (prec);
}