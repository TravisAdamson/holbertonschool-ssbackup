#include "shellshocked.h"

char* get_environment_variable(const char *variable_name, char *envp[])
{
    int i;
    char *result = NULL;
    for (i = 0; envp[i] != NULL; i++)
    {
        char *env_var = envp[i];
        char *name_end = strchr(env_var, '=');
        if (name_end != NULL)
        {
            int name_length = name_end - env_var;
            if (strncmp(env_var, variable_name, name_length) == 0)
            {
                result = name_end + 1;
                break;
            }
        }
    }
    return result;
}
