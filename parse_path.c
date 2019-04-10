#include "shell.h"

/**
* strtok_count - count the amount of tokens returned from strtok
* @value: original string (value of PATH)

* Return: count of tokens
*/

int _strtok_count(char **value)
{
	int count = 0, i;

	for (i = 0; value[i]; i++)
		count++;

	return (count);
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
		{
			free_everything(path);
			free_everything(value);
		}
	}
	free_everything(path);
	free_everything(value);
	return (NULL);
}
/**
* path_finder - connect dirs in PATH with inputted command, check if executable
* @s: input, in form array of strings
*
* Return: concat'ed string 
*/

char *path_finder(char **s)
{
	int i;
	char *dir = NULL;
	char *prog = NULL;
	char **path_value = NULL;

	path_value = get_env("PATH");
	if (path_value[0][0] != '/' || !path_value)
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
