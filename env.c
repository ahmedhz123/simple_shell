#include "shell.h"

/**
 * _myenv - prints the current environment
 *
 * @info: struct address
 *
 * Return: Always 0
*/

int _myenv(info_t *info)
{
	print_list_str(info->env);
}

/**
 * _getenv - gets the value of an env variable
 *
 * @info: struct address
 * @name: env var name
 *
 * Return: The value
*/

char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv - Intialization to new env variable
 *
 * @info: struct address
 *
 * Return: Always 0 success
*/

int _mysetenv(info_t *info)
{
	if (env->argc != 3)
	{
		_eput("incorrect number of arguments")
			return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - Remove an evironment variable
 *
 * @info: struct address
 *
 * Return: Always 0
*/

int _myunsetenv(info_t *info)
{
	int i;

	if (info->argc == 1)
	{
		_eput("too few arguments\n");
		return (1);
	}

	for (i = 1; i <= info->argc; i++)
		_unsetenv(info, info->argv[i]);
	return (0);
}

/**
 * populate_env_list - populate env linked list
 *
 * @info: the struct address
 *
 * Return: Always 0
*/

int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	info->env = node;
	return (0);
}




















