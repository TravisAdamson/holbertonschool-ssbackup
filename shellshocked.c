#include "shellshocked.h"

/**
 * main - Generates a simple shell
 * @argc: Number of arguements given
 * @argv: The arguements given
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
        int num_char, pass_check;
        size_t bsize;
        char *user_input;
        char *path = getenv("PATH");

        printf("started int main(int argc, char *argv[])");

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
                printf("%s", prompt);
                num_char = getline(&user_input, &bsize, stdin);
                if (num_char  == -1)
                {
                        perror("\n\nYou have been shellshocked and your session has ended!\n");
                        exit(100);
                }
                argc = get_token(user_input, argv);
                if (argc != 0)
                        printf("You didn't enter any commands");
                pass_check = check_run(argv, path);
                if (pass_check < 0)
                        printf("You entered something that isn't a command");
        }
        free(user_input);
        printf("ended int main(int argc, char *argv[])");
        return (0);
}

