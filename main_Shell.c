#include "shell.h"
/**
 * main - entry point
 * Return: 0 on sucess
 */
int main(void)
{
	char commandLine[99];
	size_t length;

	while (true)
	{
		length = strlen(commandLine);

		show_prompt();
		command_parsing(commandLine, sizeof(commandLine));
		command_exec(commandLine);
		command_exec2(commandLine);

		length = strlen(commandLine);

		if (length > 0 && commandLine[length - 1] =='\n')
		{
			commandLine[length - 1] = '\0';
		}
		if (strcmp(commandLine, "exit") == 0)
		{
			exit_system_call();
		}
		command_exec2(commandLine);
	}
	return (0);
}

