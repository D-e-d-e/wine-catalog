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
    
    fprintf(f, "name,type,wine_variety,prod_year,mark,optional_notes\n");
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

void load_from_csv(WineCollection* collection, const char* filename){
    if(!filename || !collection){
        perror("Invalid filename or WineCollection pointer, please try again.\n");
        return;
    }

    FILE* f = fopen(filename, "r");
    if(!f){
        perror("Error: unable to open file in read mode.\n");
        return;
    }

    char line[MAX_LINE_LEN];

    //skip first line
    fgets(line, sizeof(line), f);

    //now file pointer is on second line
    //loop to read all saved wines
    while(fgets(line, sizeof(line), f) != NULL){
        char* token;
        Wine* new_wine = malloc(sizeof(Wine));
        if(!new_wine){
            perror("Error: failed to allocate memory for new wine");
            break;
        }
        //we find first '\n' occurency and change it with '\0'
        line[strcspn(line, "\n")] = '\0';

        token = strtok(line, ",");
        if(token) strcpy(new_wine->name, token);

        //now instead of line we give NULL in order to continue reading the same line
        token = strtok(NULL, ",");
        if(token) strcpy(new_wine->type, token);

        token = strtok(NULL, ",");
        if(token) strcpy(new_wine->wine_variety, token);

        token = strtok(NULL, ",");
        if(token) new_wine->prod_year = atoi(token);

        token = strtok(NULL, ",");
        if(token) new_wine->mark = atoi(token);

        token = strtok(NULL, ",");
        if(token) strcpy(new_wine->optional_notes, token);

        if(collection->count < MAX_WINES){
            collection->wines[collection->count] = new_wine;
            collection->count++;
        }else{
            perror("Error: number of wines exceeds ammount supported, some wines wont be saved.\n");
        }
    }

    fclose(f);
}
