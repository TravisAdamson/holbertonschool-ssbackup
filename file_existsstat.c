#include "shellshocked.h"

#include "shellshocked.h"
#include <sys/stat.h>

int check_file_exists(char *dir_name)
{
    struct stat path_stat;
    if (stat(dir_name, &path_stat) != 0)
        return (0);
    if (S_ISDIR(path_stat.st_mode))
    {
        printf("Directory found\n");
        return (1);
    }
    else if (S_ISREG(path_stat.st_mode))
    {
        printf("File found\n");
        return (1);
    }
    else
    {
        printf("Not a file or directory\n");
        return (0);
    }
}
