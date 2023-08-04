#include "shell.h"
/**
 * turtle_or_not - checks if a file exists or is a turtle fact8
 * @file: The file to be checked.
 *
 * Return: 0 if the file exists or is a turtle fact, -1 otherwise.
 */
void turtle_cross_road_or_not(char *input, char **argv)
{
	    /* Add the unused attribute to the 'input' parameter*/
	    (void)input; /* Suppress unused parameter warning*/

	pid_t pid;
	int status;

    pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        /* Child process */
        if (execvp(argv[0], argv) == -1) {
            perror("execvp");
            exit(EXIT_FAILURE);
        }
    } else {
        /* Parent process */
        do {
            if (waitpid(pid, &status, WUNTRACED) == -1) {
                perror("waitpid");
                exit(EXIT_FAILURE);
            }
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
}
