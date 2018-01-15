#include <stdlib.h>
#include <stdio.h>
#include "deck.h"

//generate random number in minimum maximum range and covert it to char
char generate_rand_num(int minimum, int maximum){
    return (char) (rand() % (maximum + 1 - minimum) + minimum);
}

//fill grid with random chars
void fill_grid_randomly(){
    for (int i = 0; i < DECK_WIDTH; ++i) {
        for (int j = 0; j < DECK_HEIGHT; ++j) {
            deck[i][j] = generate_rand_num(ASCII_FIRST_CAPITAL, ASCII_LAST_CAPITAL);

        }
    }
}

//print deck = grid + labelling + hidden words
void print_deck(){
    //print labeling
    fprintf(stdout, "  ABCDEFGHIJ\n\n");
    for (int i = 0; i < DECK_WIDTH; ++i) {
        //print labeling
        fprintf(stdout, "%d ",i);

        for (int j = 0; j < DECK_HEIGHT; ++j) {
            fprintf(stdout, "%c", deck[i][j]);
        }
        fprintf(stdout, "\n");
    }

    //TODO: print also hidden words
}

