#include "shell.h"
/**
 * turtle_surgery - parses/tokenizes input into string vector
 * @input: object string
 * @cmdS: destination string vector
 * @delim: delimiter to be fed to splitting/tokenizing function
 *
 * Return: 0 if input parsed to cmdS, -1 otherwise
 */

void turtle_surgery(char *turtle_path)
{
    char *buf;

    if (!turtle_path)
        return;
    buf = turtle_path;
    /* Perform surgery on the turtle */
    free(buf);
}

