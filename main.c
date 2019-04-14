#include "shell.h"

/**
* exec - handles execution of commands
* @input: array of arguments from standard input
* @s: name of the program
* @i: index of error
*
* make child process
* if fork failed, print error, free, and exit
* if not failed,
* if command can be run on its own without path,
* execute command
* set variable "exe" to resulting array of strings containing PATH value
* if exe returned NULL but input is not NULL,
* execute input. if failure, print error, free, and return error
* else if exe did not return NULL,
* execute input. if failure, print error, free all, exit error
* if child process was nut successful, wait
* free the input
*
* Return: return to main loop (1)
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
		if (!exe && input[0])
		{
			if (execve(input[0], input, environ) == -1)
			{
				print_error(i, s, input);
				free_everything(input);
				exit(EXIT_SUCCESS);
			}
			free_everything(input);
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
 * prints a prompt and waits for the user to input a command,
 * then creates a child process in which it exececutes the command
 * @ac: number of arguments
 * @av: array of arguments
 *
 * signal: handles ctrl+C
 * if this shell is running from a terminal, print prompt
 * read from stdin, modify variable "line" to line from stdin
 * if getline failed,
 * newline for terminal user(error message?)
 * quit out of shell with error return
 * increment count of how many calls to the shell were made
 * if just enter is pressed, restart shell loop
 * replace newline with null byte to remove it. possible mem leak?
 * break up inputted line into array of strings at space
 * check if first element a builtin
 * if call to exec failed
 * free input
 *
 * Return: default exit code (0).
 */
int main(int ac, char *av[])
{
	size_t len = 0;
	int cmd_count = 0, get;
	char **input = NULL, *line = NULL, *prog_name = av[0];

	if (ac != 1)
	{
		print_error_main(av);
		exit(127);
	}
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
			return (1);
		}
		cmd_count++;
		if (_strcmp(line, "\n") == 0)
			continue;
		line[get - 1] = '\0';
		input = _strtok(line, ' ');
		if (is_builtin(line, prog_name, input, &cmd_count))
			continue;
		if (!exec(input, prog_name, &cmd_count))
			break;
		continue;
	}
	free(line);
	return (0);
}
