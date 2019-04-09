#include "shell.h"

/**
*
*
*
*/

char *strskp(char *val, char delim)
{
        char *valcpy;

        if (!*val)
                return (NULL);

        valcpy = malloc(sizeof(char) * _strlen(val));
        if (!valcpy)
                return (NULL);

        while (*val)
        {
		if (*val == delim && *val)
		{
			*valcpy = '\0';
			return (valcpy);
		}
		else
			*valcpy = *val;
        }
        return (NULL);
}
