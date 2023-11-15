#include "shell.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * _strchr - A function that locates a character in a string
 *
 * @s: the character pointer
 * @c: char parameter
 *
 * Return: 0 Always (Success)
*/

char *_strchr(char *s, char c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return (s);
		s++;
	}
	if (*s == c)
		return (s);
	return (NULL);
}

/**
 * _strdup - returns a pointer to a newly allocated space in memory
 *
 * @str: the pointe parameter
 *
 * Return: 0 Always (success)
*/

char *_strdup(char *str)
{
	int i;
	char *copy;
	int count = 0;

	if (str == NULL)
		return (NULL);

	for (i = 0; str[i] != '\0'; i++)
		count++;
	copy = malloc(sizeof(char) * (count + 1));

	if (copy == NULL)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
		copy[i] = str[i];
	return (copy);
}

/**
 * start_with - function to check if the string begins with haystack
 *
 * @haystack: A parameter refers to the beginning of the string
 * @needle: A parameter refers to the original complete string
 *
 * Return: the haystack
*/

char *start_with(const char *haystack, const char *needle)
{
	while (*needle)
	{
		if (*needle++ != *haystack++)
			return (NULL);
	}
	return ((char *)haystack);
}


