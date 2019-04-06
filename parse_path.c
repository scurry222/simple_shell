#include "shell.h"

int _strlen(char *s)
{
        unsigned int len = 0;

        while (s[len])
                len++;

        return (len);
}
/**
 * *str_concat - concatenates two strings
 * @s1: string to concatenate
 * @s2: other string to concatenate
 *
 * Return: pointer to the new string created (Success), or NULL (Error)
 */
char *str_concat(char *s1, char *s2)
{
	char *s3;
	unsigned int i = 0, j = 0, len1 = 0, len2 = 0;

	while (s1 && s1[len1])
		len1++;
	while (s2 && s2[len2])
		len2++;

	s3 = malloc(sizeof(char) * (len1 + len2 + 1));
	if (s3 == NULL)
		return (NULL);

	i = 0;
	j = 0;

	if (s1)
	{
		while (i < len1)
		{
			s3[i] = s1[i];
			i++;
		}
	}

	if (s2)
	{
		while (i < (len1 + len2))
		{
			s3[i] = s2[j];
			i++;
			j++;
		}
	}
	s3[i] = '\0';

	return (s3);
}

char **parse_path(char *value)
{
	char *token;
	char **arr;
	int i;
	int count = 0;

	count = strtok_count(value);
	arr = malloc(sizeof(char *) * (count + 1));
	if (!arr)
		return (NULL);

	token = strtok(value, ":");
	arr[0] = malloc(sizeof(char) * _strlen(token));
	if (!arr[0])
		return (NULL);

	arr[0] = token;

	for (i = 0; (token = strtok(NULL, ":")); i++)
	{
		arr[i] = malloc(sizeof(char) * _strlen(token));
		if (!arr[i])
			return (NULL);
		arr[i] = token;
	}
	arr[i] = NULL;
	return (arr);
}

char *path_finder(char *s)
{
	int i;
	char *path;
	char *dir;
	char *prog;
	char **path_arr;

	path = get_env("PATH");

	path_arr = parse_path(path);

	for (i = 0; path_arr[i]; i++)
	{
		dir = str_concat(path_arr[i], "/");
		prog = str_concat(dir, s);
		free(dir);
		if (access(prog, X_OK) == 0)
			return (prog);
		else
			free(prog);
	}

	return (NULL);
}
