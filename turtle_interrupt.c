#include "shell.h"

/**
 * handle_turtle_interrupt - handles SIGINT
 * @sig: signal
 *
 * Prints a new prompt and a fact about turtles if the signal is SIGINT.
 */
void handle_turtle_interrupt(int sig)
{
  /**
   * SIGINT is a signal that is sent to a process when the user presses
   * Ctrl+C.
   */
  if (sig == SIGINT)
  {
    /**
     * Prints a new prompt.
     */
    printf("\n# ");
  }
}
