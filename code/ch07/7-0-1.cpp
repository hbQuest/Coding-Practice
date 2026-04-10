#include <stdio.h>
#include <math.h>

void nhap(int a[][100], int&n) {
    do {
        printf("Nhap so dong va cot: ");
        scanf("%d", &n);
        if (n < 1 || n > 100) {
            printf("So dong/cot khong hop le! Xin nhap lai!");
        }
    } while(n < 1 || n > 100);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Nhap a[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
}

void xuat(int a[][100], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d  ", a[i][j]);
        }
        printf("\n");
    }
}

void duyetCheoChinh(int a[][100], int n) {
    for (int i = 0; i < n; i++) {
        printf("%4d", a[i][i]);
    }
    printf("\n");
}

void duyetCheoPhu(int a[][100], int n) {
    for (int i = 0; i < n; i++) {
        printf("%4d", a[i][n-i-1]);
    }
    printf("\n");
}
//Duyệt tam giác TRÊN đường chéo chính (j > i)
void duyetTamGiacTrenCheoChinh(int a[][100], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            printf("%4d", a[i][j]);
        }
    }
    printf("\n");
}
//Duyệt tam giác DƯỚI đường chéo chính (j < i)
void duyetTamGiacDuoiCheoChinh(int a[][100], int n) {
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= i-1; j++) {
            printf("%4d", a[i][j]);
        }
    }
    printf("\n");
}
//Duyệt tam giác TRÊN đường chéo phụ (i + j < n - 1)
void duyetTamGiacTrenCheoPhu(int a[][100], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            printf("%4d", a[i][j]);
        }
    }
    printf("\n");
}
 //Duyệt tam giác DƯỚI đường chéo phụ (i + j > n - 1)
void duyetTamGiacDuoiCheoPhu(int a[][100], int n) {
    for (int i = 1; i < n; i++) {
        for (int j = n-i; j < n; j++) {
            printf("%4d", a[i][j]);
        }
    }
    printf("\n");
}

int main() {
    int a[100][100];
    int n;
    printf("Nhap ma tran A:\n");
    nhap(a, n);
    printf("Xuat ma tran A:\n");
    xuat(a, n);

    printf("Duyet cac phan tu tren duong cheo chinh: ");
    duyetCheoChinh(a,n);
    printf("Duyet cac phan tu tren duong cheo phu: ");
    duyetCheoPhu(a,n);
    printf("Duyet cac phan tu thuoc tam giac tren duong cheo chinh: ");
    duyetTamGiacTrenCheoChinh(a,n);
    printf("Duyet cac phan tu thuoc tam giac duoi duong cheo chinh: ");
    duyetTamGiacDuoiCheoChinh(a,n);
    printf("Duyet cac phan tu thuoc tam giac tren duong cheo phu: ");
    duyetTamGiacTrenCheoPhu(a,n);
    printf("Duyet cac phan tu thuoc tam giac duoi duong cheo phu: ");
    duyetTamGiacDuoiCheoPhu(a,n);

    return 0;
}   