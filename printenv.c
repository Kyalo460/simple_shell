#include "main.h"

/**
  *dispEnv - displays the environment
  *@env: the environment
  *
  *Return: returns 0 if successfull
  */
int dispEnv(char **env)
{
	int i = 0, j, len;
	char *newline = "\n";

	while (env[i] != NULL)
	{
		j = len = 0;
		while (env[i][j] != '\0')
		{
			len++;
			j++;
		}
		write(1, env[i], len);
		write(1, newline, 1);
		i++;
	}
	return (0);
}
