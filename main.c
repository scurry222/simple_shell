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
	char *exe;

	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		perror("./shell");
		exit(1);
	}
	if (child_pid == 0)
	{
               	exe = path_finder(argv);
                if (!exe)
                {
                       	if (argv[0] && execve(argv[0], argv, environ) == -1)
			{
				print_error(i, s, argv);
				//free_everything(argv);
				exit(1);
			}
		}
                if (execve(exe, argv, environ) == -1)
                {
			print_error(i, s, argv);
		//	free_everything(argv);
                        exit(1);
                }
	}	
	else
	{
		wait(&status);
	}
	free_everything(argv);
}

/**
 * main - simple command-line argument interpreter
 * Description: prints a prompt and waits for the user to input a command,
 * then creates a child process in which it exececutes the command
 * @ac: number of arguments
 * @av: array of arguments
 * Return: Always 0.
 */
int main(int ac, char *av[])
{
	size_t len = 0;
	int i = 1;
	int get;
	char *ch;
	char **argv;
	(void)ac;

	while (1)
	{
		if (isatty(STDIN_FILENO) != 0 && isatty(STDOUT_FILENO) != 0)
			print_prompt();
		get = getline(&ch, &len, stdin);
		if (get < 0)
		{
			if (isatty(STDIN_FILENO) != 0 && isatty(STDOUT_FILENO) != 0)
				_putchar('\n');
			return (0);
		}
		if (_strcmp(ch, "exit\n") == 0)
		{
			free(ch);
			exit(EXIT_SUCCESS);
		}
		if (_strcmp(ch, "env\n") == 0)
		{
			print_env();
			continue;
		}
		if (_strcmp(ch, "\n") == 0)
			continue;
		strtok(ch, "\n");
		argv = strtow(ch);
		exec(argv, av[0], i);
		i++;
		continue;
	}
	return (0);
}
