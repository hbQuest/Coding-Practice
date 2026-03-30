#include <stdio.h>
#include <math.h>
#define MAX 100

void nhap(int a[][MAX], int& n) {
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
            scanf("%d", &a[i][j]);
        }
    }
}

void xuat(int a[][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%4d", a[i][j]);
        }
        printf("\n");
    }
}

void duyetCheoChinh(int a[][MAX], int n) {
    for (int i = 0; i < n; i++) {
        printf("%4d", a[i][i]);
    }
    printf("\n");
}

void duyetCheoPhu(int a[][MAX], int n) {
    for (int i = 0; i < n; i++) {
        printf("%4d", a[i][n-i-1]);
    }
    printf("\n");
}

void duyetTamGiacTrenCheoChinh(int a[][MAX], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = i; j < n-1; j++) {
            printf("%4d", a[i][j]);
        }
    }
    printf("\n");
}

void duyetTamGiacDuoiCheoChinh(int a[][MAX], int n) {
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= i-1; j++) {
            printf("%4d", a[i][j]);
        }
    }
    printf("\n");
}

void duyetTamGiacTrenCheoPhu(int a[][MAX], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            printf("%4d", a[i][j]);
        }
    }
    printf("\n");
}
 
void duyetTamGiacDuoiCheoPhu(int a[][MAX], int n) {
    for (int i = 1; i < n; i++) {
        for (int j = n-i; j < n; j++) {
            printf("%4d", a[i][j]);
        }
    }
    printf("\n");
}

int main() {
    int a[MAX][MAX], n;

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