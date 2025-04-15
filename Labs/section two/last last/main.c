#include <stdio.h>

int main() {
    int n;

    // Loop until an odd number is entered
    do {
        printf("Enter the size of the  Box (odd number): ");
        scanf("%d", &n);

        if (n % 2 == 0) {
            printf("The number must be odd. Please try again.\n");
        }
    } while (n % 2 == 0);  // Keep asking if the number is even

    int num = 1;  // Start from 1
    int r = 1;    // Start at row 1
    int c = (n + 1) / 2;  // Start in the middle column

    while (num <= n * n) {
        // Swap the first column with the last column
        int display_col = c;
        if (c == 1) {
            display_col = n;  // Swap 1st column with last column
        } else if (c == n) {
            display_col = 1;  // Swap last column with 1st column
        }

        // Print the current position and the number
        printf("num = %d is placed at row = %d, column = %d\n", num, r, display_col);

        // Save the current row and column
        int new_r = r - 1;  // Move up one row
        int new_c = c + 1;  // Move right one column

        // Wrap around the row if it goes out of bounds
        if (new_r < 1) {
            new_r = n;
        }

        // Wrap around the column if it goes out of bounds
        if (new_c > n) {
            new_c = 1;
        }

        // If the current number is divisible by 'n', move directly down
        if (num % n == 0) {
            new_r = r + 1;
            new_c = c;
        }

        // Update to new row and column
        r = new_r;
        c = new_c;

        // Increment the number for the next iteration
        num++;
    }

    return 0;
}
