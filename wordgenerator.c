#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdio.h>
#include "deck.h"
#include "wordgenerator.h"


char words_database[WORD_DB_LENGTH][WORD_LENGTH]  = {
        "WORD",
        "LAZY",
        "JUMP",
        "ZERO",
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
        "CLUB"
};

//print positions of hidden words
void print_positions_grid(){
    for (int i = 0; i < DECK_HEIGHT; ++i) {
        for (int j = 0; j < DECK_WIDTH; ++j) {
            printf("%d",words_positions[i][j]);
        }
        printf("\n");
    }
}

//initialize all values to false - no words are in deck, no attempts are to put word to grid
void init_positions_grid(){
    for (int i = 0; i < DECK_HEIGHT; ++i) {
        for (int j = 0; j < DECK_WIDTH; ++j) {
//            words_positions[i][j] = false;
            words_positions[i][j] = 0;
        }
    }
}


//generate next hidden word direction
int gen_word_direction(){
    int directions[3] = {HORIZONTAL, VERTICAL, DIAGONAL};
    int position = (generate_rand_num(0, 2));
    return directions[position];
}

//generate and save to hidden words
char * generate_hidden_word(){
    char * word;
    int position = generate_rand_num(0, WORD_DB_LENGTH-1);

    //check if word has been already generated
    bool is_generated = false;
    for (int i = 0; i < HIDDEN_WORDS; ++i) {
        if (strcmp(hidden_words[i].word, words_database[position]) == 0){
            is_generated = true;
            break;
        }
    }

    if (is_generated){ // if word already exists try to generate again
        word = generate_hidden_word();
    }else { // if word doesn't exist put it to hidden words
        word = words_database[position];
    }

    return word;
}

//check if word fits to the grip from starting position and direction
bool is_fitting(int word_length, int direction, int x_pos, int y_pos){
    bool fits = false;

    if (direction == HORIZONTAL){
        if (DECK_WIDTH-1 - y_pos >= word_length){
            fits = true;
        }

    }else if (direction == VERTICAL){
        if (DECK_HEIGHT-1 - x_pos >= word_length){
            fits = true;
        }

    }else{
        if (DECK_WIDTH-1 - y_pos >= word_length && DECK_HEIGHT-1 - x_pos+1 >= word_length){
            fits = true;
        }

    }

    return fits;
}

//check if words don't intersect with other
bool can_set(char * word, int direction, int x_pos, int y_pos){
    bool available = false;

    int word_length = (int)strlen(word);
    if (direction == HORIZONTAL){
        for (int i = 0; i < word_length; ++i) {
//            if(words_positions[x_pos][y_pos+i] == false){ //word doesn't exist on this position
            if(words_positions[x_pos][y_pos+i] == 0){ //word doesn't exist on this position
                available = true;
            }else{ //word exists on this position

                if (word[i] == deck[x_pos][y_pos+i]){ //check if words are intersect in the same letter
                    available = true;
                }else{
                    available = false;
                    break;
                }
            }
        }

    }else if (direction == VERTICAL){
        for (int i = 0; i < word_length; ++i) {
//            if(words_positions[x_pos+i][y_pos] == false){ //word doesn't exist on this position
            if(words_positions[x_pos+i][y_pos] == 0){ //word doesn't exist on this position
                available = true;
            }else{ //word exists on this position

                if (word[i] == deck[x_pos+i][y_pos]){ //check if words are intersect in the same letter
                    available = true;
                }else{
                    available = false;
                    break;
                }
            }
        }

    }else{
        for (int i = 0; i < word_length; ++i) {
//            if(words_positions[x_pos+i][y_pos+i] == false){ //word doesn't exist on this position
            if(words_positions[x_pos+i][y_pos+i] == 0){ //word doesn't exist on this position
                available = true;
            }else{ //word exists on this position

                if (word[i] == deck[x_pos+i][y_pos+i]){ //check if words are intersect in the same letter
                    available = true;
                }else{
                    available = false;
                    break;
                }
            }
        }

    }

    return available;
}

