#include <stdio.h>
#include <stdlib.h>
#include "shell.h"

/**
 * _realloc - reallocates the memory using malloc and free
 *
 * @ptr: the pointer parameter of the function
 * @old_size: the second parameter of the function
 * @new_size: the third parameter of the function
 *
 * Return: void
*/

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *output;
	unsigned int i;

	if (new_size == old_size)
		return (ptr);
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (ptr == NULL)
	{
		output = malloc(new_size);

		if (output == NULL)
			return (NULL);
		return (output);
	}
	if (new_size > old_size)
	{
		output = malloc(new_size);
		if (output == NULL)
			return (NULL);
		for (i = 0; i < old_size && i < new_size; i++)
			*((char *)output + i) = *((char *)ptr + i);
		free(ptr);
	}
	return (output);
}


/**
 * _memset - function fills the memory with constant byte
 *
 * @s: array of characters
 * @b: constant byte
 * @n: bytes of memory
 *
 * Return: array of characters
 *
*/

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		s[i] = b;
	}
	return (s);
}

/**
 * ffree - free a string of strings
 *
 * @pp: the string of the strings
 *
 * Return: Void
*/

void ffree(char **pp)
{
	char *a = pp;

	if (!pp)
		return;
	while (*pp)
	{
		free(*pp++);
	}
	free(a);
}
