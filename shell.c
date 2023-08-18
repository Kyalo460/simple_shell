#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "main.h"
#include <stdbool.h>
int main(__attribute__ ((unused)) int ac, char *av[], char *env[])
{
	char *tokens[5];
	int status = 0, acc;
	pid_t pid;
	bool check_pipe = false;

	while((status == 0 && !check_pipe))
	{
		if (isatty(STDIN_FILENO) == 0)
			check_pipe = true;
		fetch(tokens);

		tokens[0] = command(tokens[0], env);
		
		if (tokens[0] == NULL)
			exit(2);
		acc = access((const char*)tokens[0], F_OK);

		if (acc != 0)
		{
			perror(av[0]);
			continue;
		}

		pid = fork();
		if (pid == 0)
		{
			if(execve(tokens[0], tokens, env) == 1)
				exit(EXIT_FAILURE);
		}
		if (pid != 0)
		{
			waitpid(pid, &status, 0);
		}
	}
	return (0);
}
