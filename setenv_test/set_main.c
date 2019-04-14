#include "list.h"

int main(void)
{
	env_t *head = NULL;
	int status = 0;

	arr_to_list(&head);

	printf("This is the environ variable:\n\n");
	print_list(head);

	status = _setenv(&head, "FOO", "bar");
	if (status != 0)
		printf("error\n");
	print_list(head);
	status = _setenv(&head, "FOO", "");
	if (status != 0)
		printf("error\n");
	print_list(head);

	status = _unsetenv(&head, "FOO");
	if (status != 0)
		printf ("error\n");
	print_list(head);

	return 0;
}
