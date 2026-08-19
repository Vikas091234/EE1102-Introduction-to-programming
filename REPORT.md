# EE1102 Coursework Repository — Accuracy Report

## 1. Purpose

This report verifies the supplied repository structure and its documentation against the source files, assignment READMEs, and assignment problem-statement files.

The repository is organized into `Assignment_0` through `Assignment_9` and is intended to represent **EE1102 – Introduction to Programming** coursework.

For this review, the `EE1103 – Numerical Methods` labels appearing in `Assignment_8` are treated as a typo, as requested. They are not used to classify the repository.

---

## 2. Repository Structure

The supplied archive contains:

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

Every assignment folder contains:

- source code;
- an assignment-level README;
- the corresponding assignment PDF.

There is also a `.git` directory containing repository metadata.

---

## 3. Assignment-by-Assignment Verification

### Assignment 0

Files:

- `hello.c`
- `print_my_details.c`
- `sum.c`
- `sum_of_squares.c`

The code covers basic C program structure, variables, arithmetic, `printf()`, and `scanf()`.

The assignment-level README accurately describes these programs.

The source headers identify the programs as EE1102 and refer to Assignment 1 in the source header. The folder and problem statement identify this as Assignment 0. For repository organization, the folder/PDF numbering is used.

### Assignment 1

Files:

- `diff.c`
- `mydetails.c`
- `square_ratio.c`
- `budget.c`
- `int_maximum.c`

The programs cover integer and floating-point arithmetic, character arrays, formatted input/output, and integer limits.

The assignment README is substantially accurate.

### Assignment 2

Files:

- `quad.c`
- `poly_add.c`
- `poly_mul.c`
- `first_order_poly.c`
- `main.exe`
- `quad.exe`

The source programs cover:

- conditional statements;
- quadratic equation solving;
- root classification;
- first-order polynomial addition;
- polynomial multiplication;
- multiplication of first-order polynomials in two variables.

The README accurately describes the source programs.

The two `.exe` files are compiled artifacts and are not necessary for a source-code repository.

### Assignment 3

Files:

- `ee19b108_alph.c`
- `digit.c`
- `taylor_series_log.c`

The code covers:

- loops;
- ASCII character handling;
- decimal digit extraction;
- Taylor-series numerical approximation of `ln(1+x)`.

The README is accurate.

### Assignment 4

Files:

- `binomial_coefficient.cpp`
- `prime_numbers.c`
- `sum_of_series.c`

The code covers recursion, prime checking, functions, and an alternating mathematical series.

The README is accurate.

One important detail is that `binomial_coefficient.cpp` is C++, while the other files are C.

### Assignment 5

Files:

- `poly.c`
- `poly_mul.c`
- `string.c`

The code covers polynomial evaluation, polynomial multiplication, strings, arrays, loops, and functions.

The README accurately represents the contents.

### Assignment 6

Files:

- `1st_order_poly.c`
- `poly_multiplication.c`
- `poly_power.c`
- `bit_fields.c`

The code covers polynomial representation and arithmetic, polynomial exponentiation, functions, arrays, bit operations, and string processing.

The README accurately represents the contents.

### Assignment 7

Files:

- `getline.c`
- `pointer_strcat.c`
- `pointer_strlen.cpp`

The code covers pointer arithmetic, string manipulation, custom implementations of common string operations, and file input.

There is one correction required in the existing README:

> It lists `pointer_strlen.c`, but the actual file is `pointer_strlen.cpp`.

The corrected documentation uses the actual filename.

### Assignment 8

Files:

- `pointer_array.c`
- `mat_mul.c`
- `trapzd.c`

The programs cover:

- arrays of pointers;
- dynamic memory allocation;
- strings;
- two-dimensional arrays;
- matrix multiplication;
- function pointers;
- trapezoidal numerical integration.

The existing README describes these topics well, but its course label says EE1103. Per the requested repository interpretation, this is treated as a typo and the corrected documentation identifies the folder as EE1102 Assignment 8.

