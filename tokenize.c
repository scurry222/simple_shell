#include <stdlib.h>
#include "shell.h"

int wordcount(char *str, char delim)
{
	int num = 0, i;
	int flag = 0;

	for (i = 0; str[i]; i++)
	{
		if (str[i] == delim)
			flag = 0;
		else if (flag == 0)
		{
			flag = 1;
			num++;
		}
	}
	return (num);
}

/**
* strtow - convert input str into a double string
* @str: string to separate
*
* Return: double pointer to the words on success, null if fail
*/

char **_strtok(char *str, char delim)
{
	char *cpy = NULL, **words = NULL;
	int i = 0, j = 0, len = 0, total = 0;

	if (str == 0 || *str == 0)
		return (NULL);
	total = wordcount(str, delim);
	if (total == 0)
		return (NULL);
	words = malloc(sizeof(char *) * (total + 1));
	if (words == NULL)
		return (NULL);
	while (*str && i < total)
	{
		if (*str == delim)
			str++;
		else
		{
			cpy = str;
			while (*str != delim && *str)
			{
				len++;
				str++;
			}
			words[i] = malloc(sizeof(char) * (len + 1));
			if (!words[i])
				return (NULL);
			while (*cpy != delim && *cpy && *cpy != '\n')
			{
				words[i][j] = *cpy;
				cpy++;
				j++;
			}
			words[i][j] = '\0';
			i++;
			j = 0;
			len = 0;
		}
	}
	words[i] = NULL;
	return (words);
}

/**
 * count_word - helper function to count the number of words in a string
 * @s: string to evaluate
 *
 * Return: number of words
 */
int count_word(char *s)
{
	int flag, c, w;

	flag = 0;
	w = 0;

	for (c = 0; s[c] != '\0'; c++)
	{
		if (s[c] == ' ')
			flag = 0;
		else if (flag == 0)
		{
			flag = 1;
			w++;
		}
	}

	return (w);
}
/**
 * **strtow - splits a string into words
 * @str: string to split
 *
 * Return: pointer to an array of strings (Success)
 * or NULL (Error)
 */
char **strtow(char *str)
{
	char **matrix = NULL, *tmp = NULL;
	int i, k = 0, len = 0, words, c = 0, start, end;

	while (*(str + len))
		len++;
	words = count_word(str);
	if (words == 0)
	{
		free(str);
		return (NULL);
	}

	matrix = malloc(sizeof(char *) * (words + 1));
	if (matrix == NULL)
	{
		free(str);
		return (NULL);
	}

	for (i = 0; i <= len; i++)
	{
		if (str[i] == ' ' || str[i] == '\0')
		{
			if (c)
			{
				end = i;
				tmp = malloc(sizeof(char) * (c + 1));
				if (tmp == NULL)
					return (NULL);
				while (start < end)
					*tmp++ = str[start++];
				*tmp = '\0';
				matrix[k] = tmp - c;
				k++;
				c = 0;
			}
		}
		else if (c++ == 0)
			start = i;
	}

	matrix[k] = NULL;

	return (matrix);
}
