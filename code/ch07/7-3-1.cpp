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

int demCapGiaTriDoiXungQuaCheoChinh(int a[][MAX], int n) {
    int dem = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            printf("(%d,%d) ", a[i][j], a[j][i]);
            if (a[i][j] == a[j][i]) {
                dem++;
            }
        }
    }
    return dem;
}

int main() {
    int a[MAX][MAX];
    int n;

    nhap(a,n);
    xuat(a,n);
    
    int dem = demCapGiaTriDoiXungQuaCheoChinh(a,n);
    printf("\nSo cap gia tri doi xung qua duong cheo chinh la: %d", dem);    
    return 0;
}   