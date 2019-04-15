#include "shell.h"

/**
* _strdup - make new place in memory for a string
* @str: string to duplicate
*
* Return: New string on success, null if memory allocation failed
*/

char *_strdup(const char *str)
{
	char *dup;
	int c, i = 0;

	if (!str)
		return (NULL);

	while (str[i])
		i++;

	dup = malloc(sizeof(char) * (i + 1));
	if (!dup)
		return (NULL);

	for (c = 0; c < i; c++)
		dup[c] = str[c];

	dup[c] = '\0';

	return (dup);
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
	char *s3 = NULL;
	unsigned int i = 0, j = 0, len1 = 0, len2 = 0;

	len1 = _strlen(s1);
	len2 = _strlen(s2);

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

/**
 * _strcmp - compares two strings
 * @s1: first string to compare
 * @s2: second string to compare
 *
 * Return: less than 0 if s1 is less than s2, 0 if they're equal,
 * more than 0 if s1 is greater than s2
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
		{
			return (0);
		}
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

/**
* _strncmp - compare strings up to n bytes
* @s1: string to compare against
* @s2: string to compare from
* @n: number of bytes to compare
*
* Return: differences between strings
*/
int _strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int i = 0;

	while (*s1 == *s2 && i < n)
	{
		if (*s1 == '\0')
		{
			return (0);
		}
		s1++;
		s2++;
		i++;
	}
	return (i != n);
}


/**
 * *_strstr - locates a substring
 * @haystack: string to search in
 * @needle: substring to look for
 *
 * Return: pointer to the beginning of the located substring
 * or NULL if the substring is not found
 */
char *_strstr(char *haystack, char *needle)
{
	int i, j;

	for (i = 0; haystack[i] != '\0'; i++)
	{
		for (j = 0; needle[j] != '\0'; j++)
		{
			if (haystack[i + j] != needle[j])
				break;
		}
		if (!needle[j])
			return (&haystack[i]);
	}
	return (NULL);
}
