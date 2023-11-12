#include "shell.h"
/**
*b_print - function for printing outputs
*@str: str to be printed
 */
void b_print(const char *str)
{
	write(1, str, strlen(str));
}
