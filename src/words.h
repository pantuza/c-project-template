#define WORDLEN 5

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

enum letterColor = {gray, green, yellow};

typedef struct paintedWord {  
    char word[WORDLEN];
    letterColor colors[WORDLEN];
} paintedWord_t;

typedef struct prediction {
    char* word; 
    double score; 
} prediction_t;

// Word Functions:
int wordsLen(char** words); // Returns num of words left
prediction_t bestWord(char** words); // Returns current highest scoring word
prediction_t[] rankWords(char** words); // Returns an array of prediction scores for every word in the words array
char** filterWords(words, paintedWord); // Uses the color functions to filter out impossible works based on the given infromation

// Color Functions:
bool filterGray(words, paintedWord_t paintedWord); // Returns a version of the words array without any words containing grayLetters
bool filterYellow(words, paintedWord_t paintedWord); // Returns a version of the words array which only contains words which contain yellowLetters not in current spot
bool filterGreen(words, paintedWord_t paintedWord); // Returns a version of the words awwat which only contains words which have green letters in the right spot

// Test Functions:

bool isCorrect(prediction_t prediction); // This function checks if the prediction is correct (just for testing the solver)
paintedWord_t colorWord(prediction_t prediction); // This function takes a normal word and returns a list of letters in that word and a list of their corresponding color values. 