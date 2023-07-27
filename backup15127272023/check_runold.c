#include "shellshocked.h"

int check_run(char **argv)
{
    pid_t pid;
    int status = 0;
    char *envp[] = {NULL};
    char *path = "/bin/";
    char *full_path = malloc(strlen(path) + strlen(argv[0]) + 1);
    if (full_path == NULL)
    {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    strcpy(full_path, path);
    strcat(full_path, argv[0]);
    argv[0] = full_path;

    pid = fork();
    if (pid == -1)
    {
            perror("fork");
            exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
            execve(argv[0], argv, envp);
            perror("execve");
            exit(EXIT_FAILURE);
    }
    else
    {
        waitpid(pid, &status, 0);
    }
    return (0);
}
