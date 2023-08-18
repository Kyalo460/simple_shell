#include "main.h"

char *command(char *token, char *env[])
{
	char *fullpath;
	char *command;

	fullpath = getpath(env);

	command = path(fullpath, token);

	return(command);
}
