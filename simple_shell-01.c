#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "shell.h"

/**
 * main - simple command-line argument interpreter
 *
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
		printf("($) ");
		get = getline(&ch, &len, stdin);
		if (get < 0)
		{
			printf("\n");
			return (0);
		}
		if (strcmp(ch, "exit\n") == 0)
			exit(EXIT_SUCCESS);
		strtok(ch, "\n");
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("./shell");
			continue;
		}
		if (child_pid == 0)
		{
			if (execve(ch, argv, NULL) < 0)
			{
				perror("./shell");
				return (0);
			}
		}
		else
		{
			wait(NULL);
			continue;
		}
	}
	free(ch);
	return (0);
}
