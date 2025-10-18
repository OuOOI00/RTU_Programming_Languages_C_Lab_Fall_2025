// week5_task2_struct_save_load.c
// Task 2: Save and load structured records from a file
// Week 5 – Files & Modular Programming
// TODO: Complete function implementations and file handling logic.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    int age;
    float gpa;
} Student;

// Function prototypes
void save_student(Student s, const char *filename);
Student load_student(const char *filename);

int main(void) {
    Student s1;
    strcpy(s1.name, "Alice");
    s1.age = 21;
    s1.gpa = 3.75f;

    const char *filename = "student.txt";

    // TODO: Call save_student() to save student data to file
    save_student(s1, filename);
    // TODO: Call load_student() to read data back into a new struct
    Student s2 = load_student(filename);
    // TODO: Print loaded data to confirm correctness
    printf("Name :%s , Age: %d , GPA: %.2f ", s2.name, s2.age, s2.gpa);

    return 0;
}

// TODO: Implement save_student()
// Open file for writing, check errors, write fields, then close file
void save_student(Student s, const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error opening file");
        exit(EXIT_FAILURE);
    }

    
    fprintf(fp, "%s\n%d\n%.2f\n", s.name, s.age, s.gpa);
    fclose(fp);
}

// TODO: Implement load_student()
// Open file for reading, check errors, read fields, then close file
Student load_student(const char *filename) {
    Student stud;
    FILE *fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Could not open file\n");
        exit(EXIT_FAILURE);
    }

    
    if (fgets(stud.name, MAX_NAME_LEN, fp) == NULL) {
        fprintf(stderr, "Error name \n");
        fclose(fp);
        exit(EXIT_FAILURE);
    }

    
    if (fscanf(fp, "%d", &stud.age) != 1) {
        fprintf(stderr, "Error age \n");
        fclose(fp);
        exit(EXIT_FAILURE);
    }

    if (fscanf(fp, "%f", &stud.gpa) != 1) {
        fprintf(stderr, "Error GPA \n");
        fclose(fp);
        exit(EXIT_FAILURE);
    }
    fclose(fp);

    return stud;
}
