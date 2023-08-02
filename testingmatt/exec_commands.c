#include "shellshocked.h"

int execute_command(const char *command, char *envp[]) {
    char *command_path;
    char *path_token;
    pid_t pid;
    int status;
    struct stat st;

    pid = fork();
    if (pid == -1) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {
        char *args[MAX_COMMAND_LENGTH];
        int i = 0;
        char *token = strtok((char *)command, " ");
        while (token != NULL) {
            args[i++] = token;
            token = strtok(NULL, " ");
        }
        args[i] = NULL;

        command_path = get_environment_variable("PATH", envp);
        path_token = strtok(command_path, ":");
        while (path_token != NULL) {
            char full_path[PATH_MAX];
            snprintf(full_path, sizeof(full_path), "%s/%s", path_token, args[0]);
            if (stat(full_path, &st) == 0 && S_ISREG(st.st_mode) && access(full_path, X_OK) == 0) {
                execve(full_path, args, envp);
                perror(args[0]);
                exit(EXIT_FAILURE);
            }
            path_token = strtok(NULL, ":");
        }

        fprintf(stderr, "Command '%s' not found.\n", args[0]);
        exit(EXIT_FAILURE);
    } else {
        wait(&status);
        return WEXITSTATUS(status);
    }
}
