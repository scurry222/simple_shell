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
void exec(char **argv, char *s, int i);

/* print_funcs.c */
int _putchar(char c);
int print_env(char **av);
void print_prompt(void);
void print_error(int i, char *s, char **argv);

/* string_funcs.c */
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
int _strlen(char *s);
char *convert(int num, int base);
char *_strcat(char *dest, char *src);

/* parse_path.c */
int strtok_count(char *value);
char **get_env(char *name);
char **parse_path(char *value);
char *path_finder(char **s);

/* strtow.c */
char **strtow(char *str);
int count_word(char *s);

/* strtok.c */
int wordcount(char *str, char delim);
char **_strtok(char *str, char delim);

/* free.c */
void free_everything(char **args);

/* builtins.c */
int exit_handler(char **tokens);
int _atoi(const char *s);
char *_strstr(char *haystack, char *needle);

#endif
