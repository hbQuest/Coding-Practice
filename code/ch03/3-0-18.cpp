#include <stdio.h>
#include <math.h>

int main() {
    double a,b,c;
    printf("Nhap a: ");
    scanf("%lf", &a);
    printf("Nhap b: ");
    scanf("%lf", &b);
    printf("Nhap c: ");
    scanf("%lf", &c);

    printf("Sap xep theo thu tu tang dan: ");

    if (a > b) {
        if (b > c) {
            printf("%.2lf ", c);
            printf("%.2lf ", b);
            printf("%.2lf ", a);
        } else {
            if (a > c) {
                printf("%.2lf ", b);
                printf("%.2lf ", c);
                printf("%.2lf ", a);
            } else {
                printf("%.2lf ", b);
                printf("%.2lf ", a);
                printf("%.2lf ", c);
            }
        }
    } else {
        if (b > c) {
            if (c > a) {
                printf("%.2lf ", a);
                printf("%.2lf ", c);
                printf("%.2lf ", b);
            } else {
                printf("%.2lf ", c);
                printf("%.2lf ", a);
                printf("%.2lf ", b);
            }
        } else {
            printf("%.2lf ", a);
            printf("%.2lf ", b);
            printf("%.2lf ", c);
        }
    }
    
    return 0;
}