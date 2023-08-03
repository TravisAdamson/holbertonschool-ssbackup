#include "shell.h"

/**
 * change_working_directory - changes current working directory
 * @path: desired destination working directory
 * Returns 0 upon success, -1 otherwise
 */
int change_working_directory(char *path)
{
  /**
   * chdir() changes the current working directory to the specified path.
   * Returns 0 upon success, -1 otherwise.
   */
	return (chdir(path));
}
