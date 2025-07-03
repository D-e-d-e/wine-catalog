#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief reads  a line of input from stdin safely, removing the trailing newline.
 * @param prompt message displayed before reading.
 * @param buffer buffer where input line will be stored.
 * @param max_len maximum length of input to read(including '\0').
 */
void read_line(const char* prompt, char* buffer, size_t max_len);

/**
 * @brief reads an integer from stdin, retrying until valid integer is intered.
 * @param prompt message displayed to the user before reading.
 * @return integer valure read from input.
 */
int read_int(const char* prompt);

#endif