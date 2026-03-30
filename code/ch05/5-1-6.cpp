#include <stdio.h>
#define MAX 100

void input(double a[], int& n) {
    do {
        printf("Nhap so phan tu n: ");
        scanf_s("%d", &n);
        if (n <= 0 || n > MAX) {
            printf("Xin nhap lai!");
        }
    } while (n <= 0 || n > MAX);
    for (int i = 0; i < n; i++) {
        printf("Nhap a[%d]: ", i);
        scanf_s("%lf", &a[i]);
    }
}

void display(double a[], int n) {
    printf("Mang a: ");
    for (int i = 0; i < n; i++) {
        printf("%3.2lf ", a[i]);
    }
}

void listNegativeIndex(double a[], int n) {
    printf("\nVi tri chua gia tri am trong mang la: ");
    for (int i = 0; i < n; i++) {
        if (a[i] < 0.0) {
            printf("%3d", i);
        }
    }
}

int main() {
    double mang[MAX];
    int n;

    input(mang, n);
    display(mang, n);
    listNegativeIndex(mang, n);
    return 0;
}