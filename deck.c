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

    bool is_first_pos = true;
    int row1;
    int column1;
    int row2;
    int column2;

    int guessed_words[HIDDEN_WORDS] = {0,0,0,0}; //array of guessed word ids

    bool is_solved = false; //dedicate if game is solved
    bool incoret_format = false;
    while (is_solved == false){

        //user must guess position of first letter and then position of last letter
        if (is_first_pos) {
            fprintf(stdout, "Type 1st position!\n");
        }else{
            fprintf(stdout, "Type 2nd position!\n");
        }

        char input[7];
        fgets(input, 7, stdin);

        if (strlen(input) == 6){ //grater then "exit" string which is longest available string
            scanf("%*[^\n]");scanf("%*c");//clear stdin upto newline
            incoret_format = true;

        }else if(strlen(input) == 5 && strcmp(input, "exit\n") == 0){
            exit_code = GAME_EXITED;
            break;

        }else if(strlen(input) == 3){ //user added two chars + \n
            char row = input[0];
            char column = input[1];

            //check if chars are in correct range
            if (row - ASCII_ZERO >= 0
                && row - ASCII_ZERO < DECK_HEIGHT
                && column - ASCII_FIRST_CAPITAL >= 0
                && column - ASCII_FIRST_CAPITAL < DECK_WIDTH){

                if (is_first_pos){
                    row1 = row - ASCII_ZERO;
                    column1 = column - ASCII_FIRST_CAPITAL;
                }else{
                    row2 = row - ASCII_ZERO;
                    column2 = column - ASCII_FIRST_CAPITAL;
                }

                if (is_first_pos == false){ // user input both positions we can evaluate

                    int word_index = check_word_by_pos(row1, column1, row2, column2);

                    //find the word by index
                    hidden_word word;
                    for (int i = 0; i < HIDDEN_WORDS; ++i) {
                        if (hidden_words[i].word_index == word_index){
                            word = hidden_words[i];
                            break;
                        }
                    }
                    if (word_index == 0){
                        fprintf(stdout, "You made a mistake!\n");
                    }else{
                        fprintf(stdout, "You found %s!\n",word.word);
                    }

                    guessed_words[word.word_index-1] = word.word_index;
                    for (int i = 0; i < HIDDEN_WORDS; ++i) {
                        if (guessed_words[i] != 0){//user still found all words
                            is_solved = true;
                            exit_code = GAME_GUESSED;
                        }else{
                            is_solved = false;
                            break;
                        }
                    }
                }


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

        //user must guess position of first letter and then position of last letter
        if (is_first_pos) {
            is_first_pos = false;
        }else{
            is_first_pos = true;
        }
    }

    return exit_code;

}

