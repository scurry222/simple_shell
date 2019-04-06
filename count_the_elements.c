#include "shell.h"

char *_strdup(char *str)
{
	char *dup;
	int c, i = 0;

	if (!str)
		return (NULL);

	while (str[i])
		i++;

	dup = malloc(sizeof(char) * i + 1);

	if (!dup)
		return (NULL);

	for (c = 0; c < i; c++)
		dup[c] = str[c];

	dup[c] = '\0';

	return (dup);
}

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
