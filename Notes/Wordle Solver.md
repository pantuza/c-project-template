# homework 6: Strings, Searching, Pointers!

**Due date: Tuesday, 01 March 2022, 11:59pm**

# introduction

In this homework, we will implement a solver for the popular word-guessing game
wordle, building on our work from last week!

This solver will work in two different ways -- either the secret word may be
known to the user and specified to the program (useful for testing purposes, so
that the program can whittle down the search space until it finds the specified
word), or the solver can iteratively suggest guesses to the user, so as to
search for solutions to a live problem.

## picking a word to guess

There has been a lot of discussion on how to find the *optimal* guess words in
wordle (for example, see the [excellent](https://youtu.be/v68zYyaEmEA)
[videos](https://youtu.be/fRed0Xmc2Wg) from educational math YouTuber
3Blue1Brown) but here we will use a simple heuristic score -- we pick the
word that contains the letters that occur most commonly in the remaining
possible vocabulary.

So at each step in our solver, we select the word that maximizes the following
expression:

```
  score(word | vocabulary) = sum(score(letter | vocabulary), for unique letters in word)
```

where

```
  score(letter | vocabulary) = # words in vocabulary that contain letter
```

For our purposes here, this is *easier to understand* and *easier to implement*
than a more principled information-theoretic approach. Notably, the score
for a letter and a word both depend on the words that are currently in the
vocabulary, which we update based on the response received after every guess.

Relatedly, why do we care about only considering *unique* letters? Well, if we
do not, we will only get information about the most common letters. If we do not
include this restriction, our first guess (given the initial vocabulary) will be
"eerie", since 'e' is so common. But the answer for the word "eerie" is only so
informative -- we could do better by including a more diverse selection of
common letters! (you could [formalize this by quantifying how many bits of
information you will learn by asking the
question](https://en.wikipedia.org/wiki/Entropy_(information_theory)), but this
is more of a topic for an AI class)

Empirically, this heuristic works fairly well, and paired with the approaches to
whittling the vocabulary described in the next section, each guess causes the
size of our search space to *drastic* go down.

## paring down our vocabulary

Every time we get feedback from a guess, this gives us the opportunity to cut
down the remaining vocabulary list, eliminating many words from consideration!

Imagine that we don't know anything about the true secret word, and then we make
the following guess, resulting in the following response:

![guessing "irate" on a recent wordle](irate.png "guessing irate")

Each color in the response gives us information, constraining the remaining
search space. Here we guessed "irate", and the official Wordle game gave us
back: gray, green, gray, yellow, green. We represent this in our programs as
"xgxyg".

This means that 'r' and 'e' are in the correct place, and 't' is present
somewhere in the word, but not in the spot that we guessed. Also, 'i' and 'a' do
not appear in the true secret word. That's a lot of information! How can we
apply it?

### limiting the vocabulary based on "gray" responses

If we know that a letter is not present in the secret word, then we can simply
remove any word in the vocabulary if it contains that letter!

So for example, if we find out that the letter 'm' is not in the secret word,
then any word that *does* contain 'm' is not the secret word and can be safely
eliminated.

How do we eliminate words from our vocabulary? Recall that we've been
representing our vocabularies as an array of `char *` pointers, so a
dynamically-sized array of type `char **`. That means that each element of the
outer array is a pointer to a string.

We can simply free that string and set the corresponding pointer in the outer
array to `NULL`. And then the word is eliminated from consideration! (we need to
make sure all functions that iterate over the vocabulary are robust to having
pointers in the outer array being `NULL`).

There is one more wrinkle on "gray" responses, and it is slightly subtle -- we
did not handle this particular rule in the previous homework -- if a letter
appears multiple times in a guess, but fewer times in the secret word, then the
"extra" instances of that letter are marked as gray in the wordle response. You
do not have to worry about this rule in your code, but it is addressed in
`solver.c`.

### limiting the vocabulary based on "yellow" responses

Similarly, a "yellow" response for a letter means that the corresponding letter
in the guess *appears in the secret word*, but interestingly, not in the
location that was guessed.

This means that we can eliminate any word that does not contain that particular
letter. But moreover, we can eliminate any word that contains the letter, in the
specific spot that was guessed!

### limiting the vocabulary based on "green" responses

Finally, the simplest case is "green" responses. Green responses allow us to
eliminate any word from the vocabulary that does not contain the specified
letter in the specified spot.


## interacting with the solver

The main interaction loop for this program happens in `solver.c`, which is
provided for you, and you do not need to make changes to it.

It can be called in one of two different ways:

```
$ ./solver motif
```

This runs the guessing algorithm with a specified secret word, automatically.

Or alternatively, to play a wordle puzzle with an unknown word (ie, live on a
website):

```
$ ./solver
```

This will suggest guesses for the user, and prompt them to input the result as a
string of 5 characters (some sequence of 'g' 'y' and 'x'), making more
suggestions as it narrows the search space.


## Pieces to implement

The general shape of the program has been implemented for you, but some of the
functions have been replaced with stubs, which are for you to implement. There
are some explanatory comments, which should guide you on your path to building
your own wordle solver in C.

All of the code you need to finish is in `search_util.c`.


## Cleaning up our messes

For this homework, we are allocating some dynamic data structures, with
`malloc`, `calloc`, and `realloc`.

Most of the work has been done for you already, but you need to make sure that
we have a plan for `free`-ing all the memory we allocate. Which parts of the
code will allocate? How can you make sure every allocated pointer gets `free`d?

In order to find out whether your code is cleaning up its messes, you should use
a tool called Valgrind.

If you have not yet installed Valgrind on your Linux system, you can install it
like so:
```
sudo apt install valgrind
```

You can run Valgrind to find out whether your program is leaking memory with the
following command:

```
valgrind --leak-check=full  ./solver rinse
```

Valgrind will then tell you whether you are successfully cleaning up all of the
allocated memory, or whether your program has leaks.


## deliverables

All of your deliverables for this homework should be checked in to a directory
called `hw6` in your CSE13s gitlab repository. Remember -- *add, commit, push*.

The resources you need are available in this directory.

  * By **Saturday, 26 February 2022**, you should have written your `DESIGN.md`,
    containing your thoughts and plans and pseudocode for this assignment.
  * `search_util.c` -- most of your implementation will go in this file. Finish
    all of the unfinished functions in here.
  * `search_util.h` -- you will probably not need to change this file, but make
    sure to include it.
  * `demo_functions.c` -- space for you to exercise all of the functions you're
    developing in `search_util.c`
  * `solver.c` -- the main driver for the wordle solver. You may not need to
    change this file, but please include it for completeness.
  * Makefile -- make sure that you use the standard flags for the class in your
    Makefile.

## reading

You should read...
  * _The C Programming Language_ by Kernighan & Ritchie, Chapter 7 (to
    understand the I/O happening here).
  * _The C Programming Language_ by Kernighan & Ritchie, Chapter 8 (more
    discussion of I/O, also an explanation of realloc).
