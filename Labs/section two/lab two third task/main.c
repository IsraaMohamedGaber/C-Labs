#include <stdio.h>

int main() {
    int size, num = 1;
    int row, col, prerow, precol;

    printf("Enter an odd number for the size of the Box: ");
    scanf("%d", &size);

    if (size % 2 == 0) {
        printf("Size must be an odd number.\n");
    }
    row = 0;
    col = size / 2;

    while (num <= size * size) {

        if (col == 0) {
            printf("Placing number %d at position (%d, %d)\n", num, row + 1, size);  // Third column
        }
        else if (col == size - 1) {
            printf("Placing number %d at position (%d, %d)\n", num, row + 1, 1);  // First column
        }
        else {
            printf("Placing number %d at position (%d, %d)\n", num, row + 1, col + 1);
        }

        prerow = row;
        precol = col;
        row -= 1;
        col += 1;

        if (row < 0) row = size - 1;
        if (col >= size) col = 0;


        if (num % size == 0) {
            row = prerow + 1;
            col = precol;

            if (row >= size) row = 0;
        }

        num++;
    }

    return 0;
}
