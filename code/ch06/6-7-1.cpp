#include <stdio.h>
#include <math.h>
#define MAX 100

void nhap(int a[][MAX], int& dong, int& cot) {
    do {
        printf("Nhap so dong: ");
        scanf("%d", &dong);
        if (dong < 0 || dong > MAX) {
            printf("So dong khong hop le! Xin nhap lai!");
        }
    } while (dong < 0 || dong > MAX);

    do {
        printf("Nhap so cot: ");
        scanf("%d", &cot);
        if (cot < 0 || cot > MAX) {
            printf("So cot khong hop le! Xin nhap lai!");
        }
    } while (cot < 0 || cot > MAX);

    for (int i = 0; i < dong; i++) {
        for (int j = 0; j < cot; j++) {
            printf("Nhap a[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
}

void xuat(int a[][MAX], int dong, int cot) {
    for (int i = 0; i < dong; i++) {
        for (int j = 0; j < cot; j++) {
            printf("%4d", a[i][j]);
        }
        printf("\n");
    }
}

void taoMatranBtheoYeuCau(int a[][MAX],int b[][MAX],int dong,int cot) {
    for (int i = 0; i < dong; i++) {
        for (int j = 0; j < cot; j++) {
            b[i][j] = abs(a[i][j]);
        }
    }
}

int main() {
    int a[MAX][MAX], b[MAX][MAX];
    int dong, cot;

    printf("Nhap ma tran A:\n");
    nhap(a,dong,cot);
    xuat(a,dong,cot);

    printf("Ma tran B voi cac phan tu la tri tuyet doi cua cac phan tu ma tran A:\n");
    taoMatranBtheoYeuCau(a,b,dong,cot);
    xuat(b,dong,cot);

    return 0;
}