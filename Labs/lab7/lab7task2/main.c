#include <stdio.h>

int main() {
    FILE *fp;
    char num[10];
    // Write to a binary file
    fp = fopen("data.bin", "wb");


    printf("Enter a number: ");
    scanf("%c", &num);
    if(fp){

    fwrite(&num, sizeof(num), 1, fp);
    fclose(fp);
}
    printf("Number written to binary file: %d\n", num);

    // Read from the binary file and print to the screen
    fp = fopen("data.bin", "rb");
    if (fp) {


    fread(&num, sizeof(num), 1, fp);
    fclose(fp);}

    printf("Number read from binary file: %d\n", num);

    return 0;
}
