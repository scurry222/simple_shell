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
	static char *buf;
	char *number = convert(*i, 10);

	buf = _strcat(s, ": ");
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
	buf[0] = '\0';
}

/**
 * print_error_env - prints a custom error message for env builtin
 * @argv: array of arguments from the command line
 */
void print_error_env(char **argv)
{
	static char *buf;
	
	buf = _strcat(argv[0], ": ");

	buf = _strcat(buf, argv[1]);
	buf = _strcat(buf, ": No such file or directory\n");
	write(2, buf, _strlen(buf));
	buf[0] = '\0';
}

/**
 * print_error_exit - prints a custom error message for exit builtin
 * @i: index of the command in history
 * @s: name of the program
 * @argv: array of arguments from the command line
 */
void print_error_exit(int *i, char *s, char **argv)
{
	static char *buf;
	
	buf = _strcat(s, ": ");
	char *number = convert(*i, 10);

	buf = _strcat(buf, number);
	buf = _strcat(buf, ": ");
	buf = _strcat(buf, argv[0]);
	buf = _strcat(buf, ": Illegal number: ");
	buf = _strcat(buf, argv[1]);
	buf = _strcat(buf, "\n");
	write(2, buf, _strlen(buf));
	buf[0] = '\0';
}
