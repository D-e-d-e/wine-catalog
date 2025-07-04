#include "file.h"
#include "wines.h"
#include "utils.h"

int main(){
    
    printf("--- WINE CATALOG ---\n");
    putchar('\n');
    printf("Restoring wine collection...\n");
    //initialize WineCollection
    WineCollection* collection = (WineCollection*)malloc(sizeof(WineCollection));
    collection->count=0;    

    //loading wine collection
    load_from_csv(collection, DATA_FILE_PATH);


    printf("Succesfully loaded your wine collection!\n");

    putchar('\n');
    print_menu();
    //main loop
    int input = __INT_MAX__;
    while(input != 0){

        scanf("%d", &input);
        
        //cleaning '\n' to prevent bugs
        int c;
        while ((c = getchar()) != '\n' && c != EOF);

        switch (input){
            case 0:
                break;
            case 1:
                //slecting printing criterion and printing wine collection
                int sorting_crieria;
                printf("Select sorting criteria: \n");
                printf("0 -> Insertion date.\n");
                printf("1 -> Alphabetical order.\n");
                printf("2 -> Mark order(from highest to lowest).\n");
                printf("3 -> Production year.\n");

                scanf("%d", &sorting_crieria);

                //cleaning '\n'
                while ((c = getchar()) != '\n' && c != EOF);
                
                printWineCollection(sorting_crieria, collection);
                break;
            case 2:
                //add new wine to collection
                Wine* w = new_wine(collection);
                break;
            case 3:
                //average wine mark
                float av = average_rating(collection);
                printf("The average rating of your wine collection is %.1f.\n", av);
                break;
            case 4:
                remove_wine(collection);
                break;
            default:
                //exit early
                printf("Invalid action, please try again!");
                break;
        }

        print_menu();
    }

    printf("Saving catalog...\n");
    save_on_csv(collection, DATA_FILE_PATH);
    putchar('\n');

    printf("Freeing allocated memory...\n");
    free_wine_collection(collection);

    putchar('\n');
    printf("Done! goodbye!\n");

    return 0;
}