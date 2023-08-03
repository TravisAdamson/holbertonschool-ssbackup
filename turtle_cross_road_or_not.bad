#include "shell.h"

/**
 * turtle_cross_road_or_not - launches input command with its arguments
 * @input: The command to be executed.
 * @argv: The arguments to the command.
 * Return: void
 */
void turtle_cross_road_or_not(char *input, char **argv)
{
    char *path = get_env("PATH", environ);
    if (path == NULL)
    {
        printf("PATH environment variable not found!\n");
        return;
    }
    char *cmd = NULL;
    char *delim = PATH_DELIM;
    char *temp_path = strdup(path); // Make a copy of the path to avoid modifying the original
    char *token = shell_cracked(&temp_path, delim);
    while (token != NULL)
    {
        cmd = (char *)malloc(strlen(token) + strlen(argv[0]) + 2);
        if (cmd == NULL)
        {
            printf("Memory allocation failed.\n");
            free(temp_path);
            return;
        }
        sprintf(cmd, "%s/%s", token, argv[0]);
        if (turtle_or_not(cmd) == 0)
        {
            pid_t launch = fork();
            if (launch == -1)
            {
                perror(argv[0]);
                free(cmd);
                free(temp_path);
                exit(EXIT_FAILURE);
            }
            else if (launch == 0)
            {
                if (execv(cmd, argv) == -1)
                {
                    perror(argv[0]);
                    free(cmd);
                    free(temp_path);
                    free(input);
                    exit(EXIT_FAILURE);
                }
            }
            else
            {
                wait(NULL);
                free(cmd);
                free(temp_path);
                return;
            }
        }
        free(cmd);
        token = shell_cracked(&temp_path, delim);
    }
    free(temp_path);
    printf("%s: command not found\n", argv[0]);
}
