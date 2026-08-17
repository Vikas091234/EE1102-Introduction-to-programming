/*
Course      : EE1102 - Introduction to Programming
Assignment  : 10
Program     : Employee Database Using Arrays of Structures

Description :
Reads employee information from a file and stores
each employee as an element of an array of structures.
The structure contains employee, project, and reporting
information.

Author      : Vikas Raj
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 1000
#define MAX_NAME_LEN 50
#define MAX_STATUS_LEN 20
#define MAX_TITLE_LEN 50
#define MAX_PROJECT_LEN 50

struct Employee {
    int id;
    char name[MAX_NAME_LEN];
    char status[MAX_STATUS_LEN]; // "active" or "inactive"
    char job_title[MAX_TITLE_LEN];
    float rating;
    char projects[2][MAX_PROJECT_LEN];
    float hours_per_week;
    int reports_to[2]; // -1 or 0 if none
};

// -----------------------------------------------------------------------------
// Read employee data from file
// -----------------------------------------------------------------------------
int readEmployeeData(struct Employee employees[]) {
    FILE *file = fopen("employee_data.txt", "r");
    if (file == NULL) {
        perror("Error opening file employee_data.txt");
        return 0;
    }

    int count = 0;
    while (count < MAX_EMPLOYEES) {
        int read = fscanf(file, "%d %49s %19s %49s %f %49s %49s %f %d %d",
                          &employees[count].id,
                          employees[count].name,
                          employees[count].status,
                          employees[count].job_title,
                          &employees[count].rating,
                          employees[count].projects[0],
                          employees[count].projects[1],
                          &employees[count].hours_per_week,
                          &employees[count].reports_to[0],
                          &employees[count].reports_to[1]);

        if (read == EOF) break;
        if (read < 10) {
            // Handle optional 1 project format if necessary
            employees[count].reports_to[1] = -1;
        }
        count++;
    }

    fclose(file);
    return count;
}

// -----------------------------------------------------------------------------
// Add an Employee
// -----------------------------------------------------------------------------
int addEmployee(struct Employee employees[], int count, struct Employee newEmp) {
    if (count >= MAX_EMPLOYEES) {
        printf("Error: Database full. Cannot add employee.\n");
        return count;
    }
    employees[count] = newEmp;
    printf("Successfully added employee ID %d (%s).\n", newEmp.id, newEmp.name);
    return count + 1;
}

// -----------------------------------------------------------------------------
// Delete an Employee (by setting status to 'inactive' as per assignment rule)
// -----------------------------------------------------------------------------
int deleteEmployee(struct Employee employees[], int count, int id) {
    for (int i = 0; i < count; i++) {
        if (employees[i].id == id) {
            strcpy(employees[i].status, "inactive");
            printf("Employee ID %d marked as inactive (deleted).\n", id);
            return count;
        }
    }
    printf("Employee ID %d not found.\n", id);
    return count;
}

// -----------------------------------------------------------------------------
// Database Queries Q1 to Q6
// -----------------------------------------------------------------------------
void answerQueries(struct Employee employees[], int count) {
    printf("\n============ DATABASE ANSWERS (Q1 - Q6) ============\n");

    // Q1: Programmers in Proj 1 & Man-hours allocated to Proj 2
    int prog_p1 = 0;
    float hours_p2 = 0.0f;
    for (int i = 0; i < count; i++) {
        if (strcmp(employees[i].status, "active") == 0) {
            int in_p1 = (strcmp(employees[i].projects[0], "1") == 0 || strcmp(employees[i].projects[0], "Proj1") == 0 ||
                         strcmp(employees[i].projects[1], "1") == 0 || strcmp(employees[i].projects[1], "Proj1") == 0);
            int in_p2 = (strcmp(employees[i].projects[0], "2") == 0 || strcmp(employees[i].projects[0], "Proj2") == 0 ||
                         strcmp(employees[i].projects[1], "2") == 0 || strcmp(employees[i].projects[1], "Proj2") == 0);

            if (in_p1 && strcasecmp(employees[i].job_title, "programmer") == 0) prog_p1++;
            if (in_p2) hours_p2 += employees[i].hours_per_week;
        }
    }
    printf("Q1: Programmers in Proj 1 = %d | Total man-hours in Proj 2 = %.2f hrs\n", prog_p1, hours_p2);

    // Q2: Who reports to Manager X (e.g., Manager ID 135)
    int target_mgr_id = 135;
    printf("Q2: Employees reporting to Manager (ID %d): ", target_mgr_id);
    int found_q2 = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(employees[i].status, "active") == 0) {
            if (employees[i].reports_to[0] == target_mgr_id || employees[i].reports_to[1] == target_mgr_id) {
                printf("%s (ID: %d) ", employees[i].name, employees[i].id);
                found_q2 = 1;
            }
        }
    }
    if (!found_q2) printf("None");
    printf("\n");

    // Q3: Who is W's boss? (e.g. Employee W = ID 146)
    int emp_w_id = 146;
    printf("Q3: Boss(es) of Employee ID %d: ", emp_w_id);
    for (int i = 0; i < count; i++) {
        if (employees[i].id == emp_w_id) {
            printf("ID %d, ID %d", employees[i].reports_to[0], employees[i].reports_to[1]);
        }
    }
    printf("\n");

    // Q4: How many programmers are there in Proj 1?
    printf("Q4: Active programmers in Proj 1 = %d\n", prog_p1);

    // Q5: Which secretaries do not report to anyone?
    printf("Q5: Secretaries not reporting to anyone: ");
    int found_q5 = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(employees[i].status, "active") == 0 && strcasecmp(employees[i].job_title, "secretary") == 0) {
            if ((employees[i].reports_to[0] <= 0) && (employees[i].reports_to[1] <= 0)) {
                printf("%s (ID: %d) ", employees[i].name, employees[i].id);
                found_q5 = 1;
            }
        }
    }
    if (!found_q5) printf("None");
    printf("\n");

    // Q6: Which employees have no one reporting to them?
    printf("Q6: Employees with no inferiors reporting to them: ");
    for (int i = 0; i < count; i++) {
        if (strcmp(employees[i].status, "active") == 0) {
            int is_boss = 0;
            for (int j = 0; j < count; j++) {
                if (i != j && strcmp(employees[j].status, "active") == 0) {
                    if (employees[j].reports_to[0] == employees[i].id || employees[j].reports_to[1] == employees[i].id) {
                        is_boss = 1;
                        break;
                    }
                }
            }
            if (!is_boss) printf("%s ", employees[i].name);
        }
    }
    printf("\n====================================================\n\n");
}

int main() {
    struct Employee employees[MAX_EMPLOYEES];
    int count = readEmployeeData(employees);

    if (count > 0) {
        answerQueries(employees, count);
    } else {
        printf("No employee data loaded.\n");
    }

    return 0;
}