//set hidden word to the table
//void set_word_to_deck(char * word, int direction, int x_pos, int y_pos){
void set_word_to_deck(char * word, int direction, int x_pos, int y_pos, int word_index){
    int word_length = (int)strlen(word);
    if (direction == HORIZONTAL){
        for (int i = 0; i < word_length; ++i) {
            deck[x_pos][y_pos+i] = word[i];
//            words_positions[x_pos][y_pos+i] = true;
            words_positions[x_pos][y_pos+i] = word_index;
        }

    }else if (direction == VERTICAL){
        for (int i = 0; i < word_length; ++i) {
            deck[x_pos+i][y_pos] = word[i];
//            words_positions[x_pos+i][y_pos] = true;
            words_positions[x_pos+i][y_pos] = word_index;
        }

    }else{
        for (int i = 0; i < word_length; ++i) {
            deck[x_pos+i][y_pos+i] = word[i];
//            words_positions[x_pos+i][y_pos+i] = true;
            words_positions[x_pos+i][y_pos+i] = word_index;
        }

    }
}

//put hidden words to the grid
void set_words(){
    srand(time(NULL));
    for (int i = 0; i < HIDDEN_WORDS; ++i) {
        strcpy(hidden_words[i].word, generate_hidden_word());
        int direction = gen_word_direction();
        hidden_words[i].direction = direction;
        hidden_words[i].length = (int)strlen(hidden_words[i].word);
        hidden_words[i].word_index = i+1;


        //generate random position
        int x_pos = generate_rand_num(0, DECK_WIDTH-1);
        int y_pos = generate_rand_num(0, DECK_HEIGHT-1);

        //check if position and rest of table is enough for word length
        if (is_fitting((int)strlen(hidden_words[i].word), direction, x_pos, y_pos)){ //word fits to the grid from starting position

            if (can_set(hidden_words[i].word, direction, x_pos, y_pos)){ // word isn't intersecting with other word, or intersect in same letter
                //finally set word
//                set_word_to_deck(hidden_words[i].word, direction, x_pos, y_pos);
                set_word_to_deck(hidden_words[i].word, direction, x_pos, y_pos, i+1);

            }else{//repeat iteration - generate new word, direction and position
                i--;
                continue;
            }

        }else{ //repeat iteration - generate new word, direction and position
            i--;
            continue;
        }

#ifdef _HINT
        char ch_y_pos = (char)(y_pos+ASCII_FIRST_CAPITAL);
        if (hidden_words[i].direction == VERTICAL)
            printf("%d %c %s vertical with length %d, word index %d\n", x_pos, ch_y_pos, hidden_words[i].word, hidden_words[i].length, i+1);
        else if (hidden_words[i].direction == HORIZONTAL)
            printf("%d %c %s horizontal with length %d, word index %d\n", x_pos, ch_y_pos, hidden_words[i].word, hidden_words[i].length, i+1);
        else
            printf("%d %c %s diagonal with length %d, word index %d\n", x_pos, ch_y_pos, hidden_words[i].word, hidden_words[i].length, i+1);
#endif

    }
}


//check if word exist on concrete position, return index of the word
int check_word_by_pos(int x1, int y1, int x2, int y2){
    int word_idx1 = words_positions[x1][y1];
    int word_idx2 = words_positions[x2][y2];

    if (word_idx1 == word_idx2){ //it is the same word on both positions

        //find the word by index
        hidden_word word;
        for (int i = 0; i < HIDDEN_WORDS; ++i) {
            if (hidden_words[i].word_index == word_idx1){
                word = hidden_words[i];
                break;
            }
        }

        char first_word_letter = word.word[0];
        char last_word_letter = word.word[(int)strlen(word.word)-1];

        char first_choosen_letter = deck[x1][y1];
        char last_choosen_letter = deck[x2][y2];


        //check if user selected right first and last letters, then assume that he found the word (could be exceptions)
        if (first_word_letter == first_choosen_letter && last_word_letter == last_choosen_letter){
            return word.word_index;
        }

    }else{
        return 0;
    }
}


