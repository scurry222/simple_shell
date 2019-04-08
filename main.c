#include "shell.h"

/**
* exec - handles execution of commands
* @ch: line from standard input to be parsed
*
* Return: void
*/

void exec(char *ch)
{
	char *exe;
	char **argv;
	struct stat filestat;

	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		perror("./shell");
		exit(1);
	}
	if (child_pid == 0)
	{
		argv = strtow(ch);
               	exe = path_finder(argv);
                if (!exe)
                {
                       	if (execve(argv[0], argv, environ) < 0)
			{
                                perror("./shell");
				//free_everything(argv);
                                exit(1);
			}
		}
                if (execve(exe, argv, environ) < 0)
                {
                       	perror("./shell");
		//	free_everything(argv);
                        exit(1);
                }
	}	
	else
		wait(NULL);
	free_everything(argv);
}

/**
 * main - simple command-line argument interpreter
 * Description: prints a prompt and waits for the user to input a command,
 * then creates a child process in which it exececutes the command
 * Return: Always 0.
 */
int main(void)
{
	size_t len = 0;
	int get;
	char *ch;

	while (1)
	{
		if (isatty(STDIN_FILENO) != 0)
			print_prompt();
		get = getline(&ch, &len, stdin);
		if (get < 0)
		{
			if (isatty(STDIN_FILENO) != 0)
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
		exec(ch);
		continue;
	}
	return (0);
}
