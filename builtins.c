#include "shell.h"

int exit_handler(char **tokens)
{
	int flag = 0, i, num = 0;

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
				num = atoi(tokens[1]);
				exit(num);
			}
		}
	}
	return (num);
}

/**
 * _atoi - converts a string to an integer
 * @s: string to be converted
 *
 * Return: the int converted from the string
 */
int _atoi(const char *str)
{
	int i = 0, base = 0, sign = 1;

	while (str[i] >= '0' && str[i] <= '9')
	{
		if (str[i] == '-' || str[i] == '+')
		{
			sign = 1 - 2 * (str[i++] == '-');  
		} 
		if (base >  INT_MAX / 10 || (base == INT_MAX / 10 && str[i] - '0' > 7))
		{
			if (sign == 1)
				return INT_MAX;
			else
				return INT_MIN;
		}
		base  = 10 * base + (str[i++] - '0');

	}
	return (base * sign);
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
