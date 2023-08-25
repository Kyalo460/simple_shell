#include "main.h"

/**
  *fetch - gets input from user
  *@tokens: this is where each argument is stored separately
  *@line: buffer to store read line
  *
  *Return: returns the number of prompts outputed to stdout
  */
size_t fetch(char *tokens[], char **line)
{
	int read;
	size_t bytes = 0, n = 0, prompts = 0;

	tokens[0] = NULL;

	while (tokens[0] == NULL)
	{
		prompts++;

		if (isatty(STDIN_FILENO) != 0)
			write(STDOUT_FILENO, "$ ", 2);
		read = getline(line, &bytes, stdin);
		if (read == -1)
		{
			free(*line);
			line = NULL;
			exit(EXIT_SUCCESS);
		}

		tokens[n] = strtok(*line, " \n");
		while (tokens[n] != NULL)
		{
			n++;
			tokens[n] = strtok(NULL, " \n");
		}
	}
	if (_strncmp(tokens[0], "exit", 4) == 0)
	{
		free(*line);
		exit(EXIT_SUCCESS);
	}
	return (prompts);
}
