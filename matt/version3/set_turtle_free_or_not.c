#include "shell.h"

/**
 * set_turtle_free_or_not - frees memory related to command array if not turtle fact and prints turtle fact if turtle fact
 * @param cmdS The command array to be freed.
 * @return void
 */
void set_turtle_free_or_not(char **cmdS)
{
    int iter = 0;

    for (iter = 0; cmdS[iter]; iter++)
        cmdS[iter] = NULL;

    if (*cmdS)
        free(*cmdS), *cmdS = NULL;
}
