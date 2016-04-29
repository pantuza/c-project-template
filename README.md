# C project template

A C project template with configure, Makefile, command line options parsing,
colors for pretty printing, valgrind analysis and unittest
using [cmocka](https://cmocka.org/).


### What is included

* Generic Makefile
* Command line options parsing (args.c, args.h)
* Colors for pretty printing (colors.h)
* Default messages like help, usage, version (messages.c, messages.h)
* Project structure directories (src, bin, lib, log, test)
* Test runner and structure (test/main.c)


### Makefile rules


* **all** - Compiles and link the program generating the binary file
* **tests** - Compiles tests using cmocka and run the test binary
* **clean** - Clean the project by removing generated files
* **valgrind** - Run valgrind tool to find memory leaks and buffer overflows
