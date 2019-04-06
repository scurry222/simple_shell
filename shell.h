#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <signal.h>

extern char **environ;

int _putchar(char c);
char **strtow(char *str);
int count_word(char *s);
void print_env(void);
void print_prompt(void);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
int strtok_count(char *value);
char *get_env(char *name);
int _strlen(char *s);
char **parse_path(char *value);
char *str_concat(char *s1, char *s2);
char *path_finder(char *s);

#endif
