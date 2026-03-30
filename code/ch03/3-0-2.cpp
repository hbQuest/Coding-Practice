#include <stdio.h>
#include <conio.h>

void cungDau(double a, double b) {
    if (a*b < 0.0) {
        printf("a va b khong cung dau");
    } else {
        printf("a va b cung dau");
    }
}

int main() {
	double a,b;
    printf("Nhap so thuc a: ");
    scanf("%lf", &a);
    printf("Nhap so thuc b: ");
    scanf("%lf", &b);

    cungDau(a,b);

	return 0;
}