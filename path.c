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
	char *pathslice = NULL, *delim = ":", *patharr, *placeholder;
	char *pathcopy = NULL;
	struct stat st;

	if (stat(command, &st) == 0)
		return (command);

	pathcopy = _strdup(fullpath);

	pathslice = strtok(pathcopy, delim);

	while (pathslice != NULL)
	{
		patharr = str_concat(pathslice, "/");
		placeholder = patharr;
		patharr = str_concat(patharr, command);
		free(placeholder);

		if (stat(patharr, &st) == 0)
		{
			free(pathcopy);
			return (patharr);
		}
		free(patharr);

		pathslice = strtok(NULL, delim);

	}
	free(pathcopy);

	return (command);
}
