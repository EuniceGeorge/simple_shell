#include "shell.h"

/**
  * tokenize_input - Tokenizes the input strings
  * @input: Argument input
  * @args: The array of strings
  *
  * Return: Number of the items tokenized
  */

int tokenize_input(char *input, char *args[])
{
	int count;
	char *token;

	count = 0;
	token = strtok(input, " \n");

	while (token)
	{
		args[count] = token;
		token = strtok(NULL, " \n");
		count++;
	}

	args[count] = NULL;
	return (count);
}

/**
  * handle_builtin_commands - Handle all the built in commands
  * @args: Arguments to the built in commands
  * @num_args: Number of argument
  * @input: The input command
  * @env: The environment variables
  *
  * Return: 1 if successful 0, if unsuccessful
  */

int handle_builtin_commands(char **args, int num_args, char *input, char **env)
{
	if (_strcmp(args[0], "exit") == 0)
	{
		return (shell_exit(args, input));
	}
	else if (_strcmp(args[0], "cd") == 0)
	{
		handle_cd(args, num_args);
		return (1);
	}
	else if (_strcmp(args[0], "env") == 0)
	{
		print_env(env);
		return (1);
	}

	return (0);
}
