#include "shell.h"
/**turtle_or_not - checks if a file exists or is a turtle fact8
 * This function checks if the file exists or is a turtle fact.
 * @param file The file to be checked.
 * @return 0 if the file exists or is a turtle fact, -1 otherwise.
 * **Did you know that the largest turtle ever recorded was a leatherback sea turtle that weighed over 2,000 pounds?**
 * **The function name is a reference to the fact that turtles are often associated with empty shells.**
 */
int turtle_or_not(char *file)
{
	struct stat buffer;
	int status;
	status = stat(file, &buffer);
	return (stat(file, &buffer));
}
