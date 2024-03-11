#include "shell.h"

/**
  * get_input - gets the input from the users
  *
  * Return: Character variable to the program
  */

char *get_input(void)
{
	char *input_buf;
	size_t buf_size;
	ssize_t nread;

	input_buf = NULL;
	buf_size = 0;
	nread = getline(&input_buf, &buf_size, stdin);

	if (nread == -1)
	{
		free(input_buf);
		exit(0);
	}

	input_buf = handle_comment(input_buf);

	return (input_buf);
}


/**
  * execute_command - Executes the input from the buffer
  * @input: The argument from the buffer
  * @argv: Array of argument
  * @env: Environment variables
  */

void execute_command(char *input, char *argv[], char **env)
{
	char *args[10];
	char *path, *shell_name;
	int status, num_args;
	pid_t child_pid;

	shell_name = argv[0];
	num_args = tokenize_input(input, args);

	if (num_args == 0)
		return;
	if (handle_builtin_commands(args, num_args, input, env) == 1)
		return;
	path = get_file_path(args[0]);

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("Error: Failed to create");
		free(input);
		exit(1);
	}

	if (child_pid == 0)
	{
		if (execve(path, args, NULL) == -1)
		{
			write(2, shell_name, strlen(shell_name));
			write(2, ": 1: ", 5);
			write(2, args[0], strlen(args[0]));
			write(2, ": not found\n", 12);
			exit(127);
		}
	}
	else
		wait(&status);

	free(path);
}
