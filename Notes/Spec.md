# Wordle Solver:

## Data Structures:

```c
enum letterColor = {gray, green, yellow};

#define WORDLEN 5

struct paintedWord {
    char word[WORDLEN];
    letterColor colors[WORDLEN];
} paintedWord_t

char** filterWords(words, paintedWord){
    for word in words:
        if !filterGray(word, paintedWord):
            free(words[word]);
            words[word] = NULL;
        if ...
    return words
}

struct prediction {
    char* word; 
    double score; 
} prediction_t

char** words = { *Vocabulary* };
```

## Vocabulary:
```c

int wordsLen(char** words); // Returns num of words left

prediction_t bestWord(char** words); // Returns current highest scoring word

prediction_t[] rankWords(char** words); // Returns an array of prediction scores for every word in the words array

```

## Color Functions:
```c
bool filterGray(words, paintedWord_t paintedWord); // Returns a version of the words array without any words containing grayLetters

bool filterYellow(words, paintedWord_t paintedWord); // Returns a version of the words array which only contains words which contain yellowLetters not in current spot

bool filterGreen(words, paintedWord_t paintedWord); // Returns a version of the words awwat which only contains words which have green letters in the right spot
```

## possible V2:
 - Sort/remove Null entries from vocab array
 - Threading
 - Different Data structures
 - Connect with python wordle
