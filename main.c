#include <stdio.h>
#include <string.h>
#include "deck.h"
#include "wordgenerator.h"

#define NEW_GAME 1
#define EXIT 2

/**
 * Generate menu
 * @return user selection
 */
int generate_menu(){
    fprintf(stdout, "1.\tGenerate a new Word Puzzle\n");
    fprintf(stdout, "2.\tExit\n");

    int option;
    scanf(" %d",&option);
    getchar();
    if(option == 1){ //generate new puzzle
        return NEW_GAME;

    }else if(option == 2){ //return exitcode for end of game
        return  EXIT;

    }else{ // recursive calling in case of bad selection
        fprintf(stdout, "Select 1 or 2, please.\n");
        return generate_menu();

    }
}

/**
 * Proceed all necessary steps for new game initialization
 */
void init_game(){
    fill_grid_randomly();   //fill grid with randomly letters
    init_positions_grid();  //initialize bool grid which indicate filled words positions
    set_words();            //generate new hidden words and put it to the deck
}

int main(int argc, char** argv)
{
    int menu_result = generate_menu();
    while (menu_result == NEW_GAME) {
        init_game();                //generate new game
        print_deck();               //print game
        int code = guess_loop();    //evaluate user output

        if (code == GAME_GUESSED) {
            fprintf(stdout, "You found all words! Would you like to play another game?\n");
        } else {
            fprintf(stdout, "You didn't find all words! Would you like to play another game?\n");
        }
        menu_result = generate_menu(); // generate menu again and looping while user select option 2 for EXIT
    }

    fprintf(stdout, "Finished\n");
    return 0;
}
