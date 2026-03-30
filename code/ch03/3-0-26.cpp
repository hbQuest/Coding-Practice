#include <stdio.h>
#include <math.h>

double sqrtN(int x, int n) {
    if (n%2 != 0) {
        if (x >= 0) {
            return pow(x, 1.0/n);
        } else {
            return -pow(-x, 1.0/n);
        }
    } else {
        return pow(x, 1.0/n);
    }
}

int main() {
    int n, x;

    do {
        printf("Nhap can bac n(>0) = ");
        scanf("%d", &n);
        if (n <= 0) {
            printf("Khong hop le! Xin nhap lai!\n");
        }
    } while (n <= 0);
    
    do {
        printf("Nhap so x = ");
        scanf("%d", &x);
        if (n%2 == 0 && x < 0) {
            printf("Khong hop le! Xin nhap lai!\n");
        }
    } while (n%2 == 0 && x < 0);
    
    double result = sqrtN(x, n);

    printf("Ket qua can bac %d cua %d la %.2lf", n, x, result);

    return 0;
}