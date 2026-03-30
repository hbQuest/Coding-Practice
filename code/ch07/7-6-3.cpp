#include <stdio.h>
#include <math.h>
#define MAX 100

void nhapSoDongVaCot(int& dong,int& cot) {
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
}

void nhap(int a[][MAX], int dong, int cot) {
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

void tinhTich2MaTran(int a[][MAX], int b[][MAX], int c[][MAX], int dong, int cot) {
    for (int i = 0; i < dong; i++) {
        for (int j = 0; j < cot; j++) {
            c[i][j] = a[i][j] * b[i][j];
        }
    }
}

int main() {
    int a[MAX][MAX], b[MAX][MAX], c[MAX][MAX];
    int dong, cot;

    nhapSoDongVaCot(dong,cot);

    printf("Nhap ma tran a:\n");
    nhap(a,dong,cot);
    printf("Nhap ma tran b:\n");
    nhap(b,dong,cot);
    printf("Xuat ma tran a:\n");
    xuat(a,dong,cot);
    printf("Xuat ma tran b:\n");
    xuat(b,dong,cot);
    
    tinhTich2MaTran(a,b,c,dong,cot);
    printf("Tong 2 ma tran a va b la:\n");
    xuat(c,dong,cot);

    return 0;
}   