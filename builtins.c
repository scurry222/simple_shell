#include "shell.h"

/**
 * is_builtin - checks if the command is a builtin
 * @prog_name: name of the program
 * @argv: parsed command line
 * @i: pointer to the increment variable of main
 * @head: double pointer to the environ linked list
 *
 * Return: 1 if yes, 0 if no
 */
int is_builtin(char **argv, char *prog_name, int *i, env_t **head)
{
	int n;
	long long int m;

	if (!_strcmp(argv[0], "exit"))
	{
		m = exit_handler(argv);
		if (m == -1)
		{
			print_error_exit(i, prog_name, argv);
		}
		else
		{
			free_everything(argv);
			exit(m);
		}
		free_everything(argv);
		*i = *i + 1;
		return (1);
	}
	if (!_strcmp(argv[0], "env"))
	{
		n = env_handler(argv, head);
		if (n == -1)
		{
			print_error_env(argv);
		}
		free_everything(argv);
		*i = *i + 1;
		return (1);
	}
	if (!_strcmp(argv[0], "setenv") || !_strcmp(argv[0], "unsetenv"))
	{
		setenv_handler(argv, head);
		return (1);
	}
	return (0);
}

/**
 * exit_handler - handles the builtin exit with arguments
 * @tokens: array of strings from the command line
 *
 * Return: 0 if there are no arguments,
 * -1 on failure, or the value of the argument
 */
long long int exit_handler(char **tokens)
{
	int flag = 0, i;
	long long int num = 0;

	if (_strcmp(tokens[0], "exit") == 0)
	{
		if (tokens[1] == NULL)
			return (127);
		for (i = 0; tokens[1][i]; i++)
		{
			if ((tokens[1][i] >= '0' && tokens[1][i] <= '9') || tokens[1][0] == '+')
			{
				flag = 1;
				if (tokens[1][i + 1] < '0' || tokens[1][i + 1] > '9')
					break;
			}
			else
				break;
			flag = 0;
		}
		if (flag == 1)
		{
			num = _atoi(tokens[1]);
			return (num);
		}
	}
	return (-1);
}

/**
 * env_handler - replicates the bash env function
 * @av: array of arguments from the command line
 * @head: double pointer to the env_t linked list
 *
 * Return: 0 on success, -1 on error
 */
int env_handler(char **av, env_t **head)
{
	if (av[1] == NULL)
	{
		print_list(*head);
		return (0);
	}
	return (-1);
}

