#include "shell.h"

char *get_env_val(char *name)
{
	char **env = NULL;
	int i;

	env = environ;

	for (i = 0; env[i]; i++)
		if (_strncmp(env[i], name, strlen(name)) == 0)
			return (env[i] + _strlen(name));
	return (NULL);
}

/**
* get_env - access environment to get value at passed in name
* @name: key (key=value) to select in env
*
* Return: value at key
*/

char **get_env(char *name)
{
	char **env = NULL, **value = NULL, **path = NULL;
	int i;

	env = environ;

	for (i = 0; env[i]; i++)
	{
		path = _strtok(env[i], '=');
		if (_strcmp(name, path[0]) == 0)
		{
			value = _strtok(path[1], ':');
			free_everything(path);
			return (value);
		}
		else
			free_everything(path);
	}
	free_everything(path);
	free_everything(value);
	return (NULL);
}
/**
* path_finder - connect dirs in PATH with inputted command, check if executable
* @s: input, in form array of strings
*
* Return: concatenated string
*/

char *path_finder(char **s)
{
	int i;
	char *dir = NULL;
	char *prog = NULL;
	char **path_value = NULL;

	path_value = get_env("PATH");

	if (!path_value)
	{
		free_everything(path_value);
		return (NULL);
	}

	for (i = 0; path_value[i]; i++)
	{
		dir = str_concat(path_value[i], "/");
		prog = str_concat(dir, s[0]);

		if (access(prog, X_OK) == 0)
		{
			free_everything(path_value);
			free(dir);
			return (prog);
		}
		free(dir);
		free(prog);
	}
	free_everything(path_value);
	return (NULL);
}
