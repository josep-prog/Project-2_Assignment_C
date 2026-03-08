#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    float grade;
} Student;

void add_students(Student *students, int n);
void display_students(Student *students, int n);
void sort_students(Student *students, int n);
float calculate_average(Student *students, int n);
Student* find_top_student(Student *students, int n);
void grade_classification(Student *students, int n);

void add_students(Student *students, int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter ID for student %d: ", i + 1);
        scanf("%d", &students[i].id);
        getchar();

        printf("Enter Name for student %d: ", i + 1);
        fgets(students[i].name, 50, stdin);
        
        int nameLen = strlen(students[i].name);
        if (nameLen > 0 && students[i].name[nameLen - 1] == '\n')
            students[i].name[nameLen - 1] = '\0';

        printf("Enter Grade for student %d: ", i + 1);
        scanf("%f", &students[i].grade);
        getchar();
    }
}

void display_students(Student *students, int n) {
    printf("\n");
    printf("%-5s %-20s %s\n", "ID", "Name", "Grade");
    
    for (int i = 0; i < n; i++) {
        printf("%-5d %-20s %.2f\n", students[i].id, students[i].name, students[i].grade);
    }
}

void sort_students(Student *students, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (students[i].grade > students[j].grade) {
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
    
    printf("Students sorted by grade (ascending order)!\n");
}

float calculate_average(Student *students, int n) {
    float sum = 0;
    
    for (int i = 0; i < n; i++) {
        sum += students[i].grade;
    }
    
    return sum / n;
}

Student* find_top_student(Student *students, int n) {
    Student *topStudent = students;
    
    for (int i = 1; i < n; i++) {
        if (students[i].grade > topStudent->grade) {
            topStudent = &students[i];
        }
    }
    
    return topStudent;
}

char* get_letter_grade(float score) {
    if (score >= 90) return "A";
    if (score >= 80) return "B";
    if (score >= 70) return "C";
    if (score >= 60) return "D";
    return "F";
}

void grade_classification(Student *students, int n) {
    printf("\n");
    printf("%-5s %-20s %-8s %s\n", "ID", "Name", "Score", "Grade");
    for (int i = 0; i < n; i++) {
        char *letterGrade = get_letter_grade(students[i].grade);
        printf("%-5d %-20s %-8.2f %s\n", students[i].id, students[i].name, students[i].grade, letterGrade);
    }
}

int main() {
    int studentCount, studentID = 54321;
    printf("\n");
    printf("Student ID: %d\n", studentID);
    printf("Student Management System (10-15)\n");
    printf("Enter number of students: ");
    scanf("%d", &studentCount);

    Student *students = (Student *)malloc(studentCount * sizeof(Student));
    if (!students) {
        printf("Error: Memory allocation failed!\n");
        return 1;
    }

    void (*funcs[])(Student*, int) = {add_students, display_students, sort_students, grade_classification};
    float (*funcFloat)(Student*, int) = calculate_average;
    Student* (*funcTop)(Student*, int) = find_top_student;
    int choice;
    
    do {
        printf("\n");
        printf("--- Student Management Menu ---\n");
        printf("1. Add Students\n");
        printf("2. Display All Students\n");
        printf("3. Sort Students by Grade\n");
        printf("4. Calculate Average Grade\n");
        printf("5. Find Top Student\n");
        printf("6. Grade Classification\n");
        printf("7. Exit Program\n");
        printf("Enter your choice (1-7): ");

        scanf("%d", &choice);

        if (choice >= 1 && choice <= 4) {
            funcs[choice - 1](students, studentCount);
            if (choice == 1) printf("Students added successfully!\n");
        } else if (choice == 5) {
            Student *top = funcTop(students, studentCount);
            printf("\nTop Student: %s with %.2f\n", top->name, top->grade);
        } else if (choice == 6) {
            funcs[3](students, studentCount);
        } else if (choice == 7) {
            printf("Goodbye!\n");
        } else {
            printf("Invalid choice!\n");
        }
    } while (choice != 7);

    free(students);
    return 0;
}