#include "shell.h"

char *turtle_or_not(char *file, char *path)
{
    char *path_copy, *turtle_test, *turtle_path, *temp;
    size_t path_size;

    if (!file || !path)
        return NULL;
    path_size = strlen(path) + 1;
    path_copy = malloc(path_size);
    if (!path_copy)
        return NULL;

    strcpy(path_copy, path);

    turtle_test = malloc(sizeof(char) * (strlen(file) + 2));
    if (!turtle_test)
    {
        free(path_copy);
        return NULL;
    }
    temp = strtok_r(path_copy, ":", &path_copy);
    if (!temp)
    {
        free(turtle_test);
        free(path_copy);
        return NULL;
    }
    turtle_path = malloc(sizeof(char) * (strlen(temp) + 2));
    if (!turtle_path)
    {
        free(turtle_test);
        free(path_copy);
        return NULL;
    }
    while (temp)
    {
        strcpy(turtle_path, temp);
        strcat(turtle_path, "/");
        strcpy(turtle_test, turtle_path);
        if (strcmp(file, turtle_test) == 0)
        {
            free(turtle_test);
            free(path_copy);
            return turtle_path;
        }
        temp = strtok_r(NULL, ":", &path_copy);
    }
    free(turtle_test);
    free(path_copy);
    free(turtle_path);
    return NULL;
}

