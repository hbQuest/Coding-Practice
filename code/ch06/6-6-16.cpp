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
            printf("%3d", a[i][j]);
        }
        printf("\n");
    }
}

void hoanVi(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void sapXepDongDuaVaoTong1Dong(int a[][MAX],int dong,int cot) {
    int tong1Dong[dong], sum;
    for (int i = 0; i < dong; i++) {
        sum = 0;
        for (int j = 0; j < cot; j++) {
            sum += a[i][j];
        }
        tong1Dong[i] = sum;
    }

    for (int i = 0; i < dong-1; i++) {
        for (int j = i+1; j < dong; j++) {
            if (tong1Dong[i] > tong1Dong[j]) {
                for (int k = 0; k < cot; k++) {
                    hoanVi(a[i][k], a[j][k]);
                    hoanVi(tong1Dong[i], tong1Dong[j]);
                }
            }
        }
    }
}
int main() {
    int a[MAX][MAX];
    int dong, cot;

    printf("Nhap ma tran:\n");
    nhap(a,dong,cot);
    xuat(a,dong,cot);

    printf("Ma tran sau khi sap xep theo tong phan tu trong 1 dong:\n");
    sapXepDongDuaVaoTong1Dong(a,dong,cot);
    xuat(a,dong,cot);

    return 0;
}