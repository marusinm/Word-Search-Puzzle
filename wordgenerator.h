
#ifndef ASSIGNMENT_WORDGENERATOR_H
#define ASSIGNMENT_WORDGENERATOR_H

#include "deck.h"

//direction macros
#define HORIZONTAL 1
#define VERTICAL 2
#define DIAGONAL 3

//words macros
#define WORD_LENGTH 8
#define WORD_DB_LENGTH 20
#define HIDDEN_WORDS 4

//grid of booleans, true if word exist on some position
bool words_positions[DECK_WIDTH][DECK_HEIGHT];

//grid of booleans, true if we already tried to put word on position unsuccessfully
bool tried_positions[DECK_WIDTH][DECK_HEIGHT];

//array of hidden words
char hidden_words[HIDDEN_WORDS][WORD_LENGTH];

void init_bool_grids();
int gen_word_direction();
char * generate_hidden_word();
void set_words();

#endif //ASSIGNMENT_WORDGENERATOR_H
