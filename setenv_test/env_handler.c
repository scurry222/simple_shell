#include "list.h"

/**
*
*
*
*
*/

int _setenv(env_t **head, char *name, char *value)
{
	char *buf1, *buf2;
	int index;

	if (!head || !*head)
		return (-1);

	index = find_index_list(*head, name);

	if (!value && !name)
	{
		print_list(*head);
		return (0);
	}

	buf1 = str_concat(name, "=");
	buf2 = str_concat(buf1, value);
	free(buf1);

	if (index == 0)
	{
		add_node_end(head, buf2);
		free(buf2);
		return (0);
	}

	if (index > 0)
	{
		delete_node_at_index(head, index);
		add_node_at_index(head, buf2, index);
		free(buf2);
		return (0);
	}

	free(buf2);
	return (-1);
}

/**
*
*
*
*/

int _unsetenv(env_t **head, char *name)
{
	int index = find_index_list(*head, name);

//	if (!name)
		// ("errrrrror\n");

	if (index == 0 || !head || !*head)
		return (-1);

	else
	{
		delete_node_at_index(head, index);
		return (0);
	}
	return (-1);
}



