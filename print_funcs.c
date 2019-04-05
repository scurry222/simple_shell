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

void print_prompt(void)
{
	char *s = "(s) ";

	while (*s)
	{
		_putchar(*s);
		s++;
	}
}

void print_env(void)
{
	int i, j;

	for (i = 0; environ[i]; i++)
	{
		for (j = 0; environ[i][j]; j++)
			_putchar(environ[i][j]);
		_putchar('\n');
	}
}
