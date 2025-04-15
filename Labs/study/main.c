#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main() {
    double a;
    double b;
    double c;
    double equation;
    double root1;
    double root2;
    printf("enter your coffiecnt of a, b ,c ");
    scanf("%lf",&a);
    scanf("%lf",&b);
    scanf("%lf",&c);
    equation =(b * b)-( 4 * a * c);
    if (equation >0){
        root1 =(-b -sqrt(equation))/(2*a);
        root1 =(-b +sqrt(equation))/(2*a);
        printf("Two real roots: %lf and %lf \n", root1, root2);
    }
    if (equation ==0){
        root1 =(-b) /(2*a);
        printf("the root is %lf \n",root1);
    }
    if (equation<0){
        printf("the root is imagenry number \n");
    }



    return 0;
}

/*int main() {
    double a, b, c, equation, root1, root2;
    printf("Enter the coefficients a, b,c: ");
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    equation = b * b - 4 * a * c;
    if (equation > 0) {
        root1 = (-b + sqrt(equation)) / (2 * a);
        root2 = (-b - sqrt(equation)) / (2 * a);
        printf("Two real roots: %d and %d\n", root1, root2);
    }  if (equation == 0) {
        root1 = -b / (2 * a);
        printf("Real root: %d\n", root1);
    } else {
        printf("Not real \n");
    }

    return 0;
}
*/
/*#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c, equation, root1, root2;

    printf("Enter the coefficients a, b, c: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    equation = (b * b) - (4 * a * c);

    if (equation > 0) {
        root1 = (-b + sqrt(equation)) / (2 * a);
        root2 = (-b - sqrt(equation)) / (2 * a);
        printf("Two real roots: %.2lf and %.2lf\n", root1, root2);
    } else if (equation == 0) {
        root1 = -b / (2 * a);
        printf("One real root: %.2lf\n", root1);
    } else {
        printf("No real roots (imaginary roots)\n");
    }

    return 0;
}*/
