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
            printf("%d  ", a[i][j]);
        }
        printf("\n");
    }
}

void lietKeCotNhieuChuSoNhat(int a[][MAX],int dong,int cot) {
    int dem[MAX] = {0};

    for (int i = 0; i < cot; i++) {
        for (int j = 0; j < dong; j++) {
            int n = abs(a[j][i]);
            if (n == 0) {
                dem[i]++;
            }
            while (n > 0) {
                dem[i]++;
                n /= 10;
            }
        }
    }
    int soChuSoMax = dem[0], c = 0;
    for (int i = 0; i < cot; i++) {
         if (dem[i] > soChuSoMax) {
            soChuSoMax = dem[i];
            cot = i;
        }
    }
    printf("Cot %d co nhieu chu so nhat voi %d chu so", c, soChuSoMax);

}

int main() {
    int a[MAX][MAX];
    int dong, cot;
    printf("Nhap ma tran A:\n");
    nhap(a, dong, cot);
    printf("Xuat ma tran A:\n");
    xuat(a, dong, cot);

    lietKeCotNhieuChuSoNhat(a,dong,cot);
    return 0;
}