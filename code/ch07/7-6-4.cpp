#include <stdio.h>
#include <math.h>
#define MAX 100

void nhap(int a[][MAX], int& dong, int& cot) {
    do {
        printf("Nhap so dong: ");
        scanf("%d", &dong);
        if (dong < 1 || dong > MAX) {
            printf("Khong hop le! Xin nhap lai!");
        }
    } while (dong < 1 || dong > MAX);
    
    do {
        printf("Nhap so cot: ");
        scanf("%d", &cot);
        if (cot < 1 || cot > MAX) {
            printf("Khong hop le! Xin nhap lai!");
        }
    } while (cot < 1 || cot > MAX);

    for (int i = 0; i < dong; i++) {
        for (int j = 0; j < cot; j++) {
            printf("Nhap a[%d][%d]: ", i,j);
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

void maTranNghichDao(int a[][MAX], int b[][MAX], int dong, int cot) {

    for (int i = dong-1; i >= 0; i--) {
        for (int j = cot-1; j >= 0; j--) {
            b[dong-i-1][cot-j-1] = a[i][j];
        }
    }
}

int main() {
    int a[MAX][MAX], b[MAX][MAX];
    int dong, cot;

    printf("Nhap ma tran a:\n");
    nhap(a,dong,cot);
    printf("Xuat ma tran a:\n");
    xuat(a,dong,cot);

    printf("Ma tran nghich dao cua ma tran a la:\n");
    maTranNghichDao(a,b,dong,cot);
    xuat(b,dong,cot);

    return 0;
}     