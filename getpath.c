#include "main.h"

/**
  *getpath - extracts the PATH value from environment
  *@env: the environment
  *
  *Return: returns a pointer to the PATH value
  */
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
