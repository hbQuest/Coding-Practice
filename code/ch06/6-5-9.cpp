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


void xoa1Dong(int a[][100],int& dong,int cot, int d) {
    if (d - 1 < dong) {
        for (int i = d; i < dong-1; i++) {
            for (int j = 0; j < cot; j++) {
                a[i][j] = a[i+1][j];
            }
        }
    }
    dong--;
}

// 6.5.10
void Xoa1Cot(int a[][100], int dong, int &cot, int c) {
    if (c-1 < cot) {
        for (int j = c; j < cot - 1; j++) {
            for (int i = 0; i < dong; i++) {
                a[i][j] = a[i][j+1];
            }
        }
    }
    cot--;
}

int main() {
    int a[100][100];
    int dong, cot, d;
    printf("Nhap ma tran A:\n");
    nhap(a, dong, cot);
    printf("Xuat ma tran A:\n");
    xuat(a, dong, cot);
    
    do {
        printf("Nhap dong muon xoa: ");
        scanf("%d", &d);
        if (d < 0 || d >= dong) {
            printf("Dong khong hop le! Xin nhap lai!");
        }
    } while (d < 0 || d >= dong);

    xoa1Dong(a,dong,cot,d);
    printf("Ma tran sau khi xoa dong %d:\n", d);
    xuat(a, dong, cot);
    
    int c;
    do {
        printf("Nhap cot muon xoa: ");
        scanf("%d", &c);
        if (c < 0 || c >= cot) {
            printf("Cot khong hop le! Xin nhap lai!");
        }
    } while (c < 0 || c >= cot);

    Xoa1Cot(a,dong,cot,c);
    printf("Ma tran sau khi xoa cot %d:\n", c);
    xuat(a, dong, cot);
    return 0;
}