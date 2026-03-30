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

bool KiemTraMaTranLaMaPhuong(int a[][MAX], int n) {
    int tongCheoChinh = 0, tongCheoPhu = 0;
    // Tinh tong duong cheo chinh va phu
    for (int i = 0; i < n; i++) {
        tongCheoChinh += a[i][i];
        tongCheoPhu += a[i][n-i-1];
    }
    if (tongCheoChinh != tongCheoPhu) {
        return false;
    }
    // Tinh va so sanh tong dong va cot
    for (int i = 0; i < n; i++) {
        int tongDong = 0, tongCot = 0;
        for (int j = 0; j < n; j++) {
            tongDong += a[i][j];
            tongCot += a[j][i];
        }
        if (tongDong != tongCheoChinh || tongCot != tongCheoChinh) {
            return false;
        }
    }
    return true;
}

int main() {
    int a[MAX][MAX];
    int n;

    nhap(a,n);
    xuat(a,n);
    
    if (KiemTraMaTranLaMaPhuong(a,n)) {
        printf("Ma tran la ma phuong");
    } else {
        printf("Ma tran KHONG la ma phuong");
    }
    return 0;
}   