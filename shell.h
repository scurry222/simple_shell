#ifndef SHELL
#define SHELL

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <signal.h>

int _putchar(char c);
extern char **environ;
char **strtow(char *str);
int count_word(char *s);
void print_env(void);
void print_prompt(void);
int _strcmp(char *s1, char *s2);

#endif
