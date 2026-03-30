#include <stdio.h>
#define MAX 100

void nhap(double a[][MAX], int& dong, int& cot) {
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
            scanf("%lf", &a[i][j]);
        }
    }
}

void xuat(double a[][MAX], int dong, int cot) {
    for (int i = 0; i < dong; i++) {
        for (int j = 0; j < cot; j++) {
            printf("%.1lf  ", a[i][j]);
        }
        printf("\n");
    }
}

bool checkAConCuaB(double a[][MAX],double b[][MAX],int dongA,int cotA,int dongB,int cotB) {
    if (dongA > dongB || cotA > cotB) return false;

    for (int i = 0; i <= dongB - dongA; i++) {
        for (int j = 0; j <= cotB - cotA; j++) {
            bool check = true;

            for (int k = 0; k < dongA; k++) {
                for (int t = 0; t < cotA; t++) {
                    if (b[i+k][j+t] != a[k][t]) {
                        check = false;
                        break;
                    }
                }
                if (!check) break;
            }
            
            if (check) return true;
        }
    }
    return false;
}

int main() {
    double a[MAX][MAX], b[MAX][MAX];
    int dongA, dongB, cotA, cotB;
    printf("Nhap ma tran A:\n");
    nhap(a, dongA, cotA);
    printf("Nhap ma tran B:\n");
    nhap(b, dongB, cotB);
    printf("Xuat ma tran A:\n");
    xuat(a, dongA, cotA);
    printf("Xuat ma tran B:\n");
    xuat(b, dongB, cotB);

    if (checkAConCuaB(a,b,dongA,cotA,dongB,cotB)) {
        printf("Ma tran A la con cua ma tran B");
    } else {
        printf("Ma tran A khong la con cua ma tran B");
    }

    return 0;
}