#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#define arraylength 10
// Function to move the cursor
void gotoxy(int x, int y) ;
int main() {
    char ch;
    char input[arraylength + 1] = {0}; // extra postion for null terminator
    int postion = 0; // Current cursor position
    int counter = 0; // Current length of input
    printf("Enter Your Text ");
    gotoxy(0, 1);
    do {
  ch = getch();
    if (ch >= 33 && ch <= 127) {
      if (counter < arraylength) {
        for (int i = counter; i > postion; i--) {
                    input[i] = input[i - 1];}
                input[postion] = (char)ch;
                counter++;
                postion++;
                printf("\r%s ", input);
                gotoxy(postion, 1);
            }
}if(ch == 224 || ch == -32) { // Extended keys
            ch = getch(); // Get extended key code
switch (ch) {
        case 75: // Left arrow key
                if (postion > 0) {
                        postion--;
                        gotoxy(postion, 1);
                }break;
                case 77: // Right arrow key
                    if (postion < counter) {
                        postion++;
                        gotoxy(postion, 1);
                    }break;
                case 71: // Home key
                    postion = 0;
                    gotoxy(postion, 1);
                    break;
                case 79: // End key
                    postion = counter;
                    gotoxy(postion, 1);
                    break;}
        } else {
            switch (ch) {
                case 8: // Backspace key
                    if (postion > 0) {
                        for (int i = postion - 1; i < counter - 1; i++) {
                            input[i] = input[i + 1];
                        }
                        counter--;
                        postion--;
                        input[counter] = '\0';
                        printf("\r%s ", input);
                        gotoxy(postion, 1);
                    }
                    break;
                case 13: // Enter key
                    printf("\nFinal input: %s\n", input);

                    return 0;
}} } while (ch != 27);  // Exit loop when 'Esc'
                    }

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
