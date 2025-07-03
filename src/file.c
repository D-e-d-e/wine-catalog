#include "file.h"

void save_on_csv(WineCollection* collection, const char* filename){
    if(!filename || !collection || collection->count == 0){
        perror("Invalid .csv path or empty wine collection, please try again.\n");
        return;
    }

    FILE* f = fopen(filename, "w");
    if(!f){
        perror("Error: unable to open file in write mode.\n");
        return;
    }
    
    fprintf(f, "name,type,wine_variety,prod_year,mark,optional_notes");
    //loop to save in .csv file
    for(int i = 0; i < collection->count; i++){

        Wine* w = collection->wines[i];

        fprintf(f, "%s,%s,%s,%d,%d,%s\n",
                w->name,
                w->type,
                w->wine_variety,
                w->prod_year,
                w->mark,
                w->optional_notes);
    }

    fclose(f);
}
