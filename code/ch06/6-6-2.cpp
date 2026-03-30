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

void sapXepTangDanTungDong(int a[][MAX],int dong,int cot,int d) {
    for (int j = 0; j < cot-1; j++) {
        for (int k = j+1; k < cot; k++) {
            if (a[d][j] < a[d][k]) {
                hoanVi(a[d][j], a[d][k]);
            }
        }
    }
}


int main() {
    int a[MAX][MAX];
    int dong, cot, d;
    printf("Nhap ma tran A:\n");
    nhap(a, dong, cot);
    printf("Xuat ma tran A:\n");
    xuat(a, dong, cot);
    
    do {
        printf("Nhap dong muon sao xep: ");
        scanf("%d", &d);
        if (d < 0 || d > dong) {
            printf("Dong khong hop le! Xin nhap lai!");
        }
    } while (d < 0 || d > dong);

    printf("Ma tran sau khi sap xep tang dan tung dong:\n");
    sapXepTangDanTungDong(a,dong,cot, d);
    xuat(a, dong, cot);
    
    return 0;
}