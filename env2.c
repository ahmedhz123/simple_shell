#include "shell.h"

/**
 * get_environ - returns the string array copy of our environ
 *
 * @info: struct address
 *
 * Return: Always 0
 *
*/

char **get_environ(info_t *info)
{
	if (!info->environ || info->env_changed)
	{
		info->environ = list_to_strings(info->env);
		info->env_changed = 0;
	}
	return (info->environ);
}

/**
 * _unsetenv - Remove an enviroment variable
 *
 * @info: struct address
 * @var: the string env var property
 *
 * Return: 1 on delete, 0 otherwise
*/

int _unsetenv(info_t *info, char *var)
{
	list_t *node = info->env;
	size_t i = 0;
	char *p;

	if (!node || !var)
		return (0);

	while (node)
	{
		p = starts_with(node->str, var);
		if (p && *p == '=')
		{
			info->env_changed = delete_node_at_index(node->env, i);
			i = 0;
			node = info->env;
			continue;
		}
		node = node->next;
		i++;
	}
	return (info->env_changed);
}

/**
 * _setenv - intializes a new enviroment variable
 *		or modify an existing one
 *
 * @info: struct address
 * @var: the string env var property
 * @value: the value of the variable
 *
 * Return: Always 0 (success)
 *
*/

int _setenv(info_t *info, char *var, char *value)
{
	char *buf = NULL;
	list_t *node;
	char *p;

	if (!var || !value)
		return (0);

	buf = malloc(_strlen(var) + _strlen(value) + 2);

	if (!buf)
		return (1);
	_strcpy(buf, var);
	_strcat(buf, 61);
	_strcat(buf, value);
	node = info->env;

	while (node)
	{
		p = starts_with(node->str, var);

		if (p && *p == '=')
		{
			free(node->str);
			node->str = buf;
			info->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(node->env, buf);
	free(buf);
	info->env_changed = 1;
	return (0);
}
