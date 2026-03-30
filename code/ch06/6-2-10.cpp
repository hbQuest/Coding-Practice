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

bool checkCucTri(double a[][MAX], int soDong, int soCot, int dong, int cot) {
    bool cucTieu = true, cucDai = true;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (dong+i >= 0 && dong+i < soDong && cot+j >= 0 && cot+j < soCot && !(i==0&&j==0)) {
                if (a[dong][cot] <= a[dong+i][cot+j]) {
                    cucDai = false;
                }
                if (a[dong][cot] >= a[dong+i][cot+j]) {
                    cucTieu = false;
                }
                if (!cucDai && !cucTieu) return false;
            }
        }
    }
    
    return true;
}

int demCucDaiVaCucTieu(double a[][MAX],int dong,int cot) {
    int dem = 0;
    for (int i = 0; i < dong; i++) {
        for (int j = 0; j < cot; j++) {
            if (checkCucTri(a,dong,cot,i,j)) {
                dem++;
            }
        }
    }

    return dem;
}

int main() {
    double a[MAX][MAX];
    int dong, cot;
    nhap(a, dong, cot);
    xuat(a, dong, cot);

    int dem = demCucDaiVaCucTieu(a,dong,cot);
    if (dem != 0) {
        printf("So luong phan tu cuc tri la: %d", dem);
    } else {
        printf("Khong co phan tu cuc tri trong ma tran");
    }

    return 0;
}