#include "shellshocked.h"

char* get_environment_variable(const char *variable_name, char *envp[]) {
    int i;
    char *result = NULL;
    for (i = 0; envp[i] != NULL; i++) {
        char *env_var = envp[i];
        char *name_end = strchr(env_var, '=');
        if (name_end != NULL) {
            int name_length = name_end - env_var;
            if (strncmp(env_var, variable_name, name_length) == 0) {
                result = name_end + 1;
                break;
            }
        }
    }
    return result;
}

#include "shellshocked.h"

int execute_command(const char *command, char *envp[]) {
    struct stat st;
    pid_t pid;
    int status;

    pid = fork();
    if (pid == -1) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {
        char *args[MAX_COMMAND_LENGTH];
        int i = 0;
        char *token;

        token = strtok((char *)command, " ");
        while (token != NULL) {
            args[i++] = token;
            token = strtok(NULL, " ");
        }
        args[i] = NULL;

        if (stat(args[0], &st) == 0 && S_ISREG(st.st_mode) && access(args[0], X_OK) == 0) {
            execve(args[0], args, envp);
            perror(args[0]);
            exit(EXIT_FAILURE);
        }

        fprintf(stderr, "Command '%s' not found.\n", args[0]);
        exit(EXIT_FAILURE);
    } else {
        wait(&status);
        return WEXITSTATUS(status);
    }
}
