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

int phanTuLonNhat(int a[][MAX],int dong,int cot,int i,int j) {
    int max = a[i][0];
    for (int k = 0; k < cot; k++) {
        if (max < a[i][k]) {
            max = a[i][k];
        }
    }
    for (int t = 0; t < dong; t++) {
        if (max < a[t][j]) {
            max = a[t][j];
        }
    }
    return max;
}

void taoMatranBtheoYeuCau(int a[][MAX],int b[][MAX],int dong,int cot) {
    for (int i = 0; i < dong; i++) {
        for (int j = 0; j < cot; j++) {
            b[i][j] = phanTuLonNhat(a,dong,cot,i,j);
        }
    }
}

int main() {
    int a[MAX][MAX], b[MAX][MAX];
    int dong, cot;

    printf("Nhap ma tran A:\n");
    nhap(a,dong,cot);
    xuat(a,dong,cot);

    printf("Ma tran B voi cac phan tu la gia tri lon nhat cua cac dong va cac cot trong ma tran A:\n");
    taoMatranBtheoYeuCau(a,b,dong,cot);
    xuat(b,dong,cot);

    return 0;
}