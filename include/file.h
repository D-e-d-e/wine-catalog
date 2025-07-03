#ifndef FILE_H
#define FILE_H

#include "wines.h"

/**
 * @brief allows saving of wines collection on .csv file
 * @param collection struct containing array of Wine pointers and number of Wines saved
 * @param filename path to the .csv file
 */
void save_on_csv(WineCollection* collection, const char* filename);

#endif