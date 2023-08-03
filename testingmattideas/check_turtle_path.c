#include "shell.h"

/**
 * check_command_in_path - checks if the command exists in each directory of the PATH
 * @command: The command to be checked.
 *
 * Return: 1 if the command exists, 0 otherwise.
 */
#include "shell.h"

/**
 * check_command_in_path - checks if the command exists in each directory of the PATH
 * @command: The command to be checked.
 *
 * Return: 1 if the command exists, 0 otherwise.
 */
int check_command_in_path(const char *command)
{
    char *path_env = getenv("PATH");
    char *path_copy = NULL;
    char *dir = NULL;
    int exists = 0;

    if (!path_env) {
        fprintf(stderr, "Error: PATH environment variable not found.\n");
        return 0;
    }

    path_copy = strdup(path_env);
    if (!path_copy) {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        return 0;
    }

    dir = strtok(path_copy, PATH_DELIM);
    while (dir) {
        char *full_path = malloc(strlen(dir) + strlen(command) + 2);
        if (!full_path) {
            fprintf(stderr, "Error: Memory allocation failed.\n");
            free(path_copy);
            return 0;
        }

        sprintf(full_path, "%s/%s", dir, command);
        exists = turtle_or_not(full_path);
        free(full_path);

        if (exists == 0) {
            free(path_copy);
            return 1; /* Command found in this directory */
        }

        dir = strtok(NULL, PATH_DELIM);
    }

    free(path_copy);
    return 0; /* Command not found in any directory */
}
