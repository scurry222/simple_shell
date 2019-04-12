#include "shell.h"

/**
* exec - handles execution of commands
* @argv: array of arguments from standard input
* @s: name of the program
* @i: index of error
*
* Return: void
*/
void exec(char **argv, char *s, int i)
{
	int status;
	char *exe = NULL;

	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		perror(s);
		free_everything(argv);
		return;
	}
	if (child_pid == 0)
	{
		exe = path_finder(argv);
		if (!exe)
		{
			if (argv[0])
			{
				if (execve(argv[0], argv, environ) == -1)
				{
					print_error(i, s, argv);
					free_everything(argv);
					return;
				}
				free_everything(argv);
			}
		}
		if (execve(exe, argv, environ) == -1)
		{
			print_error(i, s, argv);
			free(exe);
			free_everything(argv);
			return;
		}
	}
	else
		wait(&status);
	free_everything(argv);
}

/**
 * main - simple command-line argument interpreter
 * Description: prints a prompt and waits for the user to input a command,
 * then creates a child process in which it exececutes the command
 * @ac: number of arguments
 * @av: array of arguments
 *
 * Return: Always 0.
 */
int main(int ac, char *av[])
{
	size_t len = 0;
	int i = 1, get;
	char **argv = NULL, *line = NULL, *prog_name = av[0];
	(void)ac;
		
	signal(SIGINT, sigint_handler);

	while (1)
	{
		if (isatty(STDIN_FILENO) != 0 && isatty(STDOUT_FILENO) != 0)
			print_prompt();
		get = getline(&line, &len, stdin);
		if (get < 0)
		{
			if (isatty(STDIN_FILENO) != 0 && isatty(STDOUT_FILENO) != 0)
				_putchar('\n');
			free(line);
			return (0);
		}
		if (_strcmp(line, "\n") == 0)
			continue;
		line[get - 1] = '\0';
		argv = _strtok(line, ' ');
		if (is_builtin(line, prog_name, argv, &i))
			continue;
		exec(argv, prog_name, i);
		i++;
		continue;
	}
	free(line);
	return (0);
}
