#include "shell.h"

/**
 * turtle_cross_road_or_not - launches input command with its arguments
 * @input: The command to be executed.
 * @argv: The arguments to the command.
 * Return: void
 */
void turtle_cross_road_or_not(char *input, char **argv)
{
    pid_t launch = 0;
    int status = 0;
    char *path;
    char *full_path;

    path = get_path(environ);
    full_path = turtle_or_not(argv[0], path);
    if (full_path == NULL)
    {
        /* Add this line to free memory */ 
        /*free(path);  Add this line to free memory */
        free(full_path); /* Add this line to free memory */
        /*free(input);*/
        exit(2);
    }

    launch = fork();
    if (launch == -1)
    {
        perror(argv[0]);
        /* Add this line to free memory */
        free(path); /* Add this line to free memory */
        free(full_path); /* Add this line to free memory */
        free(input);
        exit(EXIT_FAILURE);
    }
    else if (launch == 0)
    {
        if (execvp(full_path, argv) == -1)
        {
            perror(full_path);
            /* Add this line to free memory */
            free(path); /* Add this line to free memory */
            free(full_path); /* Add this line to free memory */
            free(input);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        wait(&status);
    }

    /* Add this line to free memory */
    free(path); /* Add this line to free memory */
    free(full_path); /* Add this line to free memory */
}

