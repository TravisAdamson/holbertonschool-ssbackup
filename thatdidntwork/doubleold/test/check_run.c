#include "shellshocked.h"

int check_run(char **argv)
{
    char *envp[] = {NULL};
    char *path = "/bin/";
    char *full_path = malloc(strlen(path) + strlen(argv[1]) + 1);
    int status = 0;
    pid_t pid = 0;
    pid_t child_pid = 0;
   
    strcpy(full_path, path);
    strcat(full_path, argv[1]);
    argv[1] = full_path;

    if (pid == -1)
    {
            perror("fork");
            exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
            child_pid = fork();
            if (child_pid == -1)
            {
                perror("fork");
                exit(EXIT_FAILURE);
            }
            else if (child_pid == 0)
            {
                execve(argv[1], argv, envp);
                perror("execve");
                exit(EXIT_FAILURE);
            }
            else
            {
                waitpid(child_pid, &status, 0);
                exit(EXIT_SUCCESS);
            }
    }
    else
    {
        waitpid(pid, &status, 0);
    }
    return (0);
}








