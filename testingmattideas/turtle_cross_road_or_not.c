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

    launch = fork();
    if (launch == -1)
    {
        perror(argv[0]);
        exit(EXIT_FAILURE);
    }
    else if (launch == 0)
    {
        /* Check if the command exists in the PATH before executing it*/
        if (check_command_in_path(argv[0]) == 0)
        {
            fprintf(stderr, "%s: not found\n", argv[0]);
            free(input);
            exit(EXIT_FAILURE);
        }

        /* Execute the command*/
        if (execvp(argv[0], argv) == -1)
        {
            perror(argv[0]);
            free(input);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        wait(&status);
    }
}
