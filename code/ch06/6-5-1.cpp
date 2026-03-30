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

void hoanVi(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void hoanVi2Dong(int a[][100],int cot,int dong1,int dong2) {
    for (int i = 0; i < cot; i++) {
        hoanVi(a[dong1][i], a[dong2][i]);
    }
}

//6.5.2
void HoanVi2Cot(int a[][100],int dong, int c1, int c2) {
    for (int i = 0; i < dong; i++) {
        hoanVi(a[i][c1], a[i][c2]);
    }
}
 
int main() {
    int a[100][100];
    int dong, cot;
    printf("Nhap ma tran A:\n");
    nhap(a, dong, cot);
    printf("Xuat ma tran A:\n");
    xuat(a, dong, cot);

    int dong1, dong2;
    do {
        printf("Nhap dong 1: ");
        scanf("%d", &dong1);
        if (dong1 < 0 || dong1 >= dong) {
            printf("Dong khong hop le! Xin nhap lai!");
        }
    } while (dong1 < 0 || dong1 >= dong);
    do {
        printf("Nhap dong 2: ");
        scanf("%d", &dong2);
        if (dong2 < 0 || dong2 >= dong) {
            printf("Dong khong hop le! Xin nhap lai!");
        }
    } while (dong2 < 0 || dong2 >= dong);
    
    hoanVi2Dong(a, cot,dong1,dong2);
    xuat(a,dong,cot);
    
    int c1,c2;
    do {
        printf("Nhap cot 1: ");
        scanf("%d", &c1);
        if (c1 < 0 || c1 >= cot) {
            printf("Cot khong hop le! Xin nhap lai!");
        }
    } while (c1 < 0 || c1 >= cot);
    do {
        printf("Nhap cot 2: ");
        scanf("%d", &c2);
        if (c2 < 0 || c2 >= cot) {
            printf("Cot khong hop le! Xin nhap lai!");
        }
    } while (c2 < 0 || c2 >= cot);
    HoanVi2Cot(a,dong,c1,c2);
    xuat(a,dong,cot);

    return 0;
}