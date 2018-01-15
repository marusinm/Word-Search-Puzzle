#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "deck.h"

char words_database[WORD_DB_LENGTH][WORD_LENGTH] = {
        "WORD",
        "APPLE",
        "BANANA",
        "RADIO",
        "SHIP",
        "TRUCK",
        "CAR",
        "SEA",
        "WATER",
        "HELLO",
        "BAG",
        "CHAIR",
        "TABLE",
        "DOOR",
        "DOG",
        "CAT",
        "BIRD",
        "WOMAN",
        "MAN",
        "YELLOW"
};

//generate random number in minimum maximum range and covert it to char
char generate_rand_num(int minimum, int maximum){
    return (char) (rand() % (maximum + 1 - minimum) + minimum);
}

//generate and save to hidden words
void generate_rand_words(){
    for (int i = 0; i < HIDDEN_WORDS; ++i) {
        strcpy(hidden_words[i], words_database[rand()%20]);
    }
}

//fill grid with random chars
void fill_grid_randomly(){
    srand(time(NULL));
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

    //randomly generate hidden words
    srand(time(NULL));
    generate_rand_words();

    //print hidden words
    fprintf(stdout, "\nHidden words:\n");
    for (int i = 0; i < HIDDEN_WORDS ; ++i) {
        fprintf(stdout, "%s  ", hidden_words[i]);
    }



    //TODO: print also hidden words
}

