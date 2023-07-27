#include "shellshocked.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
        int num_char, pass_check;
        size_t bsize;
        char *user_input;
        char cwd[1024];

        bsize = 1024;
        argc = 0;
        user_input = malloc(bsize);
        if (user_input == NULL)
        {
                perror("Your memory is shellshocked, unable to continue");
                exit(1);
        }
        while (1)
        {
                if (getcwd(cwd, sizeof(cwd)) != NULL) {
                    printf("%s", cwd);
                } else {
                    perror("getcwd() error");
                    return EXIT_FAILURE;
                }
                printf("%s", prompt);
                num_char = getline(&user_input, &bsize, stdin);
                if (num_char == -1)
                {
                        perror("\n\nYou have been shellshocked and your session has ended!\n");
                        exit(100);
                }
                argc = get_token(user_input, argv);
                printf("argc = %d\n", argc);
		printf("cwd = %s\n", cwd);
                if (argc != 0)
			printf("You didn't enter any commands");
                printf("going to check run with cwd");
		pass_check = 5;
		pass_check = check_run(argv, cwd);
                printf("pass_check = %d\n", pass_check);
                if (pass_check < 0)
                        printf("You entered something that isn't a command");
        }
        free(user_input);
        printf("ended int main(int argc, char *argv[])");
        return (0);
}
