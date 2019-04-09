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
	char **env, **value, **path;
	int i;

	env = environ;

	for (i = 0; env[i]; i++)
	{
		path = _strtok(env[i], '=');
		if (_strcmp(name, path[0]) == 0)
		{
			value = _strtok(path[1], ':');
			return (value);
		}
	}
	free(path);
	return (NULL);
}

/**
* parse_path - turn PATH string into array of strings (one dir per string)
* @value: string containing all dirs in path
*
* Return: array of strings
*/
/*
char **parse_path(char *value)
{
	char **arr;

//	printf("Entering parse_path\n");

	if (value[0] != '/' || !value)
		return (NULL);

	arr = _strtok(value, ':');
//	printf("This is the first element of the path: %s\n", arr[0]);
	if (!arr)
		return (NULL);

	return (arr);
}
*/
/**
* path_finder - connect dirs in PATH with inputted command, check if executable
* @s: input, in form array of strings
*
* Return: concat'ed string 
*/

char *path_finder(char **s)
{
	int i;
	char *dir;
	char *prog;
	char **path_value;

	path_value = get_env("PATH");
	if (path_value[0][0] != '/' || !path_value)
		return (NULL);
	//printf("in pathfinder\n");
	/*path_arr = parse_path(path_value);
	if (!path_arr)
		return (NULL);*/

	for (i = 0; path_value[i]; i++)
	{
		dir = str_concat(path_value[i], "/");
		prog = str_concat(dir, s[0]);
		free(dir);
		if (access(prog, X_OK) == 0)
			return (prog);
		else
			free(prog);
	}

	return (NULL);
}
