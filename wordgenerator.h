
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

//#define _HINT //TODO: comment to disable hint


//grid of index of hidden word. if 0 word didn't set here
int words_positions[DECK_HEIGHT][DECK_WIDTH];

// hidden word structure
typedef struct hidden_word{
    char word[WORD_LENGTH];
    int length;
    int direction;
    int word_index;

}hidden_word;

hidden_word hidden_words[HIDDEN_WORDS]; //array of hidden words

/**
 * Initialize all values of grid to false - no words are in deck
 */
void init_positions_grid();

/**
 * Generate next hidden word direction
 * @return macro which indicate direction
 */
int gen_word_direction();

/**
 * Generate hidden word
 * @return word
 */
char * generate_hidden_word();

/**
 * Check if word fits to the grip from starting position and in direction
 * @param word_length length of word
 * @param direction direction macro
 * @param x_pos grid height starting position
 * @param y_pos grid width starting position
 * @return true if word fits into grid
 */
bool is_fitting(int word_length, int direction, int x_pos, int y_pos);

/**
 * Check if words don't intersect with other and if yes if intersect in same letter
 * @param word
 * @param direction direction macro
 * @param x_pos grid heights tarting position
 * @param y_pos grid width starting position
 * @return true if is possible to put word into grid
 */
bool can_set(char * word, int direction, int x_pos, int y_pos);

/**
 * Set hidden word to the table
 * @param word word to set
 * @param direction direction macro
 * @param x_pos grid height starting position
 * @param y_pos grid width starting position
 * @param word_index
 */
void set_word_to_deck(char * word, int direction, int x_pos, int y_pos, int word_index);

/**
 * Generate and set words into grid.
 * Calling other functions for checking and setting word ...
 */
void set_words();

/**
 * Check if word exist on input positions
 * @param x1 user input grid starting height
 * @param y1 user input grid starting width
 * @param x2 user input grid ending height
 * @param y2 user input grid ending width
 * @return index of the word
 */
int check_word_by_pos(int x1, int y1, int x2, int y2);

#endif //ASSIGNMENT_WORDGENERATOR_H
