#include "shell.h"
/**
	*path_exec - path handling
	*@command: string entered by user
	*/
void path_exec(const char *command)
{
	char *args[2];
	pid_t child_process = fork();

	if (child_process == -1)
	{
	perror("fork");
	exit(EXIT_FAILURE);

	}
	else if (child_process == 0)
	{
	char *command_copy = strdup(command);

	if (command_copy == NULL)
	{
	perror("strdup");
	exit(EXIT_FAILURE);
	}


	args[0] = command_copy;
	args[1] = NULL;


	execvp(args[0], args);

	perror("execvp");
	b_print("error executing command.\n");
	free(command_copy);
	exit(EXIT_FAILURE);
	}
	else
	{
	wait(NULL);
	}
}

