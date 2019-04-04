#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "header.h"
#include <unistd.h>
#include <fcntl.h>

void *_realloc(void *ptr, unsigned int new_size)
{
	char *new, *old;
	unsigned int i;

	if (ptr && new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	if (!ptr)
		return (malloc(new_size));

	old = ptr;

	new = malloc(new_size);

	if (!new)
		return (NULL);

	for (i = 0; i < new_size; i++)
		new[i] = old[i];

	free(ptr);
	return (new);
}

int _strlen(char *s)
{
	int i;

	for (i = 0; s[i]; i++)
		;
	return (i);
}

char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i]; i++)
		dest[i] = src[i];

	return (dest);
}

int _getline(char **string, size_t *n, FILE *stream)
{
	static char buffer[256];
	int len2, fd, r, i;
	char *ptr;

	if (!string || !n)
		return (-1);

	fd = open(??????????, O_RDONLY);
	if (fd == -1)
		return (-1);

	r = read(fd, buffer, 256);
	if (r == -1)
		return (-1);

	for (i = 0; *string[i]; i++)
		if (*string[i] == '\n')
			*string[i] = '\0';

	len2 = _strlen(buffer);
	if ((len2 + 1) < 256)
	{
		ptr = realloc(*string, 256);
		if (!ptr)
			return (-1);
		*string = ptr;
		*n = 256;
	}
	_strcpy(*string, buffer);
	return (len2);
}
