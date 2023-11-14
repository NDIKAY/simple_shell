#ifndef SHELL_H
#define SHELL_H
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/wait.h>

void b_print(const char *str);
void show_prompt (void);
void command_exec(const char *command);
void command_parsing(char *string, size_t str_size);
void command_exec2(const char *command);
void exit_system_call (void);

#endif
