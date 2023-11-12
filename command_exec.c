#include "shell.h"
/**
 *command_exec - execution of child process
 *@command: string entered by user
 */
void command_exec(const char *command)
{
	pid_t child_process = fork();

	if (child_process == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);

	}
	else if (child_process == 0)
	{
		char *args[2];
		args[0] = strdup(command);
		args[1] = NULL;
		execve(command, args, (char *const *)NULL);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}

