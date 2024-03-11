#include "shell.h"
/*
 * shell_prompt - prints output to the user
 */

void shell_prompt(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "#cisfun$ ", 9);
}
