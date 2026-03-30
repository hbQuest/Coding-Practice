#include <stdio.h>
#include <conio.h>

double findMax(double a, double b, double c) {
    double max = a;
    if (max < b) {
        max = b;
    }
    if (max < c) {
        max = c;
    }
    return max;
}

int main() {
	double a,b,c;
    printf("Nhap so thuc a: ");
    scanf("%lf", &a);
    printf("Nhap so thuc b: ");
    scanf("%lf", &b);
    printf("Nhap so thuc c: ");
    scanf("%lf", &c);
    
    double max = findMax(a,b,c);
    printf("So thuc lon nhat trong 3 so la: %lf", max);
	return 0;
}