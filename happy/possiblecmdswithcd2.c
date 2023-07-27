#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <dirent.h>
#include <errno.h>


#define MAX_ARGS 10

void change_directory(char *directory) {
    if (directory == NULL) {
        chdir(getenv("HOME"));
    } else if (strcmp(directory, "..") == 0) {
        chdir("..");
    } else if (directory[0] == '/') {
        chdir(directory);
    } else {
        DIR* dir = opendir(directory);
        if (dir) {
            chdir(directory);
            closedir(dir);
        } else if (ENOENT == errno) {
            printf("Directory %s does not exist\n", directory);
        } else {
            perror("opendir");
        }
    }
    setenv("OLDPWD", getenv("PWD"), 1);
    setenv("PWD", getcwd(NULL, 0), 1);
}

void execute_command(char **args) {
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        execvp(args[0], args);
        perror("execvp");
        exit(EXIT_FAILURE);
    } else {
        int status;
        waitpid(pid, &status, 0);
    }
}

int main() {
    char input[100];
    char *args[MAX_ARGS];
    int i;

    while (1) {
        printf("Enter command: ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';
        if (strcmp(input, "exit") == 0) {
            break;
        }
        if (strcmp(input, "cd -") == 0) {
            change_directory(getenv("OLDPWD"));
            continue;
        }
        args[0] = strtok(input, " ");
        for (i = 1; i < MAX_ARGS; i++) {
            args[i] = strtok(NULL, " ");
            if (args[i] == NULL) {
                break;
            }
        }
        if (strcmp(args[0], "cd") == 0) {
            change_directory(args[1]);
            continue;
        }
        execute_command(args);
    }
    return 0;
}
