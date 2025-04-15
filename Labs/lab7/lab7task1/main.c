#include <stdio.h>

int main() {
    FILE *fp;
    char num[15]; // Assuming a maximum of 15 digits for the number

    // Write to a file
    fp = fopen("data.txt", "w");


    printf("Enter a number: ");
    scanf("%s", num);
    if(fp){

    fprintf(fp, "%s\n", num);
    fclose(fp);
    }
    printf("Number written to file: %s\n", num);

    // Read from the file and print to the screen
    fp = fopen("data.txt", "r");
    if (fp ){

    fscanf(fp, "%s", &num);
    fclose(fp);
}
    printf("Number read from file: %s\n", num);

    return 0;
}

