#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "deck.h"
#include "wordgenerator.h"

//generate random number in minimum maximum range and covert it to char
char generate_rand_num(int minimum, int maximum){
    return (char) (rand() % (maximum + 1 - minimum) + minimum);
}

//fill grid with random chars
void fill_grid_randomly(){
    srand(time(NULL));
    for (int i = 0; i < DECK_HEIGHT; ++i) {
        for (int j = 0; j < DECK_WIDTH; ++j) {
            deck[i][j] = generate_rand_num(ASCII_FIRST_CAPITAL, ASCII_LAST_CAPITAL);
        }
    }
}

//print deck = grid + labelling + hidden words
void print_deck(){
    //print labeling
    fprintf(stdout, "  ABCDEFGHIJ\n\n");
    for (int i = 0; i < DECK_HEIGHT; ++i) {
        //print labeling
        fprintf(stdout, "%d ",i);

        for (int j = 0; j < DECK_WIDTH; ++j) {
            fprintf(stdout, "%c", deck[i][j]);
        }
        fprintf(stdout, "\n");
    }

    //print hidden words
    fprintf(stdout, "\nHidden words:\n");
    for (int i = 0; i < HIDDEN_WORDS ; ++i) {
        fprintf(stdout, "%s  ", hidden_words[i].word);
    }
    fprintf(stdout, "\n");
}

//listening for user input and checking words or end of program
int guess_loop() {
    int exit_code;

    bool is_guessed = false;
    bool incoret_format = false;
    while (is_guessed == false){
        fprintf(stdout, "Type position!\n");
        char input[7];
        fgets(input, 7, stdin);

        if (strlen(input) == 6){ //grater then "exit" string which is longest available string
            scanf("%*[^\n]");scanf("%*c");//clear stdin upto newline
            incoret_format = true;

        }else if(strlen(input) == 5 && strcmp(input, "exit\n") == 0){
            exit_code = GAME_EXITED;
            break;

        }else if(strlen(input) == 3){
            char row = input[0];
            char column = input[1];

            printf("row %d\n", row-ASCII_ZERO);
            printf("column %d\n", column-ASCII_FIRST_CAPITAL);


            //check if chars are in correct range
            if (row - ASCII_ZERO >= 0
                && row - ASCII_ZERO < DECK_HEIGHT
                && column - ASCII_FIRST_CAPITAL >= 0
                && column - ASCII_FIRST_CAPITAL < DECK_WIDTH){

                //TODO evaluate word

            }else{
                incoret_format = true;
            }
        } else {
            incoret_format = true;
        }


        if (incoret_format) {
            fprintf(stdout, "Incorrect format!\n");
            incoret_format = false;
        }
        fprintf(stdout, "Try again!\n\n");
    }

    return exit_code;

}

