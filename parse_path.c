#include "header.h"

int _strlen(char *s)
{
        unsigned int len = 0;

        while (s[len])
                len++;

        return (len);
}

void parse_path(char *value, char *arr[])
{
	char *token;
	int i;
	int count = 0;

	count = strtok_count(value);
	arr = malloc(sizeof(char *) * (count + 1));
	if (!arr)
		return;

	token = strtok(value, ":");
	arr[0] = malloc(sizeof(char) * _strlen(token));
	if (!arr[0])
		return;

	arr[0] = token;
	printf("saved in list: %s\n", arr[0]);

	for (i = 0; (token = strtok(NULL, ":")); i++)
	{
		arr[i] = malloc(sizeof(char) * _strlen(token));
		if (!arr[i])
			return;
		arr[i] = token;
		printf("ssaved in list: %s\n", arr[i]);
	}
	arr[i] = NULL;
}
