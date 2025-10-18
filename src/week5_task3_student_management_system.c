// week5_task3_student_management_system.c
// Task 3: Mini-project – Student management system with file persistence
// Week 5 – Files & Modular Programming
// TODO: Implement functions to load, save, add, and list students.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LEN 50
#define DATA_FILE "students.txt"

typedef struct {
    char name[NAME_LEN];
    int id;
    float gpa;
} Student;

// Function prototypes
int load_students(Student arr[]);
void save_students(Student arr[], int count);
void add_student(Student arr[], int *count);
void list_students(Student arr[], int count);

int main(void) {
    Student students[MAX_STUDENTS];
    int count = 0;
    int choice;

    // TODO: Load existing data from file using load_students()

    do {
        printf("\n=== Student Management System ===\n");
        printf("1. List students\n");
        printf("2. Add student\n");
        printf("3. Save and Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);
        getchar(); // clear newline

        switch (choice) {
            case 1:
                list_students(students, count);
                break;
            case 2:
                add_student(students, &count);
                break;
            case 3:
                save_students(students, count);
                break;
            default:
                printf("Error input data, try again\n");
        }
    } while (choice != 3);

    return 0;
}

// TODO: Implement load_students()
// Open DATA_FILE, read records until EOF, return number of records loaded
int load_students(Student arr[]) {
    int c = 0;
    FILE *fp = fopen(DATA_FILE, "r");
    if(fp ==NULL){
        return 0;
    }
    
    while(c<MAX_STUDENTS && fscanf(fp, "%d %s %f", &arr[c].id, arr[c].name, &arr[c].gpa)== 3){
        c++;
    }

    fclose(fp);
    return c;
}

// TODO: Implement save_students()
// Write all students to DATA_FILE
void save_students(Student arr[], int count) {
    FILE *fp = fopen(DATA_FILE, "w");

    if(fp==NULL){

        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < count; i++){
        
        fprintf(fp, "%d %s %f\n", arr[i].id,arr[i].name,arr[i].gpa);
    }



    fclose(fp);
}

// TODO: Implement add_student()
// Read input from user and append to array
void add_student(Student arr[], int *count) {
    if (*count >= MAX_STUDENTS){
        printf("Too much students");

        return;
    }

    Student studs;

    printf("Enter student ID: ");
    scanf("%d", &studs.id);
    getchar();

    printf("Type student's name: ");
    fgets(studs.name, NAME_LEN, stdin);

    printf("Enter GPA: ");
    scanf("%f", &studs.gpa);

    arr[*count] = studs;
    
    (*count)++;

    printf("students were added");
}

// TODO: Implement list_students()
// Print all students in readable format
void list_students(Student arr[], int count) {
    if (count == 0){
        printf("There is no students in the list\n");
        return;
    }

    printf("\n%-7s %-10s %-3s\n", "ID", "Name", "GPA");


    for (int i =0; i<count;i++){
        printf("%-7d %-10s %-3.2f \n", arr[i].id, arr[i].name, arr[i].gpa);
    }
}
