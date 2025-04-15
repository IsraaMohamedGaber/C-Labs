#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    double a, b, c, equation, root1, root2;
    printf("Enter the coefficients a, b,c: ");
    scanf("%lf", &a);
    scanf("%lf", &b);
    scanf("%lf", &c);
    equation = b * b - 4 * a * c;
    if (equation > 0) {
        root1 = (-b + sqrt(equation)) / (2 * a);
        root2 = (-b - sqrt(equation)) / (2 * a);
        printf("Two real roots: %lf and %lf\n", root1, root2);
    }  if (equation == 0) {
        root1 = -b / (2 * a);
        printf("Real root: %lf\n", root1);
    } else {
        printf("Not real \n");
    }

    return 0;
}
