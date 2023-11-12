#include "shell.h"
/**
 * main - entry point
 * Return: 0 on sucess
 */
int main(void)
{
	char commandLine[99];

	while (true)
	{
		show_prompt();
		command_parsing(commandLine, sizeof(commandLine));
		command_exec(commandLine);
	}
	return (0);
}

