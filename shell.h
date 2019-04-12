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

/* main.c */
void exec(char **argv, char *s, int *i);

/* print_funcs.c */
int _putchar(char c);
void print_prompt(void);
void print_error(int *i, char *s, char **argv);
void print_error_env(char **argv);
void print_error_exit(int *i, char *s, char **argv);

/* string_funcs.c */
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
char *str_concat(char *s1, char *s2);
char *_strstr(char *haystack, char *needle);

/* path_finder.c */
char **get_env(char *name);
char *path_finder(char **s);

/* tokenize.c */
int wordcount(char *str, char delim);
char **_strtok(char *str, char delim);

/* helper_funcs.c */
void free_everything(char **args);
void sigint_handler(int sig);

/* builtins.c */
int is_builtin(char *line, char *prog_name, char **argv, int *i);
long long int exit_handler(char **tokens);
int env_handler(char **av);

/* convert.c */
char *convert(int num, int base);
long long int _atoi(char *s);

#endif
