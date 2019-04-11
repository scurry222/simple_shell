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

/**
 * print_error - prints a custom error message
 * @i: index of the command in history
 * @s: name of the program
 * @argv: array of arguments from the command line
 */
void print_error(int i, char *s, char **argv)
{
	char *buf = _strcat(s, ": ");
	char *number = convert(i, 10);

	if (errno == ENOENT || errno == ENOTDIR)
	{
		buf = _strcat(buf, number);
		buf = _strcat(buf, ": ");
		buf = _strcat(buf, argv[0]);
		buf = _strcat(buf, ": not found\n");
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
	char *s = "$ ";

	write(2, s, 2);
}

/**
 * print_error_env - prints a custom error message for env builtin
 * @argv: array of arguments from the command line
 */
void print_error_env(char **argv)
{
	char *buf = str_concat(argv[0], ": ");

	buf = str_concat(buf, argv[1]);
	buf = str_concat(buf, ": No such file or directory\n");
	write(2, buf, _strlen(buf));
	free(buf);
}

/**
 * print_error_exit - prints a custom error message for exit builtin
 * @i: index of the command in history
 * @s: name of the program
 * @argv: array of arguments from the command line
 */
void print_error_exit(int i, char *s, char **argv)
{
	char *buf = str_concat(s, ": ");
	char *number = convert(i, 10);

	buf = str_concat(buf, number);
	buf = str_concat(buf, ": ");
	buf = str_concat(buf, argv[0]);
	buf = str_concat(buf, ": Illegal number: ");
	buf = str_concat(buf, argv[1]);
	buf = str_concat(buf, "\n");
	write(2, buf, _strlen(buf));
	free(buf);
}
