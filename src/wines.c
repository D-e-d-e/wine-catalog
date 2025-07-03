#include "wines.h"

//Helper to read strings from stdin in a safe way
static void read_line(const char* prompt, char* buffer, size_t max_len){
    printf("%s", prompt);
    if(fgets(buffer, max_len, stdin)){
        buffer[strcspn(buffer, "\n")] = '\0';   //Remove newline
    }else{
        //if fgets fails, make sure we have an empty string
        buffer[0] = '\0';
    }
}

//Helper to read integers with control and cleaning buffer
static int read_int(const char* prompt){
    int val, res;
    char c;

    while(1){
        printf("%s", prompt);
        res = scanf("%d", &val);
        while((c = getchar()) != '\n' && c != EOF); //buffer cleaning

        if(res != 1){
            printf("Invalid input, try again.\n");
            continue;
        }
        return val;
    }
}

Wine* new_wine(WineCollection* collection){
    Wine* w = (Wine*)malloc(sizeof(Wine));
    if(!w){
        perror("malloc failed");
        return NULL;
    }

    read_line("Insert wine name: ", w->name, MAX_NAME_LEN);
    read_line("Insert wine type: ", w->type, MAX_TYPE_LEN);
    read_line("Insert wine variety: ", w->wine_variety, MAX_TYPE_LEN);      
    w->prod_year = read_int("Insert production year (ex. 2020): ");
    
    // Reading mark (1-5) with a loop until valid
    do{

        w->mark = read_int("Insert mark (1-5): ");
        if(w->mark<1 || w->mark>5) printf("%d is an invalid mark, please insert a number between 1 and 5: \n", w->mark);
    
    }while(w->mark<1 || w->mark>5);

    read_line("Insert optional notes: ", w->optional_notes, MAX_NOTES_LEN);
    
    //add wine pointer to wines array
    collection->wines[collection->count] = w;
    collection->count++;
    return w;
}