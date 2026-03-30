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

double tongPhanTuTamGiacTren(double a[][MAX], int n) {
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            sum += a[i][j];
        }
    }
    return sum;
}

int main() {
    double a[MAX][MAX];
    int n;

    nhap(a,n);
    xuat(a,n);
    
    double sum = tongPhanTuTamGiacTren(a,n);
    printf("Tong cac phan tu thuoc ma tran tam giac tren nhung khong tinh duong cheo la: %.2lf", sum);
    
    return 0;
}   