#include "main.h"

/**
  *path - attaches the command to the right directory if available
  *@fullpath: the full path
  *@command: the command given by user
  *
  *Return: returns the full directory or command
  */
char *path(char *fullpath, char *command)
{
	char *pathslice, *delim = ":", *patharr;
	char *pathcopy = _strdup(fullpath);
	struct stat st;

	if (stat(command, &st) == 0)
		return (command);

	if ((_strncmp(command, "exit", 4) == 0))
		exit(EXIT_SUCCESS);

	pathslice = strtok(pathcopy, delim);

	while (pathslice != NULL)
	{
		patharr = str_concat(pathslice, "/");
		patharr = str_concat(patharr, command);

		if (stat(patharr, &st) == 0)
			return (patharr);

		pathslice = strtok(NULL, delim);

	}

	return (command);
}
