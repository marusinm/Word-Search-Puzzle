#ifndef ASSIGNMENT_DECK_H
#define ASSIGNMENT_DECK_H

#include <stdbool.h>

#define DECK_WIDTH 10
#define DECK_HEIGHT 10
#define ASCII_FIRST_CAPITAL 65
#define ASCII_LAST_CAPITAL 90
#define ASCII_ZERO 48
#define ASCII_NINE 57

#define GAME_GUESSED 0
#define GAME_EXITED 1

char deck[DECK_HEIGHT][DECK_WIDTH]; // grid for user

/**
 * Generate random number in minimum - maximum range and covert it to char
 * @param minimum integer
 * @param maximum integer
 * @return generated number
 */
char generate_rand_num(int minimum, int maximum);

/**
 * Fills grid with random chars
 */
void fill_grid_randomly();

/**
 * Print deck = grid + labelling + hidden words
 */
void print_deck();

/**
 * Listening for user input and evaluating game
 * @return macro if game was guessed or exited
 */
int guess_loop();

#endif //ASSIGNMENT_DECK_H
