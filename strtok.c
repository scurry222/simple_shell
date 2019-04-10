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
//			while (str[i] != delim && str[i])
//				i++;
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
