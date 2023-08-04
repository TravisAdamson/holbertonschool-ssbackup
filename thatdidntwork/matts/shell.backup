#ifndef __SHELL_H__
#define __SHELL_H__

#define SPC_DELIM " \t\n\r"
#define PATH_DELIM ":"
#define MAX_LEN 1024

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <errno.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

extern char **environ;

/**
 * struct builtIn - struct to assist in calling built-in functions
 * @command_name: built-in function name
 * @command_function: function called if input = command_name, NULL otherwise
 */

typedef struct builtIn
{
    char *command_name;
    int (*command_function)();
} builtIn;

void __attribute__ ((constructor)) coolIntro(void);
ssize_t readPrompt(const char *, char **, size_t *);
void handleSignal(int);
int checkFileExistence(char *);
char *splitString(char **, char *delim);
void executeCommand(char *, char **);
void freeCommandArray(char **);
int isInputEmpty(char *);
int parseInput(char *input, char *cmdS[], char *delim);

/* Built-in implementations */
int builtIn_env(void);
int builtIn_cd(char *path);

#endif

