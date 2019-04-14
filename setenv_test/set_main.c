#include "list.h"

int main(void)
{
	env_t *head = NULL;
	int index = 0;

	arr_to_list(&head);

	printf("This is the environ variable:\n\n");
	print_list(head);

	index = find_index_list("PATH", &head);

	printf("\nThis is the index of the PATH: %d\n", index);

	return 0;
}
