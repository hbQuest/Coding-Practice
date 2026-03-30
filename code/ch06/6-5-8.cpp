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


void xoayVongChieuKimDongHoCacBien(int a[][100],int dong,int cot) {
    if (dong <= 1 || cot <= 1) return;
    int temp = a[0][0];

    for (int i = 0; i < dong-1; i++) {
        a[i][0] = a[i+1][0];
    }
    for (int i = 0; i < cot-1; i++) {
        a[dong-1][i] = a[dong-1][i+1];
    }
    for (int i = dong-1; i > 0; i--) {
        a[i][cot-1] = a[i-1][cot-1];
    }
    for (int i = cot-1; i > 1; i--) {
        a[0][i] = a[0][i-1];
    }
    a[0][1] = temp;
}

int main() {
    int a[100][100];
    int dong, cot;
    printf("Nhap ma tran A:\n");
    nhap(a, dong, cot);
    printf("Xuat ma tran A:\n");
    xuat(a, dong, cot);
    
    xoayVongChieuKimDongHoCacBien(a,dong,cot);
    printf("Ma tran sau khi xoay vong theo chieu kim dong ho cac bien:\n");
    xuat(a, dong, cot);
    
    return 0;
}