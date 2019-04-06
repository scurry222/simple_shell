#include "shell.h"

void exec(char *ch, char **argv)
{
	char *exe;

	if (access(ch, X_OK) == 0)
	{
		if (execve(ch, argv, NULL) < 0)
		{
			perror("./shell");
			return;
		}
	}
	else
	{
		exe = path_finder(ch);
		if (execve(exe, argv, NULL) < 0)
		{
			perror("./shell");
			return;
		}
	}
}

/**
 * main - simple command-line argument interpreter
 * Description: prints a prompt and waits for the user to input a command,
 * then creates a child process in which it exececutes the command
 * Return: Always 0.
 */
int main(void)
{
	pid_t child_pid;
	size_t len = 0;
	int get;
	char *ch;
	char *argv[] = {"/bin", NULL};

	while (1)
	{
		print_prompt();
		get = getline(&ch, &len, stdin);
		if (get < 0)
		{
			_putchar('\n');
			return (0);
		}
		if (_strcmp(ch, "exit\n") == 0)
			exit(EXIT_SUCCESS);
		if (_strcmp(ch, "env\n") == 0)
		{
			print_env();
			continue;
		}
		strtok(ch, "\n");
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("./shell");
			continue;
		}
		if (child_pid == 0)
			exec(ch, argv);
		else
		{
			wait(NULL);
			continue;
		}
	}
	free(ch);
	return (0);
}

