#include "shell.h"

/**
 * bfree - A function that frees the pointer and frees the address
 *
 * @ptr: A double pointer
 *
 * Return: Always 0 (success)
*/

int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
