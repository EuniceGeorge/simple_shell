#include "shell.h"

/**
  * main - this is the entry point
  * @argc: Argumnt count
  * @argv: Array of arguments
  * @env: Environment variable
  *
  * Return: 0 Always succes
  */

int main(int argc, char *argv[], char **env)
{
	char *input_buf;
	(void)argc;

	while (1)
	{
		shell_prompt();
		input_buf = get_input();
		execute_command(input_buf, argv, env);
		free(input_buf);
	}

	return (0);
}
