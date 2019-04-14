#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

extern char **environ;
/**
 * struct list_s - singly linked list
 * @str: string - (malloc'ed string)
 * @len: length of the string
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 * for Holberton project
 */
typedef struct list_s
{
	char *str;
	struct list_s *next;
} env_t;

size_t print_list(env_t *h);
env_t *add_node_end(env_t **head, const char *str);
void free_list(env_t **head);
int delete_nodeint_at_index(env_t **head, unsigned int index);
int arr_to_list(env_t **head);
int find_index_list(char *name, env_t **head);

#endif
