#include <stdio.h>
#define MAX 100

void input(double a[], int& n) {
    do {
        printf("Nhap so phan tu n: ");
        scanf("%d", &n);
        if (n <= 0 || n > MAX) {
            printf("Xin nhap lai!\n");
        }
    } while(n <= 0 || n > MAX);
    for (int i = 0; i < n; i++) {
        printf("Nhap a[%d]: ", i);
        scanf("%f", &a[i]);
    }
}

double findMax(double a[], int n) {
    double max = a[0];
    for (int i = 1; i < n; i++) {
        if (max < a[i]) {
            max = a[i];
        }
    }
    return max;
}

void display(double a[], int n) {
    printf("Mang: ");
    for (int i = 0; i < n; i++) {
        printf("%.2lf ", a[i]);
    }
    putchar('\n');
}


int main() {
    double mang[MAX];
    int n;

    input(mang, n);
    display(mang, n);

    double max = findMax(mang, n);

    printf("Phan tu lon nhat trong mang la: %.2lf ", max);

    return 0;
}