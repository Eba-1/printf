#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024
#define F_ZERO 4
#define F_MINUS 1
#define F_PLUS 2
#define F_HASH 8
#define F_SPACE 16
#define S_LONG 2
#define S_SHORT 1

/**
 * struct form - A structure for operations
 * @form: The format.
 * @func: The function associated.
 */
struct form
{
	int (*func)(num_store, char[], int, int, int, int);
	char form;
};

/**
 * typedef struct form fmt_t - Struct op
 * @fm_t: The function associated.
 * @form: The format.
 */
typedef struct form fmt_t;

int print_int(num_store types, char buffer[], int flags, int width, int prec, int size);
int print_binary(num_store types, char buffer[], int flags, int width, int prec, int size);
int print_percent(num_store types, char buffer[], int flags, int width, int prec, int size);
int print_char(num_store types, char buffer[], int flags, int width, int prec, int size);
int print_string(num_store types, char buffer[], int flags, int width, int prec, int size);

int print_unsigned(num_store types, char buffer[], int flags, int width, int prec, int size);
int print_hexa(num_store types, char map_to[], char buffer[], int flags, char flag_ch, int width, int prec, int size);
int print_octal(num_store types, char buffer[], int flags, int width, int prec, int size);
int print_hexadecimal(num_store types, char buffer[],
	int flags, int width, int prec, int size);
int print_hexa_upper(num_store types, char buffer[], int flags, int width, int prec, int size);

int flag_num(const char *format, int *r);

int prec(const char *format, int *arg, num_store ls);

int size(const char *format, int *arg);

int width(const char *format, int *arg, num_store ls);

int hPrint(const char *form, int *ind, num_store list, char buffer[], int flags, int width, int precision, int size);

int is_digit(char);
int is_printable(char);
int append_hexa_code(char, char[], int);
long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);

int write_pointer(char buffer[], int ind, int length, int width, int flags, char padd, char extra_c, int padd_start);
int handle_write_char(char c, char buffer[], int flags, int width, int precision, int size);
int write_unsgnd(int is_negative, int ind, char buffer[], int flags, int width, int precision, int size);
int write_num(int ind, char bff[], int flags, int width, int precision, int length, char padd, char extra_c);
int write_number(int is_positive, int ind, char buffer[], int flags, int width, int precision, int size);

int _printf(const char *format, ...);

int print_non_printable(num_store types, char buffer[],
	int flags, int width, int precision, int size);
int print_pointer(num_store types, char buffer[],
	int flags, int width, int precision, int size);
int print_reverse(num_store types, char buffer[],
	int flags, int width, int precision, int size);
int print_rot13string(num_store types, char buffer[],
	int flags, int width, int precision, int size);

#endif /* MAIN_H */