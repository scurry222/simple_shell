#include "shell.h"

/**
* exec - handles execution of commands
* @input: array of arguments from standard input
* @s: name of the program
* @i: index of error
*
* Return: void
*/
int exec(char **input, char *s, int *i)
{
	int status;
	char *exe = NULL;
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror(s);
		free_everything(input);
		exit(EXIT_SUCCESS);
	}
	if (child_pid == 0)
	{
		if (get_env_val("PATH=")[0] != '/')
			execve(input[0], input, environ);
		
		exe = path_finder(input);
		if (!exe)
		{
			if (input[0])
			{
				if (execve(input[0], input, environ) == -1)
				{
					print_error(i, s, input);
					free_everything(input);
					//exit(EXIT_SUCCESS);
					return (0);
				}
				free_everything(input);
			}
		}

		if (execve(exe, input, environ) == -1)
		{
			print_error(i, s, input);
			free(exe);
			free_everything(input);
			exit(EXIT_SUCCESS);
		}
	}
	else
		wait(&status);
	free_everything(input);
	return (1);
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
	int cmd_count = 1, get;
	char **input = NULL, *line = NULL, *prog_name = av[0];
	(void)ac;
		
	signal(SIGINT, sigint_handler);		//handles ctrl+C

	while (1)
	{
		
		if (isatty(STDIN_FILENO) != 0 && isatty(STDOUT_FILENO) != 0)	//if this shell is running from a terminal
			print_prompt();
		get = getline(&line, &len, stdin);	//read from stdin, modify line str  to line from stdin
		if (get < 0)	//if failure,
		{
			if (isatty(STDIN_FILENO) != 0 && isatty(STDOUT_FILENO) != 0)
				_putchar('\n');		//newline for terminal user(error message?)
			free(line);
			return (1);			//quit out of shell with error return
		}
		if (_strcmp(line, "\n") == 0)		//if just enter is pressed
			continue;
		line[get - 1] = '\0';			//replace newline with null byte to remove it. could this have mem leak due to second null?
		input = _strtok(line, ' ');		//break up inputted line into array of strings at space
		if (is_builtin(line, prog_name, input, &cmd_count))	//is the first element a builtin?
			continue;
		if (!exec(input, prog_name, &cmd_count))			//if call to exec failed
			break;
		cmd_count++;						//count how many calls to the shell were made
		continue;
	}
	free(line);					//free input
	return (0);					//default exit code
}
