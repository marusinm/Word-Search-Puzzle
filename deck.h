#ifndef ASSIGNMENT_DECK_H
#define ASSIGNMENT_DECK_H

#define DECK_WIDTH 10
#define DECK_HEIGHT 10
#define ASCII_FIRST_CAPITAL 65
#define ASCII_LAST_CAPITAL 90
#define WORD_LENGTH 8
#define WORD_DB_LENGTH 20
#define HIDDEN_WORDS 4

char deck[DECK_WIDTH][DECK_HEIGHT];
char hidden_words[HIDDEN_WORDS][WORD_LENGTH];

char generate_rand_num(int minimum, int maximum);
void fill_grid_randomly();
void print_deck();


#endif //ASSIGNMENT_DECK_H
