#include "shell.h"

/**
 * interactive - return true if shell is interactive mode
 *
 * @info: the struct address
 *
 * Return: 1 if interactive mode, 0 otherwise
*/

int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - checks if the character is delimiter
 *
 * @c: the char to be checked
 * @delim: the delimiter string
 *
 * Return: 1 if true, 0 if false
*/

int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 * _atoi - converts the string to number
 *
 * @s: the string
 *
 * Return: 0 if no numbers in string, converted numbers otherwise
*/

int _atoi(char *s)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0; s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;
		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
		{
			flag = 2;
		}
	}
	if (sign == -1)
		output = -result;
	else
		output = result;
	return (output);
}

/**
 * _isalpha - funtction check if the input is
 *              letter or not
 *
 * @c: checks the input of function
 *
 * Return: return 1 if the input is a letter
 *              otherwise Always 0 (Success);
*/

int _isalpha(int c)
{
	if (c >= 65 && c <= 90)
		return (1);
	if (c >= 97 && c <= 122)
		return (1);
	else
		return (0);
}

