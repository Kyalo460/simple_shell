#include "main.h"
#include <sys/stat.h>

char *patharr;

char *path(char *fullpath, char *command)
{
	char *pathslice;
	char *pathcopy = _strdup(fullpath);
	struct stat st;

	if (stat(command, &st) == 0)
		return (command);

	if ((_strncmp(command, "exit", 4) == 0))
		exit(2);

	if ((_strncmp(command, "env", 3) == 0))
		return ("/usr/bin/env");

	pathslice = strtok(pathcopy, ":");

	while (pathslice != NULL)
	{
		/*snprintf(patharr, sizeof(patharr), "%s/%s", pathslice, command);*/
		patharr = str_concat(pathslice, "/");
		patharr = str_concat(patharr, command);

		if (stat(patharr, &st) == 0)
			return(patharr);
		else
			pathslice = strtok(NULL, ":");

	}

	return (patharr);
}