### Assignment 9

Files:

- `array.c`
- `Array_of_structures.c`
- `array_of_structures_list.c`

This is the most substantial data-structure-oriented assignment in the repository.

The three implementations represent the employee database using:

1. separate arrays;
2. an array of structures;
3. an array of structures with linked lists for project information.

The source code demonstrates:

- structures;
- structure members;
- pointers;
- dynamic memory allocation;
- linked lists;
- file input;
- searching;
- employee/project queries;
- reporting relationships.

The README accurately describes the intended design.

However, `employee_data.txt` is listed in the README as if it were part of the repository. It is **not present in the supplied archive**. The corrected root documentation therefore states that it is an external input file required by the programs but missing from this repository snapshot.

---

## 4. Documentation Problems Found

### Problem 1 — Root README has the wrong folder structure

The previous root README referred to:

```text
Assignment_1/
Assignment_2/
...
Assignment_8/
Assignment_10/
```

The actual repository contains:

```text
Assignment_0/
Assignment_1/
...
Assignment_8/
Assignment_9/
```

This has been corrected.

### Problem 2 — Root README omitted Assignment 0

`Assignment_0` is a real directory and contains the first problem statement and four source programs. It must be included in the root README.

### Problem 3 — Root README incorrectly omitted the assignment PDFs

The current archive contains the assignment PDFs inside every assignment folder.

Therefore, the root README should not say that the PDFs are absent.

### Problem 4 — Assignment 7 filename

The README refers to:

```text
pointer_strlen.c
```

The actual source file is:

```text
pointer_strlen.cpp
```

This has been corrected.

### Problem 5 — Assignment 8 course label

The existing Assignment 8 README identifies the course as EE1103. This is treated as a typo according to the intended repository structure and has been changed to EE1102 in the corrected documentation.

### Problem 6 — Assignment 9 input file

The Assignment 9 README lists:

```text
employee_data.txt
```

but the file is absent from the archive.

The corrected documentation explicitly identifies it as a required external input file rather than claiming it is included.

### Problem 7 — Compiled executables

Assignment 2 contains:

```text
main.exe
quad.exe
```

These are generated binaries. They are not part of the source implementation and would normally be removed from a clean GitHub repository or added to `.gitignore`.

---

## 5. Technical Progression

The repository provides a clear progression of programming concepts:

| Assignment | Main concepts |
|---|---|
| 0 | Program structure, variables, arithmetic, I/O |
| 1 | Data types, arithmetic, strings, integer representation |
| 2 | Conditionals, quadratic equations, polynomial arithmetic |
| 3 | Loops, ASCII, digit manipulation, Taylor series |
| 4 | Recursion, functions, prime testing, series |
| 5 | Functions, arrays, strings, polynomial operations |
| 6 | Polynomial arithmetic, exponentiation, bit manipulation |
| 7 | Pointers, pointer arithmetic, strings, file handling |
| 8 | Pointer arrays, dynamic memory, matrices, function pointers |
| 9 | Structures, dynamic memory, linked lists, file-based data |

This progression is a fair representation of the actual source material.

---

## 6. Strongest Coursework for a Portfolio

Not all assignments have equal value for a GitHub portfolio.

### Assignment 9

This is the strongest example for data structures because the same employee database is implemented using three different representations.

It demonstrates:

- arrays;
- structures;
- pointers;
- dynamic memory;
- linked lists;
- file handling;
- searching;
- data representation trade-offs.

### Assignment 8

This is useful for demonstrating more advanced C concepts:

- pointer arrays;
- dynamic allocation;
- matrix multiplication;
- function pointers;
- numerical integration.

### Assignment 7

Useful for demonstrating low-level C understanding through:

- pointer arithmetic;
- manual string operations;
- custom file-line handling.

### Assignments 5–6

Useful supporting coursework showing:

- modular programming;
- polynomial algorithms;
- strings;
- arrays;
- bit manipulation.

Assignments 0–4 are primarily foundational and need not all be highlighted individually on a resume.

---

