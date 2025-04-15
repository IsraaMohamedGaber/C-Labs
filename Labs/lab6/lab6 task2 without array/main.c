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
int main()
{   struct Student student;
    inputStudent(&student);
    printStudent(student);
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
