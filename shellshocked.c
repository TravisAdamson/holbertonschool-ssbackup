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

    char *token; // Declare token outside the while loop

    while (1)
    {
        /* Prompt in interactive mode */
        if (interactive_mode)
        {
            printf("$ ");
        }

        /* Read the command using getline */
        read_len = getline(&command, &command_len, stdin);

        /* Check for end-of-file */
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

        /* Tokenize the input into separate commands */
        token = strtok(command, "\n");
        while (token != NULL)
        {
            /* Execute the command */
            if (execute_command(token, environ) != 0)
            {
                fprintf(stderr, "Command '%s' not found.\n", token);
            }

            /* Get the next token */
            token = strtok(NULL, "\n");
        }
    }

    /* Free dynamically allocated memory */
    free(command);

    return 0;
}

