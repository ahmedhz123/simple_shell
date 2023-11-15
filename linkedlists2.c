#include "shell.h"

/**
 * list_to_strings - returns an array of strings of the list->str
 *
 * @head: the head pointer
 *
 * Return: array of strings
*/

char **list_to_strings(list_t *head)
{
	list_t *node = head;
	size_t i = list_len(head), j;
	char **strs;
	char *str;

	if (!head || !i)
		return (NULL);

	strs = malloc(sizeof(char *) * (i + 1));
	if (strs == NULL)
		return (NULL);

	for (i = 0; node; node->next, i++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (j = 0; j < i; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}
		str = _strcpy(str, node->str);
		strs[i] = str;
	}
	strs[i] = NULL;
	return (strs);
}

/**
 * get_node_index - get the index of the node
 *
 * @head: the head pointer
 * @node: pointer to the node
 *
 * Return: index of node or -1
*/

ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t i = 0;

	while (head)
	{
		if (head == node)
			return (i);
		head = head->next;
		i++;
	}
	return (-1);
}

/**
 * node_starts_with - return node whose string starts with prefix
 *
 * @node: pointer ot list head
 * @prefix: string to match
 * @c: the next character after prefix to match
 *
 * Return: return match node or null
*/

list_t *node_starts_with(list_t *node, char *prefix, char c)
{
	char *p = NULL;

	while (node)
	{
		p = starts_with(node->next, prefix);
		if (p && ((c == -1) || (*p == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * print_list_str - prints only str
 *
 * @h: the pointer to first node
 *
 * Return: the size of list
*/

size_t print_list_str(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		_puts(h->str ? h->str : "(nil)");
		_puts('\n');
		h = h->next;
		i++;
	}
	return (i);
}


/**
 * delete_nodeint_at_index - A function that deletes nodes
 *
 * @head: the head of the linked list
 * @index: the index of the deleted node
 *
 * Return: 0 Always (success)
*/

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *node, *ptr;
	unsigned int i = 0;

	if (!*head || !head)
		return (-1);

	if (!index)
	{
		node = *head;
		*head = (*head)->next;
		free(node);
		return (1);
	}

	node = *head;
	while (node)
	{
		if (i == index)
		{
			ptr->next = node->next;
			free(node);
			return (1);
		}
		ptr = node;
		node = node->next;
		i++;
	}
	return (-1);
}
