#include <stdlib.h>
#include "shell.h"

int wordcount(char *str, char delim)
{
	int num = 0, i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == delim)
			str++;
		else
		{
			while (str[i] != delim && str[i])
				i++;
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
	char *cpy, **words;
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
	return (words);
}
