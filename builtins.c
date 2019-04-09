#include "shell.h"

void exit_handler(char **tokens)
{
	int flag = 0, i, num;

	if (_strcmp(tokens[0], "exit") == 0)
	{
		if (tokens[1] == NULL)
			exit(EXIT_SUCCESS);
		else
		{
			for (i = 0; tokens[1][i]; i++)
			{
				if (tokens[1][i] >= '0' && tokens[1][i] <= '9')
				{
					flag = 1;
					if (tokens[1][i + 1] < '0' || tokens[1][i + 1] > '9')
						break;
				}
			}
			if (flag == 1)
			{
				num = _atoi(tokens[1]);
				exit(num);
			}
		}
	}
}

/**
 * _atoi - converts a string to an integer
 * @s: string to be converted
 *
 * Return: the int converted from the string
 */
int _atoi(char *s)
{
	int i, d, n, len, f, digit;

	i = 0;
	d = 0;
	n = 0;
	len = 0;
	f = 0;
	digit = 0;

	while (s[len] != '\0')
		len++;

	while (i < len && f == 0)
	{
		if (s[i] == '-')
			++d;

		if (s[i] >= '0' && s[i] <= '9')
		{
			digit = s[i] - '0';
			if (d % 2)
				digit = -digit;
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
