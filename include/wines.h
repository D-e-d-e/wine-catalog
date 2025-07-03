#ifndef WINES_H
#define WINES_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_NAME_LEN 100
#define MAX_TYPE_LEN 50
#define MAX_NOTES_LEN 200
#define MAX_WINES 100

typedef struct wine{
    char name[MAX_NAME_LEN];
    char type[MAX_TYPE_LEN];
    char wine_variety[MAX_TYPE_LEN];
    int prod_year;
    int mark;
    char optional_notes[MAX_NOTES_LEN];
} Wine;

typedef struct wine_collection{
    Wine* wines[MAX_WINES];
    int count;
} WineCollection;

/**
 * @brief Allows user to insert a new wine
 * @param collection an array of wine pointers(pointer of new wine will be added in this array)
 * @return pointer to newly allocated wine, or NULL
 * @note caller is responsible for freeing the pointer
 */
Wine* new_wine(WineCollection* collection);

/**
 * @brief prints wine collection by insertion date, name, mark or year
 * @param sort_criteria criterion to sort the wines: 0 = insertion date, 1 = name, 2 = mark, 3 = production year 
 * @param collection struct containing array of Wine pointers and number of elements in the array
 */
void printWineCollection(int sort_criteria, WineCollection* collection);

/**
 * @brief returns the average rating of your collection of wines
 * @param collection struct containing collection of wines and number of wines collected
 */
float average_rating(WineCollection* collection);


#endif