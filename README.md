# EE1102 – Introduction to Programming Coursework

A collection of programming exercises completed for **EE1102 – Introduction to Programming** at IIT Madras.

The repository is organized by assignment and focuses on progressively developing programming fundamentals in C, with one early exercise implemented in C++.

## Course Progression

The coursework progresses from basic console programs and arithmetic to pointers, dynamic memory, strings, bit manipulation, numerical methods, and data structures.

```text
Basic C programs
      ↓
Data types & arithmetic
      ↓
Conditionals & mathematical programming
      ↓
Loops & numerical approximation
      ↓
Functions & recursion
      ↓
Arrays, strings & modular programming
      ↓
Bit manipulation
      ↓
Pointers & file handling
      ↓
Structures, dynamic memory & linked lists
```

## Repository Structure

```text
EE1102_Introduction_to_Programming/
├── README.md
├── .gitignore
│
└── assignments/
    ├── Assignment_1/
    ├── Assignment_2/
    ├── Assignment_3/
    ├── Assignment_4/
    ├── Assignment_5/
    ├── Assignment_6/
    ├── Assignment_7/
    ├── Assignment_8/
    └── Assignment_10/
```

The original problem-statement PDFs and lecture notes are intentionally not included. The repository contains the implementation code and assignment-level documentation rather than copied course material.

## Assignments

### Assignment 1 — Basic C Programming

Introduces the structure of a C program, variables, arithmetic expressions, formatted input/output, and basic console interaction.

Representative programs:

- `hello.c`
- `print_my_details.c`
- `sum.c`
- `sum_of_squares.c`

### Assignment 2 — Data Types and Arithmetic

Works with integer and floating-point arithmetic, character arrays, larger integer types, and integer representation.

Representative programs:

- `diff.c`
- `mydetails.c`
- `square_ratio.c`
- `budget.c`
- `int_maximum.c`

### Assignment 3 — Conditionals and Polynomial Operations

Introduces decision making, quadratic equations, discriminants, and first-order polynomial operations.

Representative programs:

- `quad.c`
- `poly_add.c`
- `poly_mul.c`
- `first_order_poly.c`

### Assignment 4 — Iteration and Numerical Approximation

Uses `for` and `while` loops, ASCII characters, digit extraction, and Taylor-series approximation.

Representative programs:

- `ee19b108_alph.c`
- `digit.c`
- `taylor_series_log.c`

### Assignment 5 — Recursion and Mathematical Algorithms

Introduces recursive functions, primality testing, alternating series, reusable functions, and input validation.

Representative programs:

- `binomial_coefficient.cpp`
- `prime_numbers.c`
- `sum_of_series.c`

### Assignment 6 — Modular Programming and Strings

Focuses on reusable functions, polynomial evaluation and multiplication, arrays, and basic string processing.

Representative programs:

- `poly.c`
- `poly_mul.c`
- `string.c`

### Assignment 7 — Polynomial Arithmetic and Bit Manipulation

Uses coefficient arrays, polynomial multiplication and exponentiation, reusable functions, and bit-mask based string operations.

Representative programs:

- `1st_order_poly.c`
- `poly_multiplication.c`
- `poly_power.c`
- `bit_fields.c`

### Assignment 8 — Pointers and File Handling

Introduces pointer arithmetic, custom string functions, and line-oriented file input.

Representative programs:

- `getline.c`
- `pointer_strcat.c`
- `pointer_strlen.cpp`

### Assignment 10 — Employee Database and Data Structures

The most substantial assignment in this repository. The same employee database is implemented using multiple data representations:

1. parallel arrays;
2. arrays of structures;
3. arrays of structures with linked lists.

The work covers:

- structures
- pointers to structures
- dynamic memory allocation
- linked lists
- file handling
- searching
- data representation trade-offs
- basic time/space complexity analysis

Representative programs:

- `array.c`
- `Array_of_structures.c`
- `array_of_structures_list.c`

## Most Substantial Work

The later assignments provide the strongest evidence of programming depth.

### Assignment 8

Demonstrates low-level string manipulation using pointers and a custom file-reading function.

### Assignment 10

Provides the strongest single piece of coursework in this repository. The same employee database is represented using arrays, structures, and linked lists, allowing direct comparison of fixed-size and dynamically linked representations.

The linked-list implementation uses dynamic allocation for project information and demonstrates traversal, insertion, memory management, and structured data processing.

## Language and Tools

- C
- C++ (one assignment exercise)
- GCC / G++
- Standard C libraries such as `stdio.h`, `stdlib.h`, `string.h`, and `math.h`

## Building a Program

Most individual programs are standalone source files. For example:

```bash
gcc assignments/Assignment_10/array.c -o array
./array
```

For C++:

```bash
g++ assignments/Assignment_5/binomial_coefficient.cpp -o binomial_coefficient
./binomial_coefficient
```

Refer to the README inside each assignment directory for the program descriptions and assignment-specific compilation notes.

## Why Some Files Are Not Included

The original coursework directory also contained:

- assignment problem-statement PDFs;
- lecture notes;
- lecture recordings;
- compiled Windows executables.

These are intentionally excluded from the GitHub repository. The repository is meant to contain the student's implementation work and documentation, not redistributed course material or generated binaries.

## Assignment 9 Note

The uploaded source files under the original `Assignment_9` directory identify themselves as **EE1103 – Numerical Methods**, including the source-code headers and assignment README. Because this repository represents **EE1102 – Introduction to Programming**, that directory has been left out rather than incorrectly presenting EE1103 coursework as EE1102 work.

## Resume Relevance

This repository is best treated as **coursework evidence**, not as a standalone project. The strongest material for highlighting programming ability is:

- pointers and file handling from Assignment 8;
- structures, dynamic memory, linked lists, and data representation from Assignment 10;
- bit manipulation from Assignment 7;
- recursion and modular programming from Assignments 5–6.

For an ML-hardware-oriented profile, the repository complements larger hardware/architecture projects by demonstrating a C-level programming foundation.
