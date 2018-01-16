#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdio.h>
#include "deck.h"
#include "wordgenerator.h"


char words_database[WORD_DB_LENGTH][WORD_LENGTH]  = {
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


//initialize all values to false - no words are in deck, no attempts are to put word to grid
void init_bool_grids(){
    for (int i = 0; i < DECK_WIDTH; ++i) {
        for (int j = 0; j < DECK_HEIGHT; ++j) {
            words_positions[i][j] = false;
            tried_positions[i][j] = false;
        }
    }
}

//generate next hidden word direction
int gen_word_direction(){
    srand(time(NULL));
    int directions[3] = {HORIZONTAL, VERTICAL, DIAGONAL};
    int position = (rand() % 3) + 1;
    return directions[position];
}

//generate and save to hidden words
char * generate_hidden_word(){
    char * word;
    int position = rand() % 19;

    //check if word was already generated
    bool is_generated = false;
    for (int i = 0; i < HIDDEN_WORDS; ++i) {
        if (strcmp(hidden_words[i], words_database[position]) == 0){
            is_generated = true;
            break;
        }
    }

    if (is_generated){ // if word already exists try to generate again
        word = generate_hidden_word();
    }else { // if word don't exists put it to hidden words
        word = words_database[position];
    }

    return word;
}

//put hidden words to the grid
void set_words(){
    srand(time(NULL));
    for (int i = 0; i < HIDDEN_WORDS; ++i) {
        strcpy(hidden_words[i], generate_hidden_word());

        int direction = gen_word_direction(); //TODO use this variable
    }
}


