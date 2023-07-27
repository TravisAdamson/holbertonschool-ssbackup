#ifndef SHELL_H
#define SHELL_H

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h>
#define prompt "Shellshocked $"

int main();
int get_token(char *user_input, char *token);

#endif
