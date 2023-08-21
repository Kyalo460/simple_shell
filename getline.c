#include "main.h"

int fetch(char *tokens[])
{
	char *line;
	int read;
	size_t bytes = 0, n = 0, prompts = 0;

	tokens[0] = NULL;

	while (tokens[0] == NULL)
	{
		prompts++;

		printf("testShell~$ ");
		read = getline(&line, &bytes, stdin);
		if (read == -1)
		{
			printf("getline error\n");
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
