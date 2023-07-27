#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*extern char **environ;*/

int print_env(**environ)
{
	printf("started  -- int print_env(**environ)");
    char **env = environ;
    while (*env != NULL) {
        printf("%s\n", *env);
        env++;
    }
    printf("ended  -- int print_env(**environ)");
    return 0;
}
