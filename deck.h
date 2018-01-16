#ifndef ASSIGNMENT_DECK_H
#define ASSIGNMENT_DECK_H

#include <stdbool.h>

#define DECK_WIDTH 10
#define DECK_HEIGHT 10
#define ASCII_FIRST_CAPITAL 65
#define ASCII_LAST_CAPITAL 90

char deck[DECK_WIDTH][DECK_HEIGHT];

char generate_rand_num(int minimum, int maximum);
void fill_grid_randomly();
void print_deck();

#endif //ASSIGNMENT_DECK_H
