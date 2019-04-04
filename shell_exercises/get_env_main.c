#include "header.h"

int main(void)
{
	char *value, *name = "PATH";

	value = get_env(name);

	printf("value of %s is %s\n", name, value);

	return (0);
}
