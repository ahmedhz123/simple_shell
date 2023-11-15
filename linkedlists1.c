#include "shell.h"

/**
 * print_list - a function that prints all element in list_t list
 *
 * @h: the singly linked list
 *
 * Return: the size of the linked lists
 *
*/

size_t print_list(const list_t *h)
{
	size_t nodes;

	nodes = 0;
	while (h != NULL)
	{
		if (h->str == NULL)
		{
			printf("[%d] %s\n", 0, "(nil)");
		}
		else
		{
			printf("[%d] %s\n", h->len, h->str);
		}
		h = h->next;
		nodes++;
	}
	return (nodes);
}


/**
 * list_len - A function thar prints the number of list's elements
 *
 * @h: the singly linked lists
 *
 * Return: the length of the linked list
*/

size_t list_len(const list_t *h)
{
	size_t nodes = 0;

	while (h != NULL)
	{
		nodes++;
		h = h->next;
	}
	return (nodes);

}

/**
 * add_node_end - A function that adds a node at the end
 *
 * @head: The head of the linked list
 * @str: the string of the node
 *
 * Return: the new linked list
*/

list_t *add_node_end(list_t **head, const char *str)
{
	unsigned int i, count = 0;
	list_t *newnode, *tmp;

	newnode = malloc(sizeof(list_t));
	if (newnode == NULL)
		return (NULL);
	newnode->str = strdup(str);

	for (i = 0; str[i] != '\0'; i++)
		count++;
	newnode->len = count;
	newnode->next = NULL;
	tmp = *head;

	if (tmp == NULL)
		*head = newnode;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next; /*to traverse over the linked list*/
	tmp->next = newnode;
	}
	return (*head);
}

/**
 * free_list - free the linked list
 *
 * @head: the head of the linked list
 *
 * Return: void
*/

void free_list(list_t *head)
{
	list_t *tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}


/**
 * add_node - A function that adds new node at the beginning
 *
 * @head: the head of the linked list
 * @str: A string
 *
 * Return: return the new node
*/

list_t *add_node(list_t **head, const char *str)
{
	list_t *newnode;
	unsigned int i, count = 0;

	newnode = malloc(sizeof(list_t));
	if (newnode == NULL)
		return (newnode);
	newnode->str = strdup(str);
	for (i = 0; str[i] != '\0'; i++)
		count++;
	newnode->len = count;
	newnode->next = *head;
	*head = newnode;

	return (*head);
}
