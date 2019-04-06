#include "shell.h"

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
