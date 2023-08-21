#include "main.h"

char *getpath(char **env)
{
	char *path;

	while (*env != NULL)
	{
		if (_strncmp(*env, "PATH=", 5) == 0)
		{
			path = *env + 5;
			break;
		}
		env++;
	}

	return (path);
}
