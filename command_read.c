#include "shell.h"
/**
 * command_parsing - function for reading user command
 * @string: command and args entered by user
 * @str_size: size of string
 */

void command_parsing(char *string, size_t str_size)
{
	if (fgets(string, str_size, stdin) == NULL)
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
	string[strcspn(string, "\n")] = '\0';
}

