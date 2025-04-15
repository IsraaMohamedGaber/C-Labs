#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
//#define arraylength 10
// Function to move the cursor
void gotoxy(int x, int y) ;
int main() {
   /* char ch;
    char input[arraylength + 1] = {0}; // extra postion for null terminator
    int postion = 0; // Current cursor position
    int counter = 0; // Current length of input
    printf("Enter Your Text ");
    gotoxy(0, 1);*/
    int arraylength;
    printf("Enter the maximum length of your text input: ");
    scanf("%d", &arraylength);
    getchar();  // Consume the newline character left in the buffer

    // Allocate memory dynamically for the input array
    char *input = (char *)malloc((arraylength + 1) * sizeof(char)); // +1 for null terminator
    if (input == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    char ch;
    int position = 0; // Current cursor position
    int counter = 0;  // Current length of input
    input[0] = '\0';  // Initialize input string

    //printf("Enter Your Text\n");
    gotoxy(0, 1);
   do {
        ch = getch();

        if (ch >= 33 && ch <= 127) {  // Printable characters
            if (counter < arraylength) {
                for (int i = counter; i > position; i--) {
                    input[i] = input[i - 1];
                }
                input[position] = (char)ch;
                counter++;
                position++;
                input[counter] = '\0';  // Null-terminate the string
                printf("\r%s ", input);
                gotoxy(position, 1);
            }
        }
        else if (ch == 224 || ch == -32) { // Extended keys
            ch = getch(); // Get extended key code
            switch (ch) {
                case 75: // Left arrow key
                    if (position > 0) {
                        position--;
                        gotoxy(position, 1);
                    }
                    break;
                case 77: // Right arrow key
                    if (position < counter) {
                        position++;
                        gotoxy(position, 1);
                    }
                    break;
                case 71: // Home key
                    position = 0;
                    gotoxy(position, 1);
                    break;
                case 79: // End key
                    position = counter;
                    gotoxy(position, 1);
                    break;
            }
        }
        else {
            switch (ch) {
                case 8: // Backspace key
                    if (position > 0) {
                        for (int i = position - 1; i < counter - 1; i++) {
                            input[i] = input[i + 1];
                        }
                        counter--;
                        position--;
                        input[counter] = '\0';  // Null-terminate the string
                        printf("\r%s ", input);
                        gotoxy(position, 1);
                    }
                    break;
                case 13: // Enter key
                    printf("\nFinal input: %s\n", input);
                    free(input);  // Free allocated memory
                    return 0;
            }
        }
    } while (ch != 27); // Exit loop when 'Esc' is pressed

    // Free allocated memory
    free(input);
    return 0;
}



void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
