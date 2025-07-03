#include "wines.h"
#include "utils.h"

static int compare_by_name(const void* a, const void* b){
    Wine* w1 = *(Wine**)a;
    Wine* w2 = *(Wine**)b;
    return strcmp(w1->name, w2->name);
}

static int compare_by_year(const void* a, const void* b){
    Wine* w1 = *(Wine**)a;
    Wine* w2 = *(Wine**)b;
    return w1->prod_year - w2->prod_year;
}

static int compare_by_mark(const void* a, const void* b){
    Wine* w1 = *(Wine**)a;
    Wine* w2 = *(Wine**)b;
    return w1->mark - w2->mark; // from highest to lowest mark
}

/**
 * @brief sorts the wines by users chosen criteria using function pointers
 */
static void sort_wines(Wine** wines, int count, int(*cmp)(const void*, const void*)){
    if(cmp == NULL) return;

    qsort(wines, count, sizeof(Wine*), cmp);
}

void print_wine_struct(Wine* w){
    if(!w) return;

    printf("Name: %s\n", w->name);
    printf("Type: %s\n", w->type);
    printf("Wine variety: %s\n", w->wine_variety);
    printf("Production year: %d\n", w->prod_year);
    printf("Mark: %d\n", w->mark);
    printf("Notes: %s\n", w->optional_notes);
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

void printWineCollection(int sort_criteria, WineCollection* collection){

    switch (sort_criteria)
    {
    case 0:
        //already in insertion order, do nothing
        break;
    case 1:
        sort_wines(collection->wines, collection->count, compare_by_name);
        break;
    case 2:
        sort_wines(collection->wines, collection->count, compare_by_mark);
        break;
    case 3:
        sort_wines(collection->wines, collection->count, compare_by_year);
        break;
    default:
        printf("Invalid sort method, please try again.\n");
        return; //exit early
    }

    printf("\n--- Wine Collection ---\n");
    for(int i = 0; i < collection->count; i++){
        print_wine_struct(collection->wines[i]);
    }
}

float average_rating(WineCollection* collection){
    if(!collection || collection->count == 0){
        perror("Invalid pointer or no wines to calculate average: please try again.\n");
        return -1;
    }
    int sum = 0;
    for(int i = 0; i < collection->count; i++){
        sum+=(collection->wines[i])->mark;
    }
    return (float)sum/collection->count;
}

