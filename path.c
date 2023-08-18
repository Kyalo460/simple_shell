#include "main.h"
#include <sys/stat.h>

char patharr[4096];

char *path(char *fullpath, char *command)
{
	char *pathslice;
	char *pathcopy = strdup(fullpath);
	struct stat st;

	if (stat(command, &st) == 0)
		return (command);

	if ((strcmp(command, "exit") == 0))
		exit(2);

	if ((strcmp(command, "env") == 0))
		return ("/usr/bin/env");

	pathslice = strtok(pathcopy, ":");

	while (pathslice != NULL)
	{
		snprintf(patharr, sizeof(patharr), "%s/%s", pathslice, command);

		if (stat(patharr, &st) == 0)
			return(patharr);
		else
			pathslice = strtok(NULL, ":");

	}
	printf("%s\n", patharr);

	return (patharr);
}
