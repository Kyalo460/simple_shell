#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int fetch(char *token[]);
char *command(char *token, char *env[]);
char *getpath(char **env);
char *path(char *fullpath, char *command);

#endif
