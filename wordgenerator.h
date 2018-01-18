
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

#define _HINT //TODO: comment to disable hint

//grid of booleans, true if word exist on some position
//bool words_positions[DECK_HEIGHT][DECK_WIDTH];

//grid of index of hidden word. if 0 word didn't set here
int words_positions[DECK_HEIGHT][DECK_WIDTH];

typedef struct hidden_word{
    char word[WORD_LENGTH];
    int length;
    int direction;

}hidden_word;

hidden_word hidden_words[HIDDEN_WORDS]; //array of hidden words


void init_positions_grid();
int gen_word_direction();
char * generate_hidden_word();
bool is_fitting(int word_length, int direction, int x_pos, int y_pos);
bool can_set(char * word, int direction, int x_pos, int y_pos);
//void set_word_to_deck(char * word, int direction, int x_pos, int y_pos);
void set_word_to_deck(char * word, int direction, int x_pos, int y_pos, int word_index);
void set_words();

#endif //ASSIGNMENT_WORDGENERATOR_H
