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

void sapXepChanTangLeGiam(int a[][MAX],int dong,int cot) {
    int n = dong * cot;
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            int d1 = i/cot, c1 = i%cot, d2 = j/cot, c2 = j%cot;
            int n1 = a[d1][c1], n2 = a[d2][c2];
            if (n1%2 == 0 && n2%2 == 0) {
                if (n1 > n2) {
                    hoanVi(a[d1][c1], a[d2][c2]);
                }
            } else if (n1%2 != 0 && n2%2 != 0) {
                if (n1 < n2) {
                    hoanVi(a[d1][c1], a[d2][c2]);
                }
            }
            
        }
    }
}

int main() {
    int a[MAX][MAX];
    int dong, cot;
    printf("Nhap ma tran A:\n");
    nhap(a, dong, cot);
    printf("Xuat ma tran A:\n");
    xuat(a, dong, cot);
    
    printf("Ma tran sau sap xep so chan tang dan, so le giam:\n");
    sapXepChanTangLeGiam(a,dong,cot);
    xuat(a,dong,cot);

    return 0;
}