#include "shell.h"
/**
 * command_parsing - function for reading user command
 * @string: command and args entered by user
 * @str_size: size of command
 */

void command_parsing(char *string, size_t str_size)
{
	ssize_t read = getline(&string, &str_size, stdin);


	if (read == -1)
	{

		if (feof(stdin))
		{
			b_print("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			b_print("reading input error.\n");
			exit(EXIT_FAILURE);
		}
	}
	if (string[read - 1] == '\n')
	{
		string[read - 1] = '\0';

	}
}

