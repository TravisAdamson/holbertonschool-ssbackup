#include "shellshocked.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    int num_char, path_size, index, exists;
    size_t bsize;
    char *user_input;
    char *name, *temp_com, *temp_dir;
    char *path, *temp_path;
    char **tokens; /* Added the declaration of tokens */

    bsize = 1024;
    exists = 0;
    name = "PATH";
    path = NULL;
    index = 0;
    tokens = NULL; /* Initialize tokens to NULL */
    user_input = (char *)malloc(bsize);
    path_size = 0;
    num_char = 0;
    temp_com = NULL;
    temp_dir = NULL;
    temp_path = NULL;



    if (user_input == NULL)
    {
        perror("Your memory is shellshocked, unable to continue");
        exit(1);
    }
    path = get_env(name, environ);
    temp_path = (char *)malloc(strlen(path) + 1);
    strcpy(temp_path, path);
    path_size = get_path_size(temp_path);
    free(temp_path);
    tokens = (char **)malloc(sizeof(char *) * (path_size + 1)); /* Allocate space for NULL terminator */
    temp_path = (char *)malloc(strlen(path) + 1);
    strcpy(temp_path, path);
    split_path(temp_path, tokens);
    free(temp_path);
    while (1)
    {
        index = 0;
        exists = 0;
        num_char = 0;
        argc = 1;
        printf("%s", prompt);
        num_char = getline(&user_input, &bsize, stdin);
        if (num_char == -1)
        {
            perror("\n\nYou have been shellshocked and your session has ended!\n");
            break;
        }
        argc = get_token(user_input, argv);
        if (argc == 0)
            printf("You didn't enter any commands\n");
        else
        {
            while (tokens[index] != NULL)
            {
                temp_com = (char *)malloc(strlen(argv[1]) + 1);
                strcpy(temp_com, argv[1]);
                temp_dir = (char *)malloc(strlen(tokens[index]) + 1);
                strcpy(temp_dir, tokens[index]);
                exists = check_file_exists(argv[1], tokens[index]);
                if (exists != 0)
                {
                    printf("The command exists in tokens[%d]\n", index);
                    break;
                }
                else
                {
                    index++;
                }
                /* Free temp_com and temp_dir after each iteration of the while loop */
                free(temp_com);
                free(temp_dir);
            }
        }
    }

    /* Free dynamically allocated memory */
    free(tokens);
    free(user_input);
    return (0);
}
