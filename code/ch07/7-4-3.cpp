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

bool KiemTraMaTranDoiXungQuaCheoPhu(int a[][MAX], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (a[i][j] != a[n-j-1][n-i-1]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int a[MAX][MAX];
    int n;

    nhap(a,n);
    xuat(a,n);
    
    if (KiemTraMaTranDoiXungQuaCheoPhu(a,n)) {
        printf("Ma tran co doi xung qua duong cheo phu");
    } else {
        printf("Ma tran KHONG doi xung qua duong cheo phu");
    }
    return 0;
}   