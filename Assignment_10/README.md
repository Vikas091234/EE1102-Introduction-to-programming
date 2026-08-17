# Assignment 10 – Introduction to Programming

## Course

EE1102 – Introduction to Programming

## Objective

This assignment implements a simple employee database using different
data representation techniques in C.

The same employee information is represented using:

1. Arrays
2. Arrays of structures
3. Arrays of structures containing linked lists

The purpose is to understand how different data structures affect the
organization and management of the same data.

## Learning Outcomes

After completing this assignment, I learned to:

- Read structured data from a file
- Store records using arrays
- Define and use structures in C
- Create arrays of structures
- Access structure members using `.` and `->`
- Use pointers to structures
- Implement linked lists
- Dynamically allocate and free memory
- Search and process structured data
- Compare different data representations
- Understand the basic trade-offs between arrays and linked lists

## Database

The database represents employees of an IT company.

Each employee record contains information such as:

- Employee ID
- Name
- Employment status
- Job title
- Rating
- Projects
- Hours per week
- Reporting managers

The programs are required to answer questions about projects,
employees, and reporting relationships.

## Files

| File | Description |
|------|-------------|
| `array.c` | Stores employee information using basic arrays. |
| `Array_of_structures.c` | Stores each employee as an element of a structure array. |
| `array_of_structures_list.c` | Uses an array of employee structures with linked lists for project information. |
| `employee_data.txt` | Input file containing employee records. |

## Concepts Covered

- Arrays
- Structures
- Arrays of Structures
- Pointers to Structures
- Dynamic Memory Allocation
- Linked Lists
- File Handling
- `fopen()` and `fscanf()`
- `malloc()` and `free()`
- Searching
- Data Representation

## Data Structure Comparison

### Arrays

Employee information is stored in separate arrays.

This approach is simple but becomes difficult to manage when each
employee can belong to multiple projects.

### Arrays of Structures

Each employee is represented by one structure containing all of the
employee's information.

This keeps related information together and makes the program easier
to organize.

### Arrays of Structures with Linked Lists

Each employee is stored as a structure, while a linked list is used
to represent a variable number of projects.

This removes the fixed project limit and demonstrates dynamic data
structures.

## Complexity

Let:

- `N` = number of employees
- `P` = number of projects

Basic traversal of all employee records is:

- **Time:** `O(N)`

Searching through an employee's linked list of projects may require:

- **Time:** `O(P)`

Searching all employees and their projects can therefore require:

- **Time:** `O(NP)` in the worst case.

The linked-list representation uses additional memory for each node:

- **Space:** `O(N + total number of project links)`

## Compilation

Compile using GCC.

### Arrays

```bash
gcc array.c -o array
./array
```
### Array of structures

```bash
gcc Array_of_structures.c -o Array_of_structures
./Array_of_structures
```
### Array of structures with linked lists

```bash
gcc array_of_structures_list.c -o array_of_structures_list
./array_of_structures_list
```
