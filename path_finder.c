#include "shell.h"

/**
* get_env_val - run commands if defined explicitly without PATH
* @name: env key to check
* @env: array of strings containing environment copy
*
* loop through strings in env
* if the name compares,
*
* Return: string at value in env
*/

char *get_env_val(char *name, char **env)
{
	int i;

	for (i = 0; env[i]; i++)
		if (_strncmp(env[i], name, _strlen(name)) == 0)
			return (env[i] + _strlen(name));
	return (NULL);
}

/**
* get_env - access environment to get value at passed in name
* @name: key (key=value) to select in env
* @env: array of strings containing the environment copy
*
* Return: value at key
*/

char **get_env(char *name, char **env)
{
	char **value = NULL, **path = NULL;
	int i;

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
* @env: array of strings containing the environment copy
*
* call get_env to get value at PATH, save into path_value
* if failure, free and return NULL
* loop through strings in path_value
* cat dir in PATH with command
* if executable, free variables and return catted string to exec func
* if not, free variables and go to next dir
* if no dirs worked, return NULL
*
* Return: concatenated string on success, NULL if failure
*/

char *path_finder(char **s, char **env)
{
	int i;
	char *dir = NULL;
	char *prog = NULL;
	char **path_value = NULL;

	path_value = get_env("PATH", env);
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
