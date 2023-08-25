#include "main.h"

void dispError(size_t prompts, char *av, char *tokens);

/**
  *main - the entry point for the program
  *@ac: argument count
  *@av: argument vector
  *@env: environment
  *
  *Return: 0 if successfull
  */
int main(__attribute__ ((unused)) int ac, char *av[], char *env[])
{
	char *tokens[5], *line = NULL;
	size_t prompts = 0;
	int status = 0, acc;
	pid_t pid;

	while (1)
	{
		prompts += fetch(tokens, &line);
		tokens[0] = command(tokens[0], env);
		if (_strncmp(tokens[0], "env", 3) == 0)
		{
			free(tokens[0]);
			continue;
		}

		acc = access((const char *)tokens[0], F_OK);
		if (acc != 0)
		{
			dispError(prompts, av[0], tokens[0]);
			free(tokens[0]);
			exit(127);
		}

		pid = fork();
		if (pid == 0)
		{
			if (execve(tokens[0], tokens, env) == 1)
				exit(2);
		}
		if (pid != 0)
		{
			waitpid(pid, &status, 0);
			free(line);
			line = NULL;
			if (tokens[0] != NULL)
				free(tokens[0]);
			if (status == 512)
				exit(2);
		}
	}
	return (status);
}

/**
  *dispError - displays error message to stdout
  *@prompts: amount of total prompts made in the shell
  *@av: argument vector
  *@tokens: command that was not found
  */
void dispError(size_t prompts, char *av, char *tokens)
{
	char *intoa, *separator = ": ", *error = "not found\n";

	/*printf("%lu\n", prompts);*/
	intoa = array(prompts);

	write(STDERR_FILENO, av, _strlen(av));
	write(STDERR_FILENO, separator, _strlen(separator));
	write(STDERR_FILENO, intoa, _strlen(intoa));
	write(STDERR_FILENO, separator, _strlen(separator));
	write(STDERR_FILENO, tokens, _strlen(tokens));
	write(STDERR_FILENO, separator, _strlen(separator));
	write(STDERR_FILENO, error, _strlen(error));

	free(intoa);
}
