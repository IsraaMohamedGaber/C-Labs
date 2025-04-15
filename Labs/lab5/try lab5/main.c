#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define arraylength 10

int main() {
    char input[arraylength + 1] = {0}; // Extra position for null terminator
    int position = 0; // Current cursor position
    int len = 0; // Current length of input

    printf("Enter Your Text: ");
    while (1) {
        int ch = getch();

        if (ch >= 32 && ch <= 126) { // Printable characters
            if (len < arraylength) {
                for (int i = len; i > position; i--) {
                    input[i] = input[i - 1];
                }
                input[position] = (char)ch;
                len++;
                position++;

                // Display updated input
                printf("\rEnter Your Text: %s", input);

                // Clear extra characters at the end
                for (int i = len; i < arraylength; i++) {
                    printf(" ");
                }
                printf("\rEnter Your Text: %s", input);

                // Move cursor to the correct position
                for (int i = len; i > position; i--) {
                    printf("\b");
                }
            }
        } else if (ch == 224) { // Extended keys
            ch = getch(); // Get extended key code

            switch (ch) {
                case 75: // Left arrow key
                    if (position > 0) {
                        position--;
                        printf("\b");
                    }
                    break;

                case 77: // Right arrow key
                    if (position < len) {
                        printf("%c", input[position]);
                        position++;
                    }
                    break;

                case 71: // Home key
                    while (position > 0) {
                        printf("\b");
                        position--;
                    }
                    break;

                case 79: // End key
                    while (position < len) {
                        printf("%c", input[position]);
                        position++;
                    }
                    break;
            }
        } else {
            switch (ch) {
                case 8: // Backspace key
                    if (position > 0) {
                        for (int i = position - 1; i < len - 1; i++) {
                            input[i] = input[i + 1];
                        }
                        len--;
                        position--;

                        input[len] = '\0';

                        printf("\rEnter Your Text: %s ", input);

                        // Clear extra character at the end
                        for (int i = len; i < arraylength; i++) {
                            printf(" ");
                        }

                        // Return cursor to the correct position
                        printf("\rEnter Your Text: %s", input);
                        for (int i = len; i > position; i--) {
                            printf("\b");
                        }
                    }
                    break;

                case 13: // Enter key
                    printf("\nFinal input: %s\n", input);
                    return 0;
            }
        }
    }
}
