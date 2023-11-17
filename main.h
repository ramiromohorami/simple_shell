#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
extern char **environ;
char *line_reader(void);
int _strcmp(char *string1, char *string2);
int _strlen(char *s);
char *_strdup(const char *str);
char *_strcat(char *dest, char *src);
char *_strcopy(char *dest, char *src);
char **sep_strings(char *phrase);
void freeptr_ptr(char **a);
int _execute(char **cmd, char **argv);

#endif
