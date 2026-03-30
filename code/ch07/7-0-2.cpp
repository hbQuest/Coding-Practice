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

void duyetCheoChinh(double a[][MAX], int n) {
    for (int i = 0; i < n; i++) {
        printf("%6.2lf", a[i][i]);
    }
    printf("\n");
}

void duyetCheoPhu(double a[][MAX], int n) {
    for (int i = 0; i < n; i++) {
        printf("%6.2lf", a[i][n-i-1]);
    }
    printf("\n");
}

void duyetTamGiacTrenCheoChinh(double a[][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            printf("%6.2lf", a[i][j]);
        }
    }
    printf("\n");
}

void duyetTamGiacDuoiCheoChinh(double a[][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%6.2lf", a[i][j]);
        }
    }
    printf("\n");
}

void duyetTamGiacTrenCheoPhu(double a[][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-i; j++) {
            printf("%6.2lf", a[i][j]);
        }
    }
    printf("\n");
}

void duyetTamGiacDuoiCheoPhu(double a[][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = n-i-1; j < n; j++) {
            printf("%6.2lf", a[i][j]);
        }
    }
    printf("\n");
}

int main() {
    double a[MAX][MAX];
    int n;

    nhap(a,n);
    xuat(a,n);

    printf("Duyet cac phan tu tren duong cheo chinh: ");
    duyetCheoChinh(a,n);
    printf("Duyet cac phan tu tren duong cheo phu: ");
    duyetCheoPhu(a,n);
    printf("Duyet cac phan tu thuoc tam giac tren duong cheo chinh: ");
    duyetTamGiacTrenCheoChinh(a,n);
    printf("Duyet cac phan tu thuoc tam giac duoi duong cheo chinh: ");
    duyetTamGiacDuoiCheoChinh(a,n);
    printf("Duyet cac phan tu thuoc tam giac tren duong cheo phu: ");
    duyetTamGiacTrenCheoPhu(a,n);
    printf("Duyet cac phan tu thuoc tam giac duoi duong cheo phu: ");
    duyetTamGiacDuoiCheoPhu(a,n);

    return 0;
}   