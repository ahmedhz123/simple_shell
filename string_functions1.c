#include <stdio.h>
#include "shell.h"
#include <unistd.h>

/**
 * _strlen - a function that returns the lenght of a string
 *
 * @s: char parameter
 *
 * Return: the length of the string
*/

int _strlen(char *s)
{
	int counter;

	for (counter = 0; *s != '\0'; s++)
		counter++;
	return (counter);
}


/**
 * _putchar - writes the character c to stdout
 * @c: the character to print
 *
 * Return: on success 1.
 *      on error, -1 is returned, and errno is set appropriately
*/

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - function that prints the string input
 *
 * @str: pointer parameter
 *
 * Return: void
*/

void _puts(char *str)
{
	while (*str != '\0')
	{
		_putchar(*str++);
	}
	_putchar('\n');
}

/**
 * _strcpy - function name
 *
 * @dest: function parameter 1
 * @src: function parameter 2
 *
 * Return: always 0
 *
*/

char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return (dest);
}

