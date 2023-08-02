#include "shellshocked.h"

int main(void)
{
    /* Declarations */
    char *command = NULL;
    size_t command_len = 0;
    ssize_t read_len;
    extern char **environ; /* Declare environ */

    /* Check if the input is from a terminal (interactive mode) */
    int interactive_mode = isatty(STDIN_FILENO);

    while (1)
    {
        /* Prompt in interactive mode */
        if (interactive_mode)
        {
            printf("$ ");
        }

        /* Read the command using getline */
        read_len = getline(&command, &command_len, stdin);

        /* Check for end-of-file or error in reading */
        if (read_len == -1)
        {
            if (feof(stdin))
            {
                printf("\n");
                break;
            }
            else
            {
                perror("getline");
                continue;
            }
        }

        /* Remove the newline character from the command */
        command[read_len - 1] = '\0';

        /* Check if the command is "exit" to quit the shell */
        if (strcmp(command, "exit") == 0)
        {
            break;
        }
        else if (strcmp(command, "env") == 0)
        {
            enumerate_environment(environ);
        }
        else if (strncmp(command, "echo ", 5) == 0)
        {
            /* Extract the variable name from the command (e.g., "echo VAR_NAME") */
            char *variable_name = command + 5;
            print_environment_variable(variable_name, environ);
        }
        else
        {
            /* Tokenize the input into separate arguments */
            char *args[MAX_COMMAND_LENGTH];
            int i = 0;
            char *token = strtok(command, " ");
            while (token != NULL)
            {
                args[i++] = token;
                token = strtok(NULL, " ");
            }
            args[i] = NULL;

            /* Execute the command (supporting piped input) */
            if (execute_command(args[0], environ) != 0)
            {
                fprintf(stderr, "Command '%s' not found.\n", args[0]);
            }
        }
    }

    /* Free dynamically allocated memory */
    free(command);

    return 0;
}

