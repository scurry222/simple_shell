#include "shell.h"

/**
 * _atoi - converts a string to an integer
 * @s: string to be converted
 *
 * Return: the int converted from the string
 */
long long int _atoi(char *s)
{
	int i, len, f, digit;
	long long int n;

	i = 0;
	n = 0;
	len = _strlen(s);
	f = 0;
	digit = 0;

	if (s[i] == '+')
		i++;

	while (i < len && f == 0)
	{
		if (s[i] == '-')
			return (-1);

		if (s[i] >= '0' && s[i] <= '9')
		{
			digit = s[i] - '0';
			n = n * 10 + digit;
			f = 1;
			if (s[i + 1] < '0' || s[i + 1] > '9')
				break;
			f = 0;
		}
		i++;
	}

	if (f == 0)
		return (0);

	if (n > INT_MAX || n < 0)
		return (-1);

	return (n);
}

/**
 * convert - converts number and base into string
 * @num: input number
 * @base: input base
 * Return: result string
 */
char *convert(int num, int base)
{
	static char *rep = "0123456789";
	static char buffer[50];
	char *ptr;

	ptr = &buffer[49];
	*ptr = '\0';
	do {
		*--ptr = rep[num % base];
		num /= base;
	} while (num != 0);

	return (ptr);
}
