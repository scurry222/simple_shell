#include "shell.h"

/**
 * _setenv - sets an environment variable
 * @head: double pointer to the environ linked list
 * @name: name of the variable to set
 * @value: value of the variable to set
 *
 * Return: 0 on success, -1 on failure
 */
int _setenv(env_t **head, char **argv, int args)
{
	char *buf1, *buf2;
	int index;

	if (!head || !*head)
		return (0);

	if (args == 1)
	{
		print_list(*head);
		return (0);
	}
	if (args > 3)
		return (-1);
	buf1 = str_concat(argv[1], "=");
	buf2 = str_concat(buf1, argv[2]);
	free(buf1);

	index = find_index_list(*head, argv[1]);
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
	return (0);
}

/**
 * _unsetenv - unsets an environment variable
 * @head: double pointer to the environ linked list
 * @name: name of the variable to unset
 *
 * Return: 0 on success, -1 on failure
 */
int _unsetenv(env_t **head, char **argv)
{
	int index;

	 if (!argv[1])
		 return (-1);

	index = find_index_list(*head, argv[1]);
	if (index == 0 || !head || !*head)
		return (0);

	else
		delete_node_at_index(head, index);
	return (0);
}

/**
 * setenv_handler - handles the setenv and unsetenv builtins
 * @argv: array of arguments from the command line
 * @head: pointer to the env_t linked list
 */
void setenv_handler(char **argv, env_t **head)
{
	int n, m, args = 0;

	while (argv[args])
		args++;

	if (!_strcmp(argv[0], "setenv"))
	{
		n = _setenv(head, argv, args);
		if (n == -1)
			printf("setenv: Too many arguments.\n");
	} else if (!_strcmp(argv[0], "unsetenv"))
	{
		m = _unsetenv(head, argv);
		if (m == -1)
			printf("unsetenv: Too few arguments.\n");
	}
}
