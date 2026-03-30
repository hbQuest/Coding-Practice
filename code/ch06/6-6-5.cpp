#include <stdio.h>
#include <math.h>
#define MAX 100

void nhap(int a[][MAX], int& dong, int& cot) {
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

void hoanVi(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void xuatGiaTriChanGiamDan(int a[][MAX],int dong,int cot) {
    int b[MAX] = {0};
    int dem = 0;
    for (int i = 0; i < dong; i++) {
        for (int j = 0; j < cot; j++) {
            if (a[i][j]%2 == 0) {
                b[dem] = a[i][j];
                dem++;
            }
        }
    }

    for (int i = 0; i < dem-1; i++) {
        for (int j = i+1; j < dem; j++) {
            if (b[i] < b[j]) {
                hoanVi(b[i], b[j]);
            }
        }
        printf("%4d", b[i]);
    }
    printf("%4d", b[dem-1]);
}

int main() {
    int a[MAX][MAX];
    int dong, cot;
    printf("Nhap ma tran A:\n");
    nhap(a, dong, cot);
    printf("Xuat ma tran A:\n");
    xuat(a, dong, cot);
    
    printf("Cac gia tri chan theo thu tu giam dan:\n");
    xuatGiaTriChanGiamDan(a,dong,cot);
    
    return 0;
}