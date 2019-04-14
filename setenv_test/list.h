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

size_t list_len(const list_t *h);
int _unsetenv(env_t **head, char *name);
char *_strdup(char *str);
int _setenv(env_t **head, char *name, char *value);
int _strlen(char *s);
char *str_concat(char *s1, char *s2);
size_t print_list(env_t *h);
env_t *add_node_end(env_t **head, const char *str);
void free_list(env_t **head);
int delete_node_at_index(env_t **head, unsigned int index);
int arr_to_list(env_t **head);
int find_index_list(env_t *head, char *name);
int add_node_at_index(env_t **head, char *str, int index);

#endif
