# EE1102 – Introduction to Programming Coursework

Coursework and programming assignments completed for **EE1102 – Introduction to Programming** at IIT Madras.

The repository contains C/C++ implementations for Assignments 0–9, together with the corresponding problem statements and assignment-level documentation.

## Repository Structure

```text
assignments/
├── README.md
├── Assignment_0/
├── Assignment_1/
├── Assignment_2/
├── Assignment_3/
├── Assignment_4/
├── Assignment_5/
├── Assignment_6/
├── Assignment_7/
├── Assignment_8/
└── Assignment_9/
```

Each assignment folder contains the source files for that assignment, its README, and the corresponding problem-statement PDF.

> **Note:** The `EE1103 – Numerical Methods` labels appearing in the source/header material of `Assignment_8` are treated here as a labeling error. This repository is being documented as **EE1102 coursework**, consistent with the surrounding assignments and the intended repository structure.

## Assignment Overview

| Folder | Assignment | Main topics |
|---|---:|---|
| `Assignment_0` | 0 | Basic C programming, variables, arithmetic, input/output |
| `Assignment_1` | 1 | Data types, arithmetic, strings, integer limits |
| `Assignment_2` | 2 | Conditionals, quadratic equations, polynomial operations |
| `Assignment_3` | 3 | Loops, digit manipulation, ASCII, Taylor series |
| `Assignment_4` | 4 | Recursion, prime testing, mathematical series |
| `Assignment_5` | 5 | Functions, strings, polynomial evaluation and multiplication |
| `Assignment_6` | 6 | Polynomial arithmetic, exponentiation, bit manipulation |
| `Assignment_7` | 7 | Pointers, pointer arithmetic, strings, file handling |
| `Assignment_8` | 8 | Pointer arrays, dynamic memory, matrices, function pointers, numerical integration |
| `Assignment_9` | 9 | Employee database, structures, dynamic memory, linked lists |

## Coursework Progression

```text
Basic C programming
        ↓
Data types and arithmetic
        ↓
Conditionals and mathematical programming
        ↓
Loops and numerical approximation
        ↓
Functions, recursion and algorithms
        ↓
Strings and polynomial operations
        ↓
Bit manipulation
        ↓
Pointers and file handling
        ↓
Dynamic memory, matrices and function pointers
        ↓
Structures, linked lists and file-based data processing
```

## Assignment 0 — Basic C Programming

Introduces the basic structure of a C program, variables, arithmetic expressions, formatted output, and console input.

Files:

- `hello.c` — basic program demonstrating program structure and output.
- `print_my_details.c` — prints student details.
- `sum.c` — reads five integers and computes their sum.
- `sum_of_squares.c` — reads three integers and computes the sum of their squares.

## Assignment 1 — Data Types and Arithmetic

Focuses on different C data types, integer and floating-point arithmetic, character arrays, formatted input/output, and integer representation.

Files:

- `diff.c` — difference between two integers.
- `mydetails.c` — reads and displays student information.
- `square_ratio.c` — computes a ratio involving the sum of squares and floating-point values.
- `budget.c` — performs institute-budget and computer-purchase calculations.
- `int_maximum.c` — demonstrates the maximum value representable by an integer.

## Assignment 2 — Conditionals and Polynomial Operations

Introduces conditional statements and mathematical programming through quadratic equations and polynomial operations.

Files:

- `quad.c` — solves a quadratic equation and classifies its roots.
- `poly_add.c` — adds two first-order polynomials.
- `poly_mul.c` — multiplies two first-order polynomials.
- `first_order_poly.c` — multiplies first-order polynomials in two variables.

The folder also contains `main.exe` and `quad.exe`, which are compiled executables rather than source files.

## Assignment 3 — Iteration and Numerical Approximation

Introduces `for` and `while` loops through character processing, digit extraction, and Taylor-series approximation.

Files:

- `ee19b108_alph.c` — prints the lowercase English alphabet.
- `digit.c` — decomposes an integer into decimal digits.
- `taylor_series_log.c` — approximates `ln(1+x)` using the first ten terms of its Taylor series.

