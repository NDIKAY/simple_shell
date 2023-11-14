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
		length = sizeof(commandLine);

		show_prompt();
		command_parsing(commandLine, length);
		command_exec(commandLine);
		/*command_exec2(commandLine);*/

		length = strlen(commandLine);

		if (length > 0 && commandLine[length - 1] == '\n')
		{
			commandLine[length - 1] = '\0';
		}
	}
	return (0);
}

