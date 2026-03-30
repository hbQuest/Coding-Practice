#include <stdio.h>
#define MAX 100

void nhap(double a[][MAX], int& dong, int& cot) {
    do {
        printf("Nhap so dong: ");
        scanf("%d", &dong);
        if (dong < 1 || dong > MAX) {
            printf("So dong khong hop le! Xin nhap lai!");
        }
    } while(dong < 1 || dong > MAX);
    
    do {
        printf("Nhap so cot: ");
        scanf("%d", &cot);
        if (cot < 1 || cot > MAX) {
            printf("So cot khong hop le! Xin nhap lai!");
        }
    } while(cot < 1 || cot > MAX);
    for (int i = 0; i < dong; i++) {
        for (int j = 0; j < cot; j++) {
            printf("Nhap a[%d][%d]: ", i, j);
            scanf("%lf", &a[i][j]);
        }
    }
}

void xuat(double a[][MAX], int dong, int cot) {
    for (int i = 0; i < dong; i++) {
        for (int j = 0; j < cot; j++) {
            printf("%.1lf  ", a[i][j]);
        }
        printf("\n");
    }
}

double soLanXuatHienCuaMin(double a[][MAX],int dong,int cot) {
    double min  = a[0][0];
    int dem = 0;
    for (int i = 0; i < dong; i++) {
        for (int j = 0; j < cot; j++) {
            if (min > a[i][j]) {
                min = a[i][j];
            }
        }
    }

    for (int i = 0; i < dong; i++) {
        for (int j = 0; j < cot; j++) {
            if (a[i][j] == min) {
                dem++;
            }
        }
    }
    
    return dem;
}

int main() {
    double a[MAX][MAX];
    int dong, cot;
    printf("Nhap ma tran A:\n");
    nhap(a, dong, cot);
    printf("Xuat ma tran A:\n");
    xuat(a, dong, cot);

    int dem = soLanXuatHienCuaMin(a,dong,cot);
    printf("So lan xuat hien cua phan tu nho nhat trong ma tran la %d", dem);

    return 0;
}