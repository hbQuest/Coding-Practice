#include <stdio.h>
#include <math.h>

void nhap(int a[][100], int& dong, int& cot) {
    do {
        printf("Nhap so dong: ");
        scanf("%d", &dong);
        if (dong < 1 || dong > 100) {
            printf("So dong khong hop le! Xin nhap lai!");
        }
    } while(dong < 1 || dong > 100);
    do {
        printf("Nhap so cot: ");
        scanf("%d", &cot);
        if (cot < 1 || cot > 100) {
            printf("So cot khong hop le! Xin nhap lai!");
        }
    } while(cot < 1 || cot > 100);
    for (int i = 0; i < dong; i++) {
        for (int j = 0; j < cot; j++) {
            printf("Nhap a[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
}

void xuat(int a[][100], int dong, int cot) {
    for (int i = 0; i < dong; i++) {
        for (int j = 0; j < cot; j++) {
            printf("%d  ", a[i][j]);
        }
        printf("\n");
    }
}

// 6.1.8
int tinhTongBien(int a[][100],int dong,int cot) {

    int s = 0;
    for (int i = 0; i < cot; i++) {
        s += a[0][i];
        if (dong > 1) {
            s += a[dong-1][i];
        }
    }
    for (int i = 1; i < dong - 1; i++) {
        s += a[i][0];
        if (cot > 1) {
            s += a[i][cot-1];
        }
    }
    return s;
}

// 6.1.9
double TinhTrungNhanSoDuong(int a[][100], int dong, int cot) {
    int n = dong*cot;
    int tich = 1, dem = 0;
    for (int i = 0; i < n; i++) {
        if (a[i/cot][i%cot] > 0) {
            tich *= a[i/cot][i%cot];
            dem++;
        }
    }
    if (dem == 0) return 0;
    return pow(tich, 1.0/dem);
}

// 6.1.10
void ThayAmBangTriTuyetDoi(int a[][100], int dong, int cot) {
    for (int i = 0; i < dong; i++) {
        for (int j = 0; j < cot; j++) {
            if (a[i][j] < 0) {
                a[i][j] = abs(a[i][j]);
            }
        }
    }
}


int main() {
    int a[100][100];
    int dong, cot;
    nhap(a, dong, cot);
    xuat(a, dong, cot);

    int s = tinhTongBien(a, dong, cot);
    printf("Tong cac gia tri nam tren bien la: %d\n", s);
    
    double r = TinhTrungNhanSoDuong(a,dong,cot);
    printf("Trung binh nhan cac so duong la: %.2lf\n", r);

    ThayAmBangTriTuyetDoi(a,dong,cot);
    xuat(a,dong,cot);
    return 0;
}