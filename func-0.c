#include "main.h"
/**
 * print_binary - Function that prints an unsigned integer
 * @width: Calculates the width
 * @size: Specifies the size
 * @args: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Checks for flags that are active
 * @prec: Specifies the precision
 * Return: The Number of characters to be printed
 */
int print_binary(num_store args, char buffer[],
	int flags, int width, int prec, int size)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(prec);
	UNUSED(size);

	n = values(args, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
/**
 * print_int - Function that prints an integer
 * @width: Calculates the width
 * @size: Specifies the size
 * @args: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Checks for flags that are active
 * @prec: Specifies the precision
 * Return: The Number of characters to be printed
 */
int print_int(num_store args, char buffer[],
	int flags, int width, int prec, int size)
{
	int i = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = values(args, long int);
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
/**
 * print_percent - Fucntion that prints a percent sign
 * @width: Calculates the width
 * @size: Specifies the size
 * @args: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Checks for flags that are active
 * @prec: Specifies the precision
 * Return: The Number of characters to be printed
 */
int print_percent(num_store args, char buffer[],
	int flags, int width, int prec, int size)
{
	UNUSED(args);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(prec);
	UNUSED(size);
	return (write(1, "%%", 1));
}
/**
 * print_char - Function that prints a character
 * @width: Calculates the width
 * @size: Specifies the size
 * @args: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Checks for flags that are active
 * @prec: Specifies the precision
 * Return: The Number of characters to be printed
 */
int print_char(num_store args, char buffer[],
	int flags, int width, int prec, int size)
{
	char ch = values(args, int);

	return (handle_write_char(ch, buffer, flags, width, prec, size));
}
/**
 * print_string - Function that prints a string
 * @width: Calculates the width
 * @size: Specifies the size
 * @args: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Checks for flags that are active
 * @prec: Specifies the precision
 * Return: The Number of characters to be printed
 */
int print_string(num_store args, char buffer[],
	int flags, int width, int prec, int size)
{
	int len = 0, i;
	char *str = values(args, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(prec);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (prec > 5)
			str = "      ";
	}

	while (str[len] != '\0')
		len++;

	if (prec > -1 && prec < len)
		len = prec;

	if (width > len)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], len);
			for (i = width - len; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - len; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], len);
			return (width);
		}
	}

	return (write(1, str, len));
}