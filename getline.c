#include "main.h"

/**
  *fetch - gets input from user
  *@tokens: this is where each argument is stored separately
  *
  *Return: returns the number of prompts outputed to stdout
  */
int fetch(char *tokens[])
{
	char *line = NULL;
	int read;
	size_t bytes = 0, n = 0, prompts = 0;

	tokens[0] = NULL;

	while (tokens[0] == NULL)
	{
		prompts++;

		write(STDOUT_FILENO, "$ ", 2);
		read = getline(&line, &bytes, stdin);
		if (read == -1)
		{
			perror("getline error\n");
			exit(EXIT_FAILURE);
		}

		tokens[n] = strtok(line, " \n");
		while (tokens[n] != NULL)
		{
			n++;
			tokens[n] = strtok(NULL, " \n");
		}
	}
	return (prompts);
}
