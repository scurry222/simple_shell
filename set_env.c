#include "shell.h"

/**
 * _setenv - sets an environment variable
 * @head: double pointer to the environ linked list
 * @name: name of the variable to set
 * @value: value of the variable to set
 *
 * Return: 0 on success, -1 on failure
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
 * _unsetenv - unsets an environment variable
 * @head: double pointer to the environ linked list
 * @name: name of the variable to unset
 *
 * Return: 0 on success, -1 on failure
 */
int _unsetenv(env_t **head, char *name)
{
	int index = find_index_list(*head, name);

	 if (!name)
		 return (-1);

	if (index == 0 || !head || !*head)
		return (-1);

	else
	{
		delete_node_at_index(head, index);
		return (0);
	}
	return (-1);
}

/**
 * setenv_handler - handles the setenv and unsetenv builtins
 * @argv: array of arguments from the command line
 * @head: pointer to the env_t linked list
 */
void setenv_handler(char **argv, env_t **head)
{
	int n, m;

	if (!_strcmp(argv[0], "setenv"))
	{
		n = _setenv(head, argv[1], argv[2]);
		if (n == -1)
		{
			printf("ERROR SETENV\n");
			//error function
		}
	} else if (!_strcmp(argv[0], "unsetenv"))
	{
		m = _unsetenv(head, argv[1]);
		if (m == -1)
		{
			printf("ERROR UNSETENV\n");
			//error function
		}
	}
}
