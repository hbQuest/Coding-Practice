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

double timSoXuatHienNhieuNhat(double a[][MAX],int dong,int cot) {
    int demMax = 1;
    double num = a[0][0];
    for (int i = 0; i < dong; i++) {
        for (int j = 0; j < cot; j++) {
            int dem = 0;
            double temp = a[i][j];
            for (int k = 0; k < dong; k++) {
                for (int t = 0; t < cot; t++) {
                    if (num == a[k][t]) {
                        dem++;
                    }
                }
            }
            if (dem > demMax) {
                demMax = dem;
                num = temp;
            }
        }
    }
    return num;
}

int main() {
    double a[MAX][MAX];
    int dong, cot;
    printf("Nhap ma tran A:\n");
    nhap(a, dong, cot);
    printf("Xuat ma tran A:\n");
    xuat(a, dong, cot);

    double n = timSoXuatHienNhieuNhat(a,dong,cot);
    printf("So xuat hien nhieu nhat trong ma tran la %.2lf", n);

    return 0;
}