#include <stdio.h>
#include <string.h>
#include "deck.h"
#include "wordgenerator.h"

#define NEW_GAME 1
#define EXIT 2

//generates menu
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

    //TODO osetrit co spravit ked user stlaci nieco ine

}

//proceed all necessary steps for initialization
void init_game(){
    fill_grid_randomly();   //fill grid with randomly letters
    init_bool_grids();      //initialize bool grid which indicate filled words positions
    set_words();            //generate new hidden words and put it to the deck
}

int main(int argc, char** argv)
{
    int menu_result = generate_menu();
    if (menu_result == NEW_GAME){
        init_game();    //generate new game
        print_deck();   //print game
    }

    fprintf(stdout, "Finished\n");
    return 0;
}
