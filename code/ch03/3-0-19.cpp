#include <stdio.h>
#include <math.h>

int main() {
    int a,b,c;
    printf("Nhap a (a khac 0): ");
    scanf("%d", &a);
    printf("Nhap b: ");
    scanf("%d", &b);
    printf("Nhap c: ");
    scanf("%d", &c);

    int delta = (b*b) - (4*a*c);

    if ( delta < 0) {
        printf("PT vo nghiem");
    } else if (delta == 0) {
        double x = (double)-b/(2*a);
        printf("PT co nghiem kep x1 = x2 = %.2lf", x);
    } else {
        printf("PT co 2 nghiem:\n");
        double x1 = ((double)-b + sqrt(delta)) / (2*a);
        double x2 = ((double)-b - sqrt(delta)) / (2*a);
        printf("x1 = %.2lf", x1);
        printf("\nx2 = %.2lf", x2);
    }

    return 0;
}