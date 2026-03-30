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

void sapXepTangDanKhongDungMangPhu(int a[][MAX],int dong,int cot) {
    int n = dong * cot;
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (a[i/cot][i%cot] > a[j/cot][j%cot]) {
                hoanVi(a[i/cot][i%cot], a[j/cot][j%cot]);
            }
        }
    }
}

void sapXepTangDanCoDungMangPhu(int a[][MAX],int dong,int cot) {
    int mangPhu[MAX] = {0}, index=0;
    for (int i = 0; i < dong; i++) {
        for (int j = 0; j < cot; j++) {
            mangPhu[index++] = a[i][j];
        }
    }

    for (int i = 0; i < index-1; i++) {
        for (int j = i+1; j < index; j++) {
            if (mangPhu[i] > mangPhu[j]) {
                hoanVi(mangPhu[i], mangPhu[j]);
            }
        }
    }
    index = 0;
    for (int i = 0; i < dong; i++) {
        for (int j = 0; j < cot; j++) {
            a[i][j] = mangPhu[index++];
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
    
    // printf("Ma tran sau sap xep tang dan KHONG su dung mang phu:\n");
    // sapXepTangDanKhongDungMangPhu(a,dong,cot);
    // xuat(a,dong,cot);
    printf("Ma tran sau sap xep tang dan CO su dung mang phu:\n");
    sapXepTangDanCoDungMangPhu(a,dong,cot);
    xuat(a,dong,cot);
    return 0;
}