#include "shell.h"
/**
 *command_exec2 - execution of the child process
 *@command: string entered by user
 */
void command_exec2(const char *command)
{
	pid_t child_process = fork();

	if (child_process == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (child_process == 0)
	{
		char *array[120];
		int i = 0;
		
		char *tok;
		char *copy = strdup(command);

		tok = strtok(copy, " ");

		while (tok != NULL)
		{
		array[i++] = tok;
		tok = strtok(NULL, " ");
		}
		array[i] = NULL;
		
		execvp(array[0], array);
		perror("execvp");
		b_print("Error executing command.\n");
		free(copy);
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}

/**
 * exit_system_call - handle the exit built-in command
 */
void exit_system_call (void)
{
	exit(0);
}
