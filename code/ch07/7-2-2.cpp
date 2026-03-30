#include <stdio.h>
#include <math.h>
#define MAX 100

void nhap(double a[][MAX], int& n) {
    do {
        printf("Nhap n: ");
        scanf("%d", &n);
        if (n < 0 || n > MAX) {
            printf("So n khong hop le! Xin nhap lai!");
        }
    } while (n < 0 || n > MAX);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Nhap a[%d][%d]: ", i,j);
            scanf("%lf", &a[i][j]);
        }
    }
}

void xuat(double a[][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%6.2lf", a[i][j]);
        }
        printf("\n");
    }
}

void hoanVi(double& a, double& b) {
    a = a + b;
    b = a - b;
    a = a - b;
}

double timMinTamGiacDuoi(double a[][MAX], int n) {
    double min = a[0][0];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (min > a[i][j]) {
                min = a[i][j];
            }
        }
    }
    return min;
}

int main() {
    double a[MAX][MAX];
    int n;

    nhap(a,n);
    xuat(a,n);
    
    double min = timMinTamGiacDuoi(a,n);
    printf("Min trong ma tran tam giac duoi la: %.2lf", min);
    
    return 0;
}   