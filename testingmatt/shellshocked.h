#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <limits.h>

#define MAX_COMMAND_LENGTH 1024
#define prompt "Shellshocked $"
extern char **environ;
char* get_environment_variable(const char *variable_name, char *envp[]);
int execute_command(const char *command, char *envp[]);
void run_cd(const char *args[]);
void run_pwd();
void run_echo(const char *args[]);
void enumerate_environment(char *envp[]);
void print_environment_variable(const char *variable_name, char *envp[]);
int main(void);

#endif


