#ifndef UTILS_H
#define UTILS_H

void clearScreen(void);
void terminosSetup(void);
/**
 * set_input_mode - Configure the terminal for interactive mode
 *
 * This function disables canonical mode and input echo, hides the terminal
 * cursor, and saves the current terminal settings. The previous terminal
 * configuration will be automatically restored when the program exits.
 */
void set_input_mode(void);
/**
 * reset_input_mode - Restore the terminal to its previous state
 *
 * This function restores the terminal settings saved by `set_input_mode()`
 * and makes the terminal cursor visible again. It is intended to be called
 * automatically on program exit (via `atexit`) to ensure the terminal is
 * returned to its original state.
 */
void reset_input_mode(void);
void handle_sigint(int sig);

#endif
