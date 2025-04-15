#include <stdio.h>
#include <stdlib.h>

// Define the struct for a student
struct Student {
    int id;
    char name[100];
    int grades[2];
};
void inputStudent(struct Student *s);
void printStudent(struct Student s);
int main() {
    int n;
    printf("please enter the number of studdent you want to add in structure : ");
    scanf("%d",&n);
    struct Student *students=(struct Student *)malloc(n * sizeof(struct Student));
    //to make user put input of students
    for(int i;i<n;i++){
        printf("\n enter information of students: %d \n ",i+1);
        inputStudent(&students[i]);
    }
//print information
    printf("\nDisplaying information of students:\n");
    for (int i = 0; i < n; i++) {
        printStudent(students[i]);
    }
    free(students);
    return 0;
}

void inputStudent(struct Student *s) {
    printf("Enter Student ID: ");
    scanf("%d", &s->id);
    printf("Enter Student Name: ");
    scanf(" %[^\n]", s->name);  // Reads string with spaces
    printf("Enter two grades:\n");
    for (int i = 0; i < 2; i++) {
        printf("Grade %d: ", i + 1);
        scanf("%f", &s->grades[i]);
    }
}
void printStudent(struct Student s) {
    printf("\nStudent Information:\n");
    printf("ID: %d\n", s.id);
    printf("Name: %s\n", s.name);
    printf("Grades: %d, %d\n", s.grades[0], s.grades[1]);
}
