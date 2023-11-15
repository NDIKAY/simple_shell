#include "shell.h"
/**
	*path_exec - path handling
	*@command: string entered by user
	*/
void path_exec(const char *command)
{
	char *args[4];
	pid_t child_process;
	char *path = "/bin/sh";


	if (access(command, X_OK) == 0)
	{
	path = strdup(command);
	if (path == NULL)
	{
	perror("strdup");
	exit(EXIT_FAILURE);
	}
	}
	else
	{
	char *path_env = getenv("PATH");
	char *token = strtok(path_env, ":");

	while (token != NULL)
	{
	char *total_path = malloc(strlen(token) + strlen(command) + 2);

	if (total_path == NULL)
	{
	perror("malloc");
	exit(EXIT_FAILURE);
	}
	strcpy(total_path, token);
	strcat(total_path, "/");
	strcat(total_path, command);

	if (access(total_path, X_OK) == 0)
	{
	path = total_path;
	break;
	}
	free(total_path);
	token = strtok(NULL, ":");
	}
	args[0] = path;
	args[1] = "-c";
	args[2] = strdup(command);
	args[3] = NULL;

	child_process = fork();

	if (child_process == -1)
	{
	perror("fork");
	exit(EXIT_FAILURE);

	}
	else if (child_process == 0)
	{
	execve(args[0], args, NULL);

	perror("execve");
	b_print("error executing command.\n");
	free(args[2]);

	if (strcmp(path, "/bin/sh") != 0)
	free(path);
	exit(EXIT_FAILURE);
	}
	else
	{
	wait(NULL);
	if (strcmp(path, "/bin/sh") != 0)
	free(path);
	}
	}
}

