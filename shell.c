#include "main.h"

void dispError(int prompts, char *av, char *tokens);

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
	char *tokens[5];
	size_t prompts = 0;
	int status = 0, acc, x;
	pid_t pid;
	bool check_pipe = false;

	while ((status == 0 && !check_pipe))
	{
		if (isatty(STDIN_FILENO) == 0)
			check_pipe = true;

		prompts += fetch(tokens);

		tokens[0] = command(tokens[0], env);

		if (_strncmp(tokens[0], "env", 3) == 0)
			continue;

		acc = access((const char *)tokens[0], F_OK);

		if (acc != 0)
		{
			dispError(prompts, av[0], tokens[0]);
			continue;
		}

		pid = fork();
		if (pid == 0)
		{
			if (execve(tokens[0], tokens, env) == 1)
				exit(EXIT_FAILURE);
		}
		if (pid != 0)
		{
			waitpid(pid, &status, 0);
			for (x = 0; tokens[x] != NULL; x++)
				free(tokens[x]);
		}
	}
	return (0);
}

/**
  *dispError - displays error message to stdout
  *@prompts: amount of total prompts made in the shell
  *@av: argument vector
  *@tokens: command that was not found
  */
void dispError(int prompts, char *av, char *tokens)
{
	char *intoa, *separator = ": ", *error = "not found\n";

	intoa = array(prompts);

	write(STDOUT_FILENO, av, _strlen(av));
	write(STDOUT_FILENO, separator, _strlen(separator));
	write(STDOUT_FILENO, intoa, _strlen(intoa));
	write(STDOUT_FILENO, separator, _strlen(separator));
	write(STDOUT_FILENO, tokens, _strlen(tokens));
	write(STDOUT_FILENO, separator, _strlen(separator));
	write(STDOUT_FILENO, error, _strlen(error));
	free(intoa);
}
