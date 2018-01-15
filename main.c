#include <stdio.h>
#include "deck.h"

#define NEW_GAME 1
#define EXIT 2

int generate_menu(){
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
    int menu_result = generate_menu();
    if (menu_result == NEW_GAME){
        //generate new game
        fill_grid_randomly();
        print_deck();
    }

    fprintf(stdout, "Finished\n");
    return 0;
}
