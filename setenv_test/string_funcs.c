#include "list.h"


/**
* _strdup - make new place in memory for a string
* @str: string to duplicate
*
* Return: New string on success, null if memory allocation failed
*/

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
 * _strlen - returns the length of a string
 * @s: string to evaluate
 *
 * Return: the length of the string
 */
int _strlen(char *s)
{
        unsigned int len = 0;

        if (!s)
                return (0);

        while (s[len])
                len++;

        return (len);
}
