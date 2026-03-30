#include <stdio.h>
#include <limits.h>
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

double timSoAmDau(double a[][MAX],int dong,int cot) {
    for (int i = 0; i < dong; i++) {
        for (int j = 0; j < cot; j++) {
            if (a[i][j] < 0) {
                return a[i][j];
            }
        }
    }
    return 0;
}

double timMaxAm(double a[][MAX],int dong,int cot) {
    // Dung thu vien <limits.h>
    // double max = INT_MIN;
    // for (int  i = 0; i < dong; i++) {
    //     for (int j = 0; j < cot; j++) {
    //         if (a[i][j] < 0 && a[i][j] > max) {
    //             max = a[i][j];
    //         }
    //     }
    // }
    // if (max == INT_MIN) return 0;
    // return max;    

    // Khong dung <limits.h>
    // Tim so am dau tien
    double maxAm = timSoAmDau(a,dong,cot);
    for (int i = 0; i < dong; i++) {
        for (int j = 0; j < cot; j++) {
            if (a[i][j] < 0 && a[i][j] > maxAm) {
                maxAm = a[i][j];
            }
        }
    }
    return maxAm;
}

int main() {
    double a[MAX][MAX];
    int dong, cot;
    printf("Nhap ma tran A:\n");
    nhap(a, dong, cot);
    printf("Xuat ma tran A:\n");
    xuat(a, dong, cot);

    double n = timMaxAm(a,dong,cot);
    if (n != 0) {
        printf("So am lon nhat trong ma tran la %.2lf", n);
    } else {
        printf("Khong co so am trong ma tran");
    }

    return 0;
}