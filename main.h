#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdbool.h>

char *command(char *token, char *env[]);
char *getpath(char **env);
size_t fetch(char *tokens[], char **line);
char *path(char *fullpath, char *command);
char *_strdup(char *str);
int _strncmp(char *str1, char *str2, int num);
char *str_concat(char *s1, char *s2);
int dispEnv(char **env);
char *array(size_t n);
int _strlen(char *s);

#endif
