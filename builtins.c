#include "shell.h"

/**
 * exit_handler - handles the builtin exit with arguments
 * @tokens: array of strings from the command line
 *
 * Return: 0 if there are no arguments,
 * -1 on failure, or the value of the argument
 */
long long int exit_handler(char **tokens)
{
	int flag = 0, i;
	long long int num = 0;

	if (_strcmp(tokens[0], "exit") == 0)
	{
		if (tokens[1] == NULL)
			return (0);
		for (i = 0; tokens[1][i]; i++)
		{
			if (tokens[1][i] >= '0' && tokens[1][i] <= '9')
			{
				flag = 1;
				if (tokens[1][i + 1] < '0' || tokens[1][i + 1] > '9')
					break;
			}
			flag = 0;
		}
		if (flag == 1)
		{
			num = _atoi(tokens[1]);
			return (num);
		}
	}
	return (-1);
}

/**
 * print_env - replicates the bash env function
 * @av: array of arguments from the command line
 *
 * Return: 0 on success, -1 on error
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

/**
 * _atoi - converts a string to an integer
 * @s: string to be converted
 *
 * Return: the int converted from the string
 */
long long int _atoi(char *s)
{
	int i, len, f, digit;
	long long int n;

	i = 0;
	n = 0;
	len = _strlen(s);
	f = 0;
	digit = 0;

	while (i < len && f == 0)
	{
		if (s[i] == '-')
			return (-1);

		if (s[i] >= '0' && s[i] <= '9')
		{
			digit = s[i] - '0';
			n = n * 10 + digit;
			f = 1;
			if (s[i + 1] < '0' || s[i + 1] > '9')
				break;
			f = 0;
		}
		i++;
	}

	if (f == 0)
		return (0);

	if (n > INT_MAX || n < 0)
		return (-1);

	return (n);
}

/**
 * *_strstr - locates a substring
 * @haystack: string to search in
 * @needle: substring to look for
 *
 * Return: pointer to the beginning of the located substring
 * or NULL if the substring is not found
 */
char *_strstr(char *haystack, char *needle)
{
	int i, j;

	for (i = 0; haystack[i] != '\0'; i++)
	{
		for (j = 0; needle[j] != '\0'; j++)
		{
			if (haystack[i + j] != needle[j])
				break;
		}
		if (!needle[j])
			return (&haystack[i]);
	}
	return (NULL);
}
