#include <stdio.h>
#include <conio.h>
#include <math.h>

void checkTamGiac(double a, double b, double c) {
    if (a + b <= c || a + c <= b || b + c <= a) {
        printf("Day khong phai la tam giac!");
        return;
    }
    if (a == b && a == c) {
        printf("Day la tam giac deu");
    } else if (a == b || a == c || b == c) {
        if (a*a + b*b == c*c || a*a + c*c == b*b || b*b + c*c == a*a) {
            printf("Day la tam giac vuong can");
        } else {
            printf("Day la tam giac can");
        }
    } else {
        if (a*a + b*b == c*c || a*a + c*c == b*b || b*b + c*c == a*a) {
            printf("Day la tam giac vuong");
        } else {
            printf("Day la tam giac thuong");
        }
    }
}


int main() {
    double a,b,c;
    printf("Nhap do dai canh a: ");
    scanf("%lf", &a);
    printf("Nhap do dai canh b: ");
    scanf("%lf", &b);
    printf("Nhap do dai canh c: ");
    scanf("%lf", &c);

    checkTamGiac(a,b,c);
    return 0;
}