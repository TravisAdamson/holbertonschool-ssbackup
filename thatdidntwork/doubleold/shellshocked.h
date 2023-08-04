#ifndef SHELL_H
#define SHELL_H

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h>
#include <sys/wait.h>
#define prompt "Shellshocked $"

extern char **environ;
char **tokens;
char **input_tokens;
int main(int argc, char **argv);
int print_env(char **environ);
char *get_env(char *name, char **environ);
int get_token(char *user_input, char **input_tokens);
int check_run(char **argv, char **paths);
int split_path(char *temp_path, char **tokens);
int get_size(char *temp_path, char *delim);
int check_file_exists(char *command, char *dir_name);

#endif
