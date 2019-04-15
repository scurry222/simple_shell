#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <signal.h>
#include <errno.h>
#include <limits.h>

extern char **environ;

/**
 * struct list_s - singly linked list
 * @str: string - (malloc'ed string)
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 */
typedef struct list_s
{
	char *str;
	struct list_s *next;
} env_t;

/* main.c */
int exec(char **input, char *s, int *i, env_t **head);

/* path_finder.c */
char **get_env(char *name);
char *path_finder(char **s);
char *get_env_val(char *name);

/* tokenize.c */
int wordcount(char *str, char delim);
char **_strtok(char *str, char delim);

/* print_funcs.c */
void print_prompt(void);
void print_error(int *i, char *s, char **argv);
void print_error_env(char **argv);
void print_error_exit(int *i, char *s, char **argv);
void print_error_main(char **av);

/* string_funcs_1.c */
int _strcmp(char *s1, char *s2);
char *str_concat(char *s1, char *s2);
char *_strstr(char *haystack, char *needle);
int _strncmp(char *s1, char *s2, unsigned int n);
char *_strdup(const char *str);

/* string_funcs_2.c */
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
void _puts(char *str);

/* helper_funcs.c */
int _putchar(char c);
void free_everything(char **args);
void sigint_handler(int sig);

/* builtins.c */
int is_builtin(char *line, char **argv, char *prog_name, int *i, env_t **head);
long long int exit_handler(char **tokens);
int env_handler(char **av, env_t **head);

/* convert.c */
char *convert(int num, int base);
long long int _atoi(char *s);

/* list_funcs_1.c */
void add_node_end(env_t **head, const char *str);
int add_node_at_index(env_t **head, char *str, int index);
int delete_node_at_index(env_t **head, unsigned int index);
int find_index_list(env_t *head, char *name);

/* list_funcs_2.c */
size_t list_len(const env_t *h);
size_t print_list(env_t *h);
void free_list(env_t **head);
int arr_to_list(env_t **head);
char **list_to_arr(env_t *head);

/* set_env.c */
int _unsetenv(env_t **head, char **argv);
int _setenv(env_t **head, char **argv, int args);
void setenv_handler(char **argv, env_t **head);

#endif
