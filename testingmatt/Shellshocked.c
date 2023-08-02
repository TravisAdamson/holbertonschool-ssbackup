#include "shellshocked.h"

int main(void) {
    char command[MAX_COMMAND_LENGTH];
    int interactive_mode = isatty(STDIN_FILENO);

    extern char **environ; /* Add this line to declare environ */

    while (1) {
        if (interactive_mode) {
            printf("$ ");
            if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL) {
                if (feof(stdin)) {
                    printf("\n");
                    break;
                } else {
                    perror("fgets");
                    continue;
                }
            }
        } else {
            if (read(STDIN_FILENO, command, MAX_COMMAND_LENGTH) == 0) {
                break;
            }
        }

        command[strcspn(command, "\n")] = '\0';

        if (strcmp(command, "exit") == 0) {
            break;
        } else if (strcmp(command, "env") == 0) {
            enumerate_environment(environ);
        } else if (strncmp(command, "echo ", 5) == 0) {
            /* Extract the variable name from the command (e.g., "echo VAR_NAME") */
            char *variable_name = command + 5;
            print_environment_variable(variable_name, environ);
        } else {
            if (execute_command(command, environ) != 0) {
                fprintf(stderr, "Command '%s' not found.\n", command);
            }
        }
    }

    return 0;
}
