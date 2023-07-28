#include "shellshocked.h"
extern char **environ;

int check_run(char **argv, char **paths)
{
        pid_t pid = fork();
        int status = 0;
        int index = 2;

        printf("PATH = %s\n", paths[index]);
	while (argv[index] != NULL)
        {
                argv[index][strcspn(argv[index], "\n")] = '\0';
                index++;
        }
        if (pid == -1)
        {
                perror("fork");
                exit(EXIT_FAILURE);
        }
        else if (pid == 0)
        {
                execvp(argv[1], argv);
                perror("execvp");
                exit(EXIT_FAILURE);
        }
        else
        {
                waitpid(pid, &status, 0);
        }
        return (1);
}

