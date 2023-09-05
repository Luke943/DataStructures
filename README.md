## Description

Common data structures implemented in C.

Data structures included:
- Queue
- Stack
- Linked list
- Doubly linked list
- Binary search tree

## Contents

Each data structure has a source file in the `/src` directrory and corresponding header file in `/include`.

The `/tests` directory contains a test file for each data structure.

## Build

To compile all data structure object files and test executables:
1. In `Makefile`, change `CC` and `CFLAGS` to your chosen compiler and required flags.
2. Run `make`.
3. This will create a `/build` directory with the binary files.

To remove `/build` and its contents, run `make clean` 
