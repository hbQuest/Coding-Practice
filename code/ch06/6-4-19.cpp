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

void demChuSo(int b[], int n) {
    n = abs(n);
    
    if (n == 0) {
        b[0]++;
        return;
    }
    while (n > 0) {
        int soDu = n%10;
        b[soDu]++;
        n /= 10;
    }
}

void timChuSoXuatHienNhieuNhat(int a[][MAX],int dong,int cot) {
    int b[10] = {0};

    for (int i = 0; i < dong; i++) {
        for (int j = 0; j < cot; j++) {
            demChuSo(b, a[i][j]);
        }
    }
    int soLanXuatHienMax = 0;
    for (int i = 0; i < 10; i++) {
        if (soLanXuatHienMax < b[i]) {
            soLanXuatHienMax = b[i];
        }
    }
    if (soLanXuatHienMax == 0) {
        printf("Khong co chu so nao");
        return;
    }

    printf("Chu so xuat hien nhieu nhat la: ");
    for (int i = 0; i < 10; i++) {
        if (soLanXuatHienMax == b[i]) {
            printf("%d ", i);
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

    timChuSoXuatHienNhieuNhat(a,dong,cot);

    return 0;
}