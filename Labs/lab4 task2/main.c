#include <stdio.h>
#include <stdlib.h>
void clrscr();
int main() {
    int grades[3][4];
    int i, j;
    int total_grades_of_student[3] = {0};  // Array to store total grades of each student
    int Four_subject_totals[4] = {0};  // Array to store total grades of each subject
    printf("Enter grades for 3 students in 4 subjects:\n");
    // outer loop for row and inner loop for column
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            printf("Student %d, Subject %d: ", i + 1, j + 1);
            scanf("%d", &grades[i][j]);
            total_grades_of_student[i] += grades[i][j];  // Calculate total grade for each student
            Four_subject_totals[j] += grades[i][j];  // Calculate total grade for each subject
        }
    }

    // Clear the screen after input
     clrscr();

    printf("Total grades for each student:\n");
    for (i = 0; i < 3; i++) {
        printf("Student %d: %d\n", i + 1, total_grades_of_student[i]);
    }
    printf("Average grade for each subject:\n");
    for (j = 0; j < 4; j++) {
        printf("Subject %d: %.3f\n", j + 1, (float)Four_subject_totals[j] / 3);
    }

    return 0;
}
//function Clear Screen
void clrscr()
{
    system("@cls||clear");
}


