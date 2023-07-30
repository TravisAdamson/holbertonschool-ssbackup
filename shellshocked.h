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
int main(int argc, char **argv);
int print_env(char **environ);
char *get_env(char *name, char **environ);
int get_token(char *user_input, char **argv);
int check_run(char **argv, char **paths);
int split_path(char *temp_path, char **tokens);
int get_path_size(char *temp_path);
#endif
