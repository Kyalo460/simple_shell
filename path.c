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
		exit(EXIT_SUCCESS);

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

	return (command);
}
