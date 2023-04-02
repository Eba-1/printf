#include "main.h"

/**
 * flag_num - Stores the number of active flags
 * @format: String that print the arguments
 * @var: A parameter.
 * Return: Flag numbers on success:
 */
int flag_num(const char *format, int *var)
{
	int iter, index, flag_num = 0;
	const char flag_list[] = {'-', '+', '0', '#', ' ', '\0'};
	const int flag_array[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (index = *var + 1; format[index] != '\0'; index++)
	{
		for (iter = 0; flag_list[iter] != '\0'; iter++)
			if (format[index] == flag_list[iter])
			{
				flag_num |= flag_array[iter];
				break;
			}

		if (flag_list[iter] == 0)
			break;
	}

	*var = index - 1;

	return (flag_num);
}
