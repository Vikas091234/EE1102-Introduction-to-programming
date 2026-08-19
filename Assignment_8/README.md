# Assignment 8 – Introduction to Programming

## Course

EE1103 – Numerical Methods

## Objective

This assignment introduces important C programming concepts including
pointer arrays, static two-dimensional arrays, matrix multiplication,
dynamic memory allocation, and function pointers.

The programs apply these concepts to string storage, matrix operations,
and numerical integration using the trapezoidal rule.

## Learning Outcomes

After completing this assignment, I learned to:

- Work with arrays of pointers
- Dynamically allocate and free memory using `malloc()` and `free()`
- Work with static two-dimensional arrays
- Implement matrix multiplication using nested loops
- Pass arrays to functions
- Use function pointers in C
- Implement numerical integration using the trapezoidal rule
- Analyze the time and space complexity of basic algorithms

## Files

| File | Description |
|------|-------------|
| `pointer_array.c` | Reads up to 10 strings and stores them using an array of pointers. |
| `mat_mul.c` | Multiplies a 4×5 matrix by a 5×3 matrix using static 2-D arrays. |
| `trapzd.c` | Computes a definite integral using the trapezoidal rule and a function pointer. |

## Concepts Covered

- Arrays
- Static 2-D Arrays
- Arrays of Pointers
- Strings
- Pointers
- Dynamic Memory Allocation
- `malloc()` and `free()`
- Functions
- Function Pointers
- Nested Loops
- Matrix Multiplication
- Numerical Integration
- Trapezoidal Rule
- Time and Space Complexity

## Complexity

### Pointer Array

For `N` strings with average length `L`:

- Time: `O(NL)`
- Space: `O(NL)`

### Matrix Multiplication

For multiplying an `M × N` matrix by an `N × P` matrix:

- Time: `O(MNP)`
- Space: `O(MP)` for the result matrix

For this assignment:

- A = `4 × 5`
- B = `5 × 3`
- Result = `4 × 3`

### Trapezoidal Integration

For `n` intervals:

- Time: `O(n)`
- Space: `O(1)`

## Compilation

Compile using GCC.

### Matrix Multiplication

```bash
gcc mat_mul.c -o mat_mul
./mat_mul
```
### Pointer Array

```bash
gcc pointer_array.c -o pointer_array
./pointer_array
```

### Trapezoid Integration

``` bash
gcc trapzd.c -o trapzd
./trapzd
```


