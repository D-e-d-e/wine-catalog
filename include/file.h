#ifndef FILE_H
#define FILE_H

#include "wines.h"

#define MAX_LINE_LEN 370
#define DATA_FILE_PATH "data/wines.csv"

/**
 * @brief allows saving of wines collection on .csv file
 * @param collection struct containing array of Wine pointers and number of Wines saved
 * @param filename path to the .csv file
 */
void save_on_csv(WineCollection* collection, const char* filename);

/**
 * @brief allows loading of wines collection from .csv file
 * @param collection struct containing array of Wine pointers and number of Wines saved
 * @param filename path to the .csv file
 */
void load_from_csv(WineCollection* collection, const char* filename);

#endif