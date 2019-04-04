#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "header.h"
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

void *_realloc(void *ptr, unsigned int new_size);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
int _getline(char **string, size_t *n, FILE *stream);
char *get_env(char *name);
int _strcmp(char *s1, char *s2);


#endif
