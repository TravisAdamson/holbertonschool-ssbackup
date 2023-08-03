#include "shellshocked.h"

void enumerate_environment(char *envp[])
{
    int i = 0;
    while (envp[i] != NULL)
    {
        printf("%s\n", envp[i]);
        i++;
    }
}