## Assignment 4 — Recursion and Mathematical Algorithms

Introduces recursive functions and mathematical algorithms.

Files:

- `binomial_coefficient.cpp` — computes a binomial coefficient using recursive factorial functions.
- `prime_numbers.c` — checks whether an integer is prime.
- `sum_of_series.c` — evaluates an alternating mathematical series for different values of `N`.

This assignment contains the only C++ source file in the repository; the remaining coursework is primarily C.

## Assignment 5 — Functions, Strings and Polynomial Operations

Focuses on modular programming and reusable functions.

Files:

- `poly.c` — evaluates a polynomial for user-specified values.
- `poly_mul.c` — multiplies two polynomials.
- `string.c` — performs basic string manipulation.

## Assignment 6 — Polynomial Arithmetic and Bit Manipulation

Develops structured programming through polynomial representation and bit-mask-based string operations.

Files:

- `1st_order_poly.c` — generates a first-order polynomial of the form `(x + a)`.
- `poly_multiplication.c` — multiplies polynomials represented using coefficient arrays.
- `poly_power.c` — computes `(x + a)^n` using repeated polynomial multiplication.
- `bit_fields.c` — performs string transformations controlled by bit masks.

## Assignment 7 — Pointers and File Handling

Introduces pointer arithmetic and low-level string manipulation.

Files:

- `getline.c` — custom implementation for reading lines from a text file.
- `pointer_strcat.c` — implements string concatenation using pointers.
- `pointer_strlen.cpp` — computes string length using pointer arithmetic.

`pointer_strlen.cpp` is a C++ source file despite the assignment being primarily a C programming exercise.

## Assignment 8 — Pointers, Dynamic Memory, Matrices and Function Pointers

Introduces more advanced C programming concepts including arrays of pointers, dynamic memory allocation, two-dimensional arrays, matrix multiplication, function pointers, and numerical integration.

Files:

- `pointer_array.c` — reads strings and stores them using an array of pointers with dynamically allocated memory.
- `mat_mul.c` — multiplies a `4 × 5` matrix by a `5 × 3` matrix using two-dimensional arrays.
- `trapzd.c` — performs numerical integration using the trapezoidal rule and a function pointer.

The `EE1103` label present in some source/header material is treated as a typo for this repository documentation.

## Assignment 9 — Employee Database and Data Structures

Implements an employee database using three different data representations.

Files:

- `array.c` — represents employee information using separate arrays.
- `Array_of_structures.c` — represents each employee using an array of structures.
- `array_of_structures_list.c` — represents employees using structures and dynamically allocated linked lists for project information.

The programs work with information such as:

- employee ID
- name
- employment status
- job title
- rating
- projects
- hours per week
- reporting relationships

The assignment demonstrates structures, pointers to structures, dynamic memory allocation, linked lists, file handling, searching, and comparison of data representations.

The programs expect an input file named:

```text
employee_data.txt
```

This file is referenced by the source code but is **not present in the supplied repository archive**.

## Languages and Tools

- C
- C++
- GCC / G++
- Standard C libraries such as `stdio.h`, `stdlib.h`, `string.h`, and `math.h`

## Building the Programs

Most source files are standalone programs.

For C:

```bash
gcc path/to/program.c -o program
./program
```

For C++:

```bash
g++ path/to/program.cpp -o program
./program
```

For example:

```bash
gcc Assignment_9/array.c -o array
./array
```

The programs that read external data require their expected input files to be present in the working directory.

## Repository Notes

The assignment PDFs are included in the current coursework archive for reference.

For a clean public GitHub repository, generated executables such as:

```text
main.exe
quad.exe
```

would normally be removed or ignored.

The `.git` directory is repository metadata and does not need to be described as part of the coursework itself.

## Scope

This repository is a collection of **coursework implementations**, not a single standalone software project. Its main value is in showing the progression from basic C programming to pointers, dynamic memory, function pointers, structures, linked lists, and file-based data processing.
