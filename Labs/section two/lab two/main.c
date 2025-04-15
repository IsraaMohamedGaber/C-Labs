#include <stdio.h>
#include <stdlib.h>

int main()
{int num, max, min;

    printf("Enter the first number: ");
    scanf("%d", &num);
    max = num;
    min = num;

    for (int i = 1; i <5 ; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &num);
        if (num > max) {
            max = num;
        }
        if (num < min) {
            min = num;
        }
    }

    printf("Maximum number %d\n", max);
    printf("Minimum number %d\n", min);

    return 0;
}
