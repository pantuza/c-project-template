#pragma once

#include "words.h";

// Word Functions:
int wordsLen(char** words){
    return 0;
}

prediction_t bestWord(char** words){
    return NULL;
}

prediction_t[] rankWords(char** words){
    return NULL;
}

char** filterWords(words, paintedWord){
    // for word in words:
    //     if !filterGray(word, paintedWord):
    //         free(words[word]);
    //         words[word] = NULL;
    //     if ...
    // return words
    return NULL;
}

// Color Functions:
bool filterGray(words, paintedWord_t paintedWord){
    return false;
}

bool filterYellow(words, paintedWord_t paintedWord){
    return false;
}

bool filterGreen(words, paintedWord_t paintedWord){
    return false;
}

// Test Functions:
bool isCorrect(prediction_t prediction){
    return false;
}

paintedWord_t colorWord(prediction_t prediction){
    return {"Hello", 0.0};
}