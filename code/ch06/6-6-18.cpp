#include <stdio.h>
#include <math.h>
#define MAX 100

void nhap(int a[][MAX], int& dong, int& cot) {
    do {
        printf("Nhap so dong: ");
        scanf("%d", &dong);
        if (dong < 0 || dong > MAX) {
            printf("So dong khong hop le! Xin nhap lai!");
        }
    } while (dong < 0 || dong > MAX);

    do {
        printf("Nhap so cot: ");
        scanf("%d", &cot);
        if (cot < 0 || cot > MAX) {
            printf("So cot khong hop le! Xin nhap lai!");
        }
    } while (cot < 0 || cot > MAX);

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
            printf("%3d", a[i][j]);
        }
        printf("\n");
    }
}

void hoanVi(int& a, int& b) {
    a = a + b;
    b = a - b;
    a = a - b;
}

void sapXepMang1Chieu(int mangPhu[],int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (mangPhu[i] > mangPhu[j]) {
                hoanVi(mangPhu[i], mangPhu[j]);
            }
        }
    }
}

void sapXepTangDanTheoDangXoanOc(int a[][MAX],int dong,int cot) {
    int n = dong * cot;
    int mangPhu[n], index = 0;
    for (int i = 0; i < dong; i++) {
        for (int j = 0; j < cot; j++) {
            mangPhu[index++] = a[i][j];
        }
    }

    sapXepMang1Chieu(mangPhu,n);
    index = 0;
    int j = 0;
    for (int i = 0; i < dong; i++) {
        if (j < cot) {
            while (j < cot) {
                a[i][j] = mangPhu[index];
                index++;
                j++;
            }
        } else {
            j--;
            while (j < cot && j >= 0) {
                a[i][j] = mangPhu[index];
                index++;
                j--;        
            }
            j++;
        }
    }
}
int main() {
    int a[MAX][MAX];
    int dong, cot;

    printf("Nhap ma tran:\n");
    nhap(a,dong,cot);
    xuat(a,dong,cot);

    printf("Ma tran sau khi sap xep tang dan theo dang xoan oc:\n");
    sapXepTangDanTheoDangXoanOc(a,dong,cot);
    xuat(a,dong,cot);

    return 0;
}