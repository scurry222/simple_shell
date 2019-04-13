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
 * print_prompt - prints a prompt for the shell
 */
void print_prompt(void)
{
	char *s = "$ ";

	write(2, s, 2);
}

/**
 * print_error - prints a custom error message
 * @i: index of the command in history
 * @s: name of the program
 * @argv: array of arguments from the command line
 */
void print_error(int *i, char *s, char **argv)
{
	char *buf1, *buf2, *buf3, *buf4, *buf5;
	char *number = convert(*i, 10);

	if (errno == ENOENT || errno == ENOTDIR)
	{
		buf1 = str_concat(s, ": ");
		buf2 = str_concat(buf1, number);
		free(buf1);
		buf3 = str_concat(buf2, ": ");
		free(buf2);
		buf4 = str_concat(buf3, argv[0]);
		free(buf3);
		buf5 = str_concat(buf4, ": not found\n");
		free(buf4);
		write(2, buf5, _strlen(buf5));
		free(buf5);
	}
	else
		perror(s);
}

/**
 * print_error_env - prints a custom error message for env builtin
 * @argv: array of arguments from the command line
 */
void print_error_env(char **argv)
{
	char *buf1, *buf2, *buf3;

	buf1 = str_concat(argv[0], ": ");
	buf2 = str_concat(buf1, argv[1]);
	free(buf1);
	buf3 = str_concat(buf2, ": No such file or directory\n");
	free(buf2);
	write(2, buf3, _strlen(buf3));
	free(buf3);
}

/**
 * print_error_exit - prints a custom error message for exit builtin
 * @i: index of the command in history
 * @s: name of the program
 * @argv: array of arguments from the command line
 */
void print_error_exit(int *i, char *s, char **argv)
{
	char *buf1, *buf2, *buf3, *buf4, *buf5, *buf6, *buf7;
	char *number = convert(*i, 10);

	buf1 = str_concat(s, ": ");

	buf2 = str_concat(buf1, number);
	free(buf1);
	buf3 = str_concat(buf2, ": ");
	free(buf2);
	buf4 = str_concat(buf3, argv[0]);
	free(buf3);
	buf5 = str_concat(buf4, ": Illegal number: ");
	free(buf4);
	buf6 = str_concat(buf5, argv[1]);
	free(buf5);
	buf7 = str_concat(buf6, "\n");
	free(buf6);
	write(2, buf7, _strlen(buf7));
	free(buf7);
}
