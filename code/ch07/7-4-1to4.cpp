#include <stdio.h>
#include <math.h>

void nhap(int a[][100], int& n) {
    do {
        printf("Nhap n: ");
        scanf("%d", &n);
        if (n < 0 || n > 100) {
            printf("So n khong hop le! Xin nhap lai!");
        }
    } while (n < 0 || n > 100);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Nhap a[%d][%d]: ", i,j);
            scanf("%d", &a[i][j]);
        }
    }
}

void xuat(int a[][100], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%4d", a[i][j]);
        }
        printf("\n");
    }
}
// 7.4.1
bool KiemTraCheoChinhTangDan(int a[][100], int n) {
    for (int i = 0; i < n-1; i++) {
        if (a[i+1][i+1] < a[i][i]) {
            return false;
        }
    }
    return true;
}

// 7.4.2
bool KiemTraMaTranDoiXungQuaCheoChinh(int a[][100], int n) {
    for (int i = 0; i < n; i++) {
        for (int j =i+1; j < n; j++) {
            if (a[i][j] != a[j][i]) {
                return false;
            }
        }
    }
    return true;
}

// 7.4.3
bool KiemTraMaTranDoiXungQuaCheoPhu(int a[][100], int n) {
    if (n == 1) { return true; }
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (a[i][j] != a[n-j-1][n-i-1]) {
                return false;
            }
        }
    }
    return true;
}
// 7.4.4
bool KiemTraMaTranLaMaPhuong(int a[][100], int n) {
    if (n == 1) {return true;}
    int tongChuan = 0;
    int tongCheoChinh=0, tongCheoPhu=0;
    for (int i = 0; i < n; i++) {
        int tongDong = 0;
        int tongCot = 0;
        for (int j = 0 ;j < n; j++) {
            tongDong += a[i][j];
            tongCot += a[j][i];
        }
        if (i == 0) {
            if (tongDong != tongCot) {
                return false;
            }
            tongChuan = tongDong;
        } else if (tongChuan != tongDong || tongChuan != tongCot) {
            return false;
        }
        tongCheoChinh += a[i][i];
        tongCheoPhu += a[i][n-1-i];
    }
    if (tongChuan != tongCheoChinh || tongChuan != tongCheoPhu) {
        return false;
    }
    return true;
}
int main() {
    int a[100][100];
    int n;

    nhap(a,n);
    xuat(a,n);
    
    if (KiemTraMaTranDoiXungQuaCheoPhu(a,n)) {
        printf("Ma tran co doi xung qua duong cheo phu\n");
    } else {
        printf("Ma tran KHONG doi xung qua duong cheo phu\n");
    }

    if (KiemTraMaTranLaMaPhuong(a,n)) {
        printf("Ma tran la ma phuong\n");
    } else {
        printf("Ma tran KHONG la ma phuong\n");
    }
    return 0;
}   