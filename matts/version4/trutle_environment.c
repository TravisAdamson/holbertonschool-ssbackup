#include "shell.h"

/**
 * print_environment_variables - prints environmental variables
 *
 * Prints out all of the environmental variables, followed by a fact about turtles.
 *
 * @environment_variables: an array of environmental variables
 *
 * Returns 0 upon success, -1 otherwise.
 */
int print_environment_variables(char **environment_variables) {
  int iter = 0;

  for (; environment_variables != NULL && *environment_variables != NULL; ++environment_variables) {
    printf("%s\n", *environment_variables);
  }

  /*Print a fact about turtles after the environmental variables.*/
  printf("Did you know that turtles can live for over 100 years?\n");

  return (iter > 0 ? 0 : -1);
}
