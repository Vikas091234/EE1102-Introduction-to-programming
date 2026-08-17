/*
Course      : EE1102 - Introduction to Programming
Assignment  : 10
Program     : Employee Database Using Linked Lists

Description :
Reads employee information from a file and stores
employees in an array of structures. Project information
is represented using dynamically allocated linked-list
nodes.

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

struct ProjectLink {
    char project[MAX_PROJECT_LEN];
    struct ProjectLink *next;
};

struct Employee {
    int id;
    char name[MAX_NAME_LEN];
    char status[MAX_STATUS_LEN];
    char job_title[MAX_TITLE_LEN];
    float rating;
    struct ProjectLink *projects; // Linked list head pointer
    float hours_per_week;
    int reports_to[2];
};

struct ProjectLink *initProjectLink(const char *project) {
    struct ProjectLink *link = (struct ProjectLink *)malloc(sizeof(struct ProjectLink));
    if (link != NULL) {
        strncpy(link->project, project, sizeof(link->project) - 1);
        link->project[sizeof(link->project) - 1] = '\0';
        link->next = NULL;
    }
    return link;
}

void addProjectLink(struct ProjectLink **head, const char *project) {
    struct ProjectLink *newLink = initProjectLink(project);
    if (newLink == NULL) return;
    newLink->next = *head;
    *head = newLink;
}

void freeProjectList(struct ProjectLink *head) {
    struct ProjectLink *current = head;
    while (current != NULL) {
        struct ProjectLink *next = current->next;
        free(current);
        current = next;
    }
}

int readEmployeeData(struct Employee employees[]) {
    FILE *file = fopen("employee_data.txt", "r");
    if (file == NULL) {
        perror("Error opening file employee_data.txt");
        return 0;
    }

    int count = 0;
    while (count < MAX_EMPLOYEES) {
        int id, num_projects;
        char name[MAX_NAME_LEN], status[MAX_STATUS_LEN], job_title[MAX_TITLE_LEN];
        float rating;

        int prefix_read = fscanf(file, "%d %49s %19s %49s %f %d",
                                 &id, name, status, job_title, &rating, &num_projects);

        if (prefix_read == EOF) break;
        if (prefix_read != 6) break;

        employees[count].id = id;
        strncpy(employees[count].name, name, MAX_NAME_LEN - 1);
        strncpy(employees[count].status, status, MAX_STATUS_LEN - 1);
        strncpy(employees[count].job_title, job_title, MAX_TITLE_LEN - 1);
        employees[count].rating = rating;
        employees[count].projects = NULL;

        for (int p = 0; p < num_projects; ++p) {
            char proj[MAX_PROJECT_LEN];
            if (fscanf(file, "%49s", proj) == 1) {
                addProjectLink(&employees[count].projects, proj);
            }
        }

        float hours;
        int r1, r2;
        if (fscanf(file, "%f %d %d", &hours, &r1, &r2) == 3) {
            employees[count].hours_per_week = hours;
            employees[count].reports_to[0] = r1;
            employees[count].reports_to[1] = r2;
        }

        count++;
    }

    fclose(file);
    return count;
}

// -----------------------------------------------------------------------------
// Database Queries Q1 to Q6 with Linked List Traversals
// -----------------------------------------------------------------------------
void answerQueries(struct Employee employees[], int count) {
    printf("\n============ DATABASE ANSWERS (Q1 - Q6) ============\n");

    int prog_p1 = 0;
    float hours_p2 = 0.0f;

    for (int i = 0; i < count; i++) {
        if (strcmp(employees[i].status, "active") == 0) {
            int in_p1 = 0, in_p2 = 0;
            struct ProjectLink *cur = employees[i].projects;
            while (cur != NULL) {
                if (strcmp(cur->project, "1") == 0 || strcmp(cur->project, "Proj1") == 0) in_p1 = 1;
                if (strcmp(cur->project, "2") == 0 || strcmp(cur->project, "Proj2") == 0) in_p2 = 1;
                cur = cur->next;
            }

            if (in_p1 && strcasecmp(employees[i].job_title, "programmer") == 0) prog_p1++;
            if (in_p2) hours_p2 += employees[i].hours_per_week;
        }
    }

    printf("Q1: Programmers in Proj 1 = %d | Man-hours in Proj 2 = %.2f\n", prog_p1, hours_p2);
    printf("Q4: Active programmers in Proj 1 = %d\n", prog_p1);

    // Q6: Employees with no subordinates
    printf("Q6: Employees with no one reporting to them: ");
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

void freeEmployeeData(struct Employee employees[], int count) {
    for (int i = 0; i < count; ++i) {
        freeProjectList(employees[i].projects);
        employees[i].projects = NULL;
    }
}

int main(void) {
    struct Employee employees[MAX_EMPLOYEES];
    int count = readEmployeeData(employees);

    if (count > 0) {
        answerQueries(employees, count);
        freeEmployeeData(employees, count);
    } else {
        printf("No employee data read.\n");
    }

    return 0;
}