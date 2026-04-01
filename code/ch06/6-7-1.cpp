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

// 6.7.1
void taoMatranBtheoYeuCau1(int a[][100],int b[][100],int dong,int cot) {
    for (int i = 0; i < dong; i++) {
        for (int j = 0; j < cot; j++) {
            b[i][j] = abs(a[i][j]);
        }
    }
}

// 6.7.2
void taoMatranBtheoYeuCau2(int a[][100],int b[][100],int dong,int cot) {
    int maxDong[dong], maxCot[cot];
    // tìm max dòng
    for (int i = 0; i < dong; i++) {
        maxDong[i] = a[i][0];
        for (int j = 1; j < cot; j++) {
            if (a[i][j] > maxDong[i]) {
                maxDong[i] = a[i][j];
            }
        }
    }
    // tìm max cột
    for (int j = 0; j < cot; j++) {
        maxCot[j] = a[0][j];
        for (int i = 1; i < dong; i++) {
            if (a[i][j] > maxCot[j]) {
                maxCot[j] = a[i][j];
            }
        }
    }
    // gán max dòng, cột vào mảng b
    for (int i = 0; i < dong; i++) {
        for (int j = 0; j < cot; j++) {
            if (maxCot[j] >= maxDong[i]) {
                b[i][j] = maxCot[j];
            } else {
                b[i][j] = maxDong[i];
            }
        }
    }
}

// 6.7.3
int SoLuongPhanTuDuongXungQuanh(int a[][100], int dong, int cot, int d, int c) {
    int dem = 0;
    int x[8] = {-1,-1,-1,0,0,1,1,1};
    int y[8] = {-1,0,1,-1,1,-1,0,1};
    for (int i = 0; i < 8; i++) {
        if (d+x[i] < dong && d+x[i] >= 0 && c+y[i] < cot && c+y[i] >= 0) {
            if (a[d+x[i]][c+y[i]] > 0) {
                dem++;
            }
        }
    }
    return dem;
}

void taoMatranBtheoYeuCau3(int a[][100],int b[][100],int dong,int cot) {
    for (int i = 0; i < dong; i++) {
        for (int j = 0; j < cot; j++) {
            b[i][j] = SoLuongPhanTuDuongXungQuanh(a,dong,cot,i,j);
        }
    }
}

int main() {
    int a[100][100], b[100][100];
    int dong, cot;

    printf("Nhap ma tran A:\n");
    nhap(a,dong,cot);
    xuat(a,dong,cot);

    // printf("Ma tran B voi cac phan tu la tri tuyet doi cua cac phan tu ma tran A:\n");
    // taoMatranBtheoYeuCau1(a,b,dong,cot);
    // xuat(b,dong,cot);

    // printf("Ma tran B voi cac phan tu la max dong i, cot j cua ma tran A:\n");
    // taoMatranBtheoYeuCau2(a,b,dong,cot);
    // xuat(b,dong,cot);

    printf("Ma tran B voi cac phan tu la so luong phan tu duong xung quanh cua ma tran A:\n");
    taoMatranBtheoYeuCau3(a,b,dong,cot);
    xuat(b,dong,cot);

    return 0;
}