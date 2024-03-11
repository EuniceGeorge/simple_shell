#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>

void shell_prompt(void);
void execute_command(char *input, char *argv[], char **env);
char *get_input(void);
int tokenize_input(char *input, char *args[]);

int handle_builtin_commands(char **args, int num_args, char *input, char **env);
void print_env(char **env);
void handle_cd(char **args, int num_args);
void handle_exit(char *input, int exit_status);
int shell_exit(char **args, char *input);

char *get_file_path(char *file_name);
char *get_file_loc(char *path, char *file_name);

char *handle_comment(char *input);

int _strcmp(char *s1, char *s2);
char *_strdup(const char *s);
int _strlen(const char *s);
void _memcpy(void *newptr, const void *ptr, unsigned int size);

#endif
