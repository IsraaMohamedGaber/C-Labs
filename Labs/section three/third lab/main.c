#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>  // Needed for gotoxy function to work

void gotoxy(int x, int y);
int addNumbers(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
int power(int base, int exp);
int main() {
    char ch;
    int x = 1, y = 1;
    int a, b;
    printf("Hi if you want to move through app you can use the arrow keys to move the cursor .\n");
    printf("Press Enter to select.\n");
    do {
        ch = getch();
        // Extended key => arrow keys and enter key
        if (ch == -32) {
            // Get the second character
            ch = getch();
            switch (ch) {
                case 72:  // Arrow Up
                    if (y > 1) y--;  // Prevent going off-screen upwards
                    gotoxy(x, y);
                    break;
                case 80:  // Arrow Down
                    if (y < 25) y++;  // Prevent going off-screen downwards
                    gotoxy(x, y);
                    break;
                case 75:  // Arrow Left
                    if (x > 1) x--;  // Prevent going off-screen left
                    gotoxy(x, y);
                    break;
                case 77:  // Arrow Right
                    if (x < 80) x++;  // Prevent going off-screen right
                    gotoxy(x, y);
                    break;
            }
        } else if (ch == 13) {  // Enter key
            printf("\nEnter pressed. Choose an action:\n");
            printf("1: Add\n");
            printf("2: Subtract\n");
            printf("3: Multiply\n");
            printf("4: Power\n");
            printf("5: Home (Move to Top Left)\n");  // Added Home option
            printf("6: Exit\n");

            ch = getch();
            switch (ch) {
                case '1':
                    printf("Enter two numbers: ");
                    scanf("%d %d", &a, &b);
                    printf("Result: %d\n", addNumbers(a, b));
                    break;
                case '2':
                    printf("Enter two numbers: ");
                    scanf("%d %d", &a, &b);
                    printf("Result: %d\n", subtract(a, b));
                    break;
                case '3':
                    printf("Enter two numbers: ");
                    scanf("%d %d", &a, &b);
                    printf("Result: %d\n", multiply(a, b));
                    break;
                case '4':
                    printf("Enter base and exponent: ");
                    scanf("%d %d", &a, &b);
                    printf("Result: %d\n", power(a, b));
                    break;
                case '5':
                    gotoxy(1, 1);
                    printf("\nMoved to Home (1,1)\n");
                    break;
                case '6':
                    printf("Exiting...\n");
                    return 0;
            }
        }
    } while (ch != 27);  // Exit loop when 'Esc'

    return 0;
}


int addNumbers(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int power(int base, int exp) {
    if (exp == 0) {
        return 1;
    } else {
        return base * power(base, exp - 1);
    }
}

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
