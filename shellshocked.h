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

int main(int argc, char **argv);
int print_env(char **environ);
int get_token(char *user_input, char **argv);
char **get_token2(char *path);
int check_run(char **argv, char *path);
#endif
