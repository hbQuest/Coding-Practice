#include <stdio.h>
#include <conio.h>
#include <math.h>

int main() {
    float a,b,c;
    printf("Nhap so thuc a: ");
    scanf("%f", &a);
    printf("Nhap so thuc b: ");
    scanf("%f", &b);
    printf("Nhap so thuc c: ");
    scanf("%f", &c);

    if (a < 0) {
        a = abs(a);
    }
    if (b < 0) {
        b = abs(b);
    } 
    if (c < 0) {
        c = abs(c);
    }

    printf("So thuc a, b, c sau check lan luot la: %f, %f, %f", a,b,c);
    return 0;
}