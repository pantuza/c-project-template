# C project template

A C project template with configure, Makefile, command line options parsing,
colors for pretty printing, valgrind analysis and unittest
using [cmocka](https://cmocka.org/). For detailed informations, check out the [Wiki](https://github.com/pantuza/c-project-template/wiki)

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
* **help** - Prints a help message with target rules


### How to start

First, you have to clone this project and check if all dependencies are ok.
To verify that, you should compile, run and test the project without any
modifications:

#### Compiling the project

```bash
$> make
```
You will see compilation log output and them the following message:
> Binary file placed at bin/binary

#### Running binary file

```bash
$> ./bin/binary
```
You should see the command line options printed as a debugging message.

#### Testing project

```bash
$> make tests
```
You will see compilation output and the tests running results.

> 'make tests' compile the project using cmocka. The binary output will be:
> bin/binary_test_runner. Then it runs the tests binary

#### Author

Gustavo Pantuza <gustavopantuza@gmail.com>
