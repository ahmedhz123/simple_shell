#include "shell.h"
#include <string.h>

/**
 * *_strcat - Function to concate two strings
 *
 * @dest: the pointer parameter
 * @src: the pointer parameter
 *
 * Return: 0 Always
 *
*/

char *_strcat(char *dest, char *src)
{
	int destlen = 0;
	int srclen = 0;
	int i;

	for (i = 0; dest[i] != '\0'; i++)
		destlen++;

	for (i = 0; src[i] != '\0'; i++)
		srclen++;

	for (i = 0; i <= srclen; i++)
		dest[destlen + i] = src[i];
	return (dest);
}

/**
 * *_strncat - concates two string
 *
 * @dest: the pointer parameter
 * @src: the pointer parameter
 * @n: parameter for function
 *
 * Return: 0 Always
 *
*/

char *_strncat(char *dest, char *src, int n)
{
	int i;
	int len = strlen(dest);

	for (i = 0; i < n && *src != '\0'; i++)
	{
		dest[len + i] = *src;
		src++;
	}
	dest[len + i] = '\0';
	return (dest);
}

/**
 * _strcmp - Function to compare to string
 *
 * @s1: the pointer parameter
 * @s2: the pointer parameter
 *
 * Return: 0 Always (Success)
*/

int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] != '\0' || s2[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
		{
			if (s1[i] < s2[i])
				return (s1[i] - s2[i]);
			else if (s1[i] > s2[i])
				return (s1[i] - s2[i]);
		}
	}
	return (0);
}

/**
 * *_strncpy - copy strings
 *
 * @dest: the pointer parameter
 * @src: the pointer parameter
 * @n: the function parameter
 *
 * Return: 0 Always
 *
*/

char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
