#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define NEW_GAME 1
#define EXIT 2

int generate_menu(){
    bool is_exit = false;
    fprintf(stdout, "1.\tGenerate a new Word Puzzle\n");
    fprintf(stdout, "2.\tExit\n");

    int option;
    scanf(" %d",&option);
    getchar();
    if(option == 1){ //generate new puzzle
        return NEW_GAME;

    }else if(option == 2){ //exit loop, allow program to return 0 and finish
        return  EXIT;
    }
}

int main()
{
    generate_menu();


    fprintf(stdout, "Finished\n");
    return 0;
}
