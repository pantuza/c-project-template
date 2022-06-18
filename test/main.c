/*
 * ============================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  Main execution of the tests using cmocka
 *
 *        Created:  04/28/2016 19:21:37
 *       Compiler:  gcc
 *
 *         Author:  Gustavo Pantuza
 *   Organization:  Software Community
 *
 * ============================================================================
 */


#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include "../src/words.h";


/* include here your files that contain test functions */

static void bestWordReturnsWord(void **state) {
    (void) state; /* unused */
    char* outputWord = "";
    char** words = {"hello", "audio", "train", "split", "jumps"};

    outputWord = bestWord(words).word;

    assert_string_not_equal(outputWord, "");
}

static void filterGrayTrueWhenTrue(void **state){
    (void) state; /* unused */
    paintedWord_t pWord = { .word = {'h', 'e', 'l', 'l', 'o'}, .colors = {gray, gray, gray, gray, gray}};
    char** words = {"hello", "audio", "train", "split", "jumps"};

    bool output = filterGray(words);

    assert_true(output);
}

static void filterYellowTrueWhenTrue(void **state){
    (void) state; /* unused */
    paintedWord_t pWord = { .word = {'h', 'e', 'l', 'l', 'o'}, .colors = {yellow, yellow, yellow, yellow, yellow}};
    char** words = {"hello", "audio", "train", "split", "jumps"};

    bool output = filterYellow(words);

    assert_true(output);
}

static void filterGreenTrueWhenTrue(void **state){
    (void) state; /* unused */
    paintedWord_t pWord = { .word = {'h', 'e', 'l', 'l', 'o'}, .colors = {green, green, green, green, green}};
    char** words = {"hello", "audio", "train", "split", "jumps"};

    bool output = filterGreen(words);

    assert_true(output);
}

/**
 * Test runner function
 */
int
main(void) {

    /**
     * Insert here your test functions
     */
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(bestWordReturnsWord),
        cmocka_unit_test(filterGrayTrueWhenTrue),
        cmocka_unit_test(filterYellowTrueWhenTrue),
        cmocka_unit_test(filterGreenTrueWhenTrue),
    };


    /* Run the tests */
    return cmocka_run_group_tests(tests, NULL, NULL);
}
