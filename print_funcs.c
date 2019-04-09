#include "shell.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

void print_error(int i, char *s, char **argv)
{
	char *buf = str_concat(s, ": ");
	char *number = convert(i, 10);

	if (errno == ENOENT || errno == ENOTDIR)
	{
		buf = str_concat(buf, number);
		buf = str_concat(buf, ": ");
		buf = str_concat(buf, argv[0]);
		buf = str_concat(buf, ": not found\n");

		write(2, buf, _strlen(buf));
	}
	else
		perror(s);
}

/**
 * print_prompt - prints a prompt for the shell
 */
void print_prompt(void)
{
	char *s = "($) ";
	write(2, s, 5);
}

/**
 * print_env - replicates the bash env function
 * @av: array of arguments from the command line
 */
int print_env(char **av)
{
	int i, j;

	if (_strcmp(av[0], "env") == 0 && av[1] == NULL)
	{
		for (i = 0; environ[i]; i++)
		{
			for (j = 0; environ[i][j]; j++)
				_putchar(environ[i][j]);
			_putchar('\n');
		}
		return (0);
	}
	return (-1);
}
