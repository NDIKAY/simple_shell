#include "shell.h"
/**
 *command_exec - execution of child process
 *@command: string entered by user
 */
void command_exec(const char *command)
{
	char *args[4];
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


		args[0] = "/bin/sh";
		args[1] = "-c";
		args[2] = command_copy;
		args[3] = NULL;

		execve(args[0], args, NULL);

		perror("execve");
		b_print("error executing command.\n");
		free(command_copy);
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}
/**
 * exit_system_call - Handle the exit built-in
 */
void exit_system_call(void)
{
	exit(0);
}


