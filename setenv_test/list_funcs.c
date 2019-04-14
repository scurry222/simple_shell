#include "list.h"

/**
 * print_list - prints all the elements of a linked list
 * @h: pointer to the list_t list to print
 *
 * Return: the number of nodes printed
 */
size_t print_list(env_t *h)
{
	size_t s = 0;

	while (h)
	{
		if (!h->str)
			printf("(nil)\n");
		else
			printf("%s\n", h->str);
		h = h->next;
		s++;
	}

	return (s);
}

/**
 * add_node_end - adds a new node at the end of a linked list
 * @head: double pointer to the list_t list
 * @str: string to put in the new node
 *
 * Return: address of the new element, or NULL if it failed
 */
env_t *add_node_end(env_t **head, const char *str)
{
	env_t *new;
	env_t *temp = *head;

	new = malloc(sizeof(env_t));
	if (!new)
		return (NULL);

	new->str = strdup(str);
	new->next = NULL;

	if (*head == NULL)
	{
		*head = new;
		return (new);
	}

	while (temp->next)
		temp = temp->next;

	temp->next = new;

	return (new);
}

/**
 * free_list - frees a linked list
 * @head: list_t list to be freed
 */
void free_list(env_t **head)
{
	env_t *temp;

	if (head == NULL)
		return;

	while (*head)
	{
		temp = (*head)->next;
		free(*head);
		*head = temp;
	}

	*head = NULL;
}

/**
 * delete_nodeint_at_index - deletes a node in a linked list at a certain index
 * @head: pointer to the first element in the list
 * @index: index of the node to delete
 *
 * Return: 1 (Success), or -1 (Fail)
 */
int delete_nodeint_at_index(env_t **head, unsigned int index)
{
	env_t *temp = *head;
	env_t *current = NULL;
	unsigned int i = 0;

	if (*head == NULL)
		return (-1);

	if (index == 0)
	{
		*head = (*head)->next;
		free(temp);
		return (1);
	}

	while (i < index - 1)
	{
		if (!temp || !(temp->next))
			return (-1);
		temp = temp->next;
		i++;
	}


	current = temp->next;
	temp->next = current->next;
	free(current);

	return (1);
}


int arr_to_list(env_t **head)
{
	int i = 0;

	while (environ[i])
	{
		add_node_end(head, environ[i]);
		i++;
	}
	return (i);
}

int find_index_list(char *name, env_t **head)
{
	int index = 0;
	int c;

	while (*head)
	{
		c = strncmp((*head)->str, name, strlen(name));
		if (c == 0)
			return (index);
		else
			index++;
		*head = (*head)->next;
	}

	return (0);
}
