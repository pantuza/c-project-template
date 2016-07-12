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


/* include here your files that contain test functions */




/* A test case that does nothing and succeeds. */
static void null_test_success(void **state) {

    /**
     * If you want to know how to use cmocka, please refer to:
     * https://api.cmocka.org/group__cmocka__asserts.html
     */
    (void) state; /* unused */
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
        cmocka_unit_test(null_test_success),
    };


    /* Run the tests */
    return cmocka_run_group_tests(tests, NULL, NULL);
}
