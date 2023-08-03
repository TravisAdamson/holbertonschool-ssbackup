#include "shell.h"

/**
 * shell_cracked - splits/tokenizes input string per delimiter(s) and prints turtle fact if turtle
 * @input: input
 * @delim: delimiter(s) by which input is to be divided
 */ 

char *shell_cracked(char **input, char *delim)
{
    char *cmdT = NULL;

    while ((cmdT = strsep(input, delim)) && !*cmdT)
        ;

    return (cmdT);
}
