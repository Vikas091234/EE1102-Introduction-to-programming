/*
Course      : EE1102 - Introduction to Programming
Assignment  : 10
Program     : Employee Database Using Arrays

Description :
Reads employee information from a file and stores
the data using arrays. The program processes employee,
project, and reporting information using the array-based
representation.

Author      : Vikas Raj
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 100

// -----------------------------------------------------------------------------
// Parallel Arrays Representation
// -----------------------------------------------------------------------------
int ids[MAX_EMPLOYEES];
char names[MAX_EMPLOYEES][50];
char statuses[MAX_EMPLOYEES][20];
char job_titles[MAX_EMPLOYEES][50];
float ratings[MAX_EMPLOYEES];
char projects[MAX_EMPLOYEES][50];
float hours_per_week[MAX_EMPLOYEES];

// -----------------------------------------------------------------------------
// Function: readEmployeeData
// Reads employee records from "employee_data.txt" into parallel arrays.
// -----------------------------------------------------------------------------
int readEmployeeData() {
    FILE *file = fopen("employee_data.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 0;
    }

    int count = 0;
    while (fscanf(file, "%d %s %s %s %f %s %f",
                  &ids[count],
                  names[count],
                  statuses[count],
                  job_titles[count],
                  &ratings[count],
                  projects[count],
                  &hours_per_week[count]) == 7) {
        count++;
        if (count >= MAX_EMPLOYEES) {
            printf("Warning: Maximum employee capacity reached.\n");
            break;
        }
    }

    fclose(file);
    return count;
}

// -----------------------------------------------------------------------------
// Function: printEmployeeData
// Prints details of all stored employees from the parallel arrays.
// -----------------------------------------------------------------------------
void printEmployeeData(int count) {
    printf("\n=== Employee Records (%d Total) ===\n", count);
    for (int i = 0; i < count; i++) {
        printf("ID: %d | Name: %s | Status: %s | Title: %s | Rating: %.2f | Project: %s | Hours/Wk: %.2f\n",
               ids[i], names[i], statuses[i], job_titles[i], ratings[i], projects[i], hours_per_week[i]);
    }
    printf("===================================\n\n");
}

// -----------------------------------------------------------------------------
// Function: addEmployee
// Adds a new employee record to the parallel arrays.
// -----------------------------------------------------------------------------
int addEmployee(int count, int id, const char *name, const char *status, 
                const char *title, float rating, const char *project, float hours) {
    if (count >= MAX_EMPLOYEES) {
        printf("Error: Cannot add employee. Array full.\n");
        return count;
    }

    ids[count] = id;
    strcpy(names[count], name);
    strcpy(statuses[count], status);
    strcpy(job_titles[count], title);
    ratings[count] = rating;
    strcpy(projects[count], project);
    hours_per_week[count] = hours;

    printf("Successfully added employee ID %d: %s\n", id, name);
    return count + 1;
}

// -----------------------------------------------------------------------------
// Function: deleteEmployee
// Deletes an employee by ID by shifting left subsequent array elements.
// -----------------------------------------------------------------------------
int deleteEmployee(int count, int target_id) {
    int found_index = -1;

    for (int i = 0; i < count; i++) {
        if (ids[i] == target_id) {
            found_index = i;
            break;
        }
    }

    if (found_index == -1) {
        printf("Error: Employee ID %d not found.\n", target_id);
        return count;
    }

    // Shift elements left to overwrite deleted entry
    for (int i = found_index; i < count - 1; i++) {
        ids[i] = ids[i + 1];
        strcpy(names[i], names[i + 1]);
        strcpy(statuses[i], statuses[i + 1]);
        strcpy(job_titles[i], job_titles[i + 1]);
        ratings[i] = ratings[i + 1];
        strcpy(projects[i], projects[i + 1]);
        hours_per_week[i] = hours_per_week[i + 1];
    }

    printf("Successfully deleted employee ID %d.\n", target_id);
    return count - 1;
}

// -----------------------------------------------------------------------------
// Database Queries (Q1 - Q5)
// -----------------------------------------------------------------------------

// Q1: Search employee by ID
void answerQ1_searchById(int count, int search_id) {
    printf("[Q1] Searching for Employee ID %d:\n", search_id);
    for (int i = 0; i < count; i++) {
        if (ids[i] == search_id) {
            printf("     Found: %s | Title: %s | Project: %s\n", names[i], job_titles[i], projects[i]);
            return;
        }
    }
    printf("     Employee ID %d not found.\n", search_id);
}

// Q2: Calculate average performance rating
void answerQ2_averageRating(int count) {
    if (count == 0) return;
    float sum = 0.0f;
    for (int i = 0; i < count; i++) {
        sum += ratings[i];
    }
    printf("[Q2] Average Performance Rating: %.2f\n", sum / count);
}

// Q3: Find employee working the maximum hours per week
void answerQ3_maxHoursWorked(int count) {
    if (count == 0) return;
    int max_idx = 0;
    for (int i = 1; i < count; i++) {
        if (hours_per_week[i] > hours_per_week[max_idx]) {
            max_idx = i;
        }
    }
    printf("[Q3] Employee with Max Hours: %s (%.2f hrs/wk)\n", names[max_idx], hours_per_week[max_idx]);
}

// Q4: Count full-time vs contract employees
void answerQ4_countByStatus(int count) {
    int full_time = 0, contract = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(statuses[i], "FullTime") == 0) full_time++;
        else if (strcmp(statuses[i], "Contract") == 0) contract++;
    }
    printf("[Q4] Employment Breakdown: FullTime = %d, Contract = %d\n", full_time, contract);
}

// Q5: List employees assigned to a specific project
void answerQ5_listByProject(int count, const char *target_project) {
    printf("[Q5] Employees working on '%s':\n", target_project);
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(projects[i], target_project) == 0) {
            printf("     - %s (ID: %d)\n", names[i], ids[i]);
            found++;
        }
    }
    if (!found) {
        printf("     No employees currently assigned to %s.\n", target_project);
    }
}

// -----------------------------------------------------------------------------
// Main Execution Workflow
// -----------------------------------------------------------------------------
int main() {
    int count = readEmployeeData();

    if (count == 0) {
        printf("No employee records loaded.\n");
        return 1;
    }

    // 1. Display Initial Dataset
    printEmployeeData(count);

    // 2. Execute Database Queries Q1-Q5
    printf("--- Database Queries (Q1 - Q5) ---\n");
    answerQ1_searchById(count, ids[0]);  // Search first loaded employee
    answerQ2_averageRating(count);
    answerQ3_maxHoursWorked(count);
    answerQ4_countByStatus(count);
    answerQ5_listByProject(count, projects[0]);
    printf("----------------------------------\n\n");

    // 3. Add Employee Demonstration
    printf("--- Performing Add Operation ---\n");
    count = addEmployee(count, 999, "Alice", "FullTime", "Engineer", 4.8f, "ProjectX", 40.0f);
    printEmployeeData(count);

    // 4. Delete Employee Demonstration
    printf("--- Performing Delete Operation ---\n");
    count = deleteEmployee(count, 999);
    printEmployeeData(count);

    return 0;
}