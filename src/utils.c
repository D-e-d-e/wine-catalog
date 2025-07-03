#include "utils.h"

void read_line(const char* prompt, char* buffer, size_t max_len){
    printf("%s", prompt);
    if(fgets(buffer, max_len, stdin)){
        buffer[strcspn(buffer, "\n")] = '\0';   //Remove newline
    }else{
        //if fgets fails, make sure we have an empty string
        buffer[0] = '\0';
    }
}

int read_int(const char* prompt){
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