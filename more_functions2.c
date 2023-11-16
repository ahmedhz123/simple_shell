#include "shell.h"

/**
 * remove_comments - function replace first instance of #
 *
 * @buf: address of the string to modify
 *
 * Return: Always 0 (success)
*/

void remove_comments(char *buf)
{
	int i;

	for (i = 0; buf[i] != '\0'; i++)
	{
		if (buf[i] == '#' && (!i || buf[i - 1] == ' '))
		{
			buf[i] = '\0';
			break;
		}
	}
}

/**
 * converter_number - convert int to string
 *
 * @num: number
 * @base: base
 * @flags: arguments flag
 *
 * Return: string
*/

char *converter_number(long int num, int base, int flags)
{
	static char *array;
	static char buffer[50];
	char sign;
	char *ptr;
	unsigned long n = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';
	}
	array = flags & CONVERT_LOWERCASE ? "0123456780abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do {
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
	{
		*--ptr = sign;
	}
	return (ptr);
}

/**
 * _erratoi - convert the string to an integer
 *
 * @s: the string to be converted
 *
 * Return: 0 if no numbers in string, converted number
 *	-1 on error
*/

int _erratoi(char *s)
{
	int i = 0;
	unsigned long int result = 0;

	if (*s == '+')
		s++;
	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			result *= 10;
			result += (s[i] - '0');

			if (result > INT_MAX)
			{
				return (-1);
			}
		}
		else
			return (-1);
	}
	return (result);
}

/**
 * print_error - prints an error message
 *
 * @info: the parameter and return info message
 * @estr: string containing specified error type
 *
 * Return: 0 if no number in string, converted numbers
 *	otherwise -1 on error
*/

void print_error(info_t *info, char *estr)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estr);
}

/**
 * print_d - function prints a decimal (integer) number (base 10)
 *
 * @input: the input
 * @fd: the ile descriptor to write to
 *
 * Return: number of characters printed
*/

int print_d(int input, int fd)
{
	int (*__putchar)(char) = _putchar;

	int i, count = 0;
	unsigned int _abs_, current;

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		count++;
	}
	else
		_abs_ = input;
	current = _abs_;

	for (i = 1000000000; i > 1; i /= 10)
	{
		if (_abs_ / i)
		{
			__putchar(current / i + '0');
			count++;
		}
		current %= i;
	}
	__putchar(current + '0');
	count++;
	return (count);
}
