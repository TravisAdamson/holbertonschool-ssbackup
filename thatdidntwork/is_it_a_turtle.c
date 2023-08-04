#include "shell.h"

/**
 * check_command_exists - checks if the command exists in the system
 * @command: The command to be checked.
 * Return: 1 if the command exists, 0 otherwise.
 */
int check_command_exists(char *command)
{
        return (access(command, X_OK) != -1);
}
