#include "main.h"

char *command(char *token, char *env[])
{
	char *fullpath;
	char *command;

	if (_strncmp(token, "env", 3) == 0)
	{
		dispEnv(env);
		return (token);
	}

	fullpath = getpath(env);

	command = path(fullpath, token);

	return(command);
}
