#include "shellshocked.h"

void run_pwd() {
    char cwd[PATH_MAX];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("%s\n", cwd);
    } else {
        perror("pwd");
    }
}
void run_echo(const char *args[]) {
    int i;
    for (i = 1; args[i] != NULL; i++) {
        printf("%s ", args[i]);
    }
    printf("\n");
}
void run_cd(const char *args[]) {
    if (args[1]) {
        if (chdir(args[1]) == -1) {
            perror("cd");
        }
    } else {
        fprintf(stderr, "cd: missing argument\n");
    }
}



