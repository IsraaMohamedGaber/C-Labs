#include <stdio.h>
#include <stdlib.h>

int main() {
    int numbers[4];
    int i, maxindex, minindex;
    // Get Five input from the user
    printf("Please Enter Five numbers:\n");
    for (i = 0; i < 5; i++) {
        scanf("%d", &numbers[i]);
    }
    maxindex = 0;
    minindex = 0;
    // Find the index of the maximum and minimum numbers
    for (i = 1; i < 5; i++) {
        if (numbers[i] > numbers[maxindex]) {
            maxindex = i;
        }
        if (numbers[i] < numbers[minindex]) {
            minindex = i;
        }
    }
    printf("\nIndex of Maximum Number: %d\n", maxindex);
    printf("\nIndex of Minimum Number: %d\n", minindex);
    return 0;
}

