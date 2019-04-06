#include "shell.h"

int strtok_count(char *value)
{
	char *valcopy = NULL;
	char *token;
	int count = 0, i;

	valcopy = _strdup(value);

	token = strtok(valcopy, ":");
		count++;

	for (i = 0; (token = strtok(NULL, ":")); i++)
		count++;

	return (count);
}

char *get_env(char *name)
{
	char **env, *value = NULL, *pathname = NULL;
	int i;

	env = environ;

	for (i = 0; env[i]; i++)
	{
		pathname = strtok(env[i], "=");
		if (_strcmp(name, pathname) == 0)
		{
			value = strtok(NULL, env[i]);
			break;
		}
	}
	return (value);
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

char *path_finder(char **s)
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
		prog = str_concat(dir, s[0]);
		free(dir);
		if (access(prog, X_OK) == 0)
			return (prog);
		else
			free(prog);
	}

	return (NULL);
}
