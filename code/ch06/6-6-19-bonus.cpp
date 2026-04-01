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
            printf("%4d", a[i][j]);
        }
        printf("\n");
    }
}

void hoanVi(int& a, int& b) {
    a = a + b;
    b = a - b;
    a = a - b;
}

void xuatGiaTriAmGiamDan(int a[][MAX],int dong,int cot) {
    int n = dong * cot;
    int d1,d2,c1,c2;
    
    for (int i = 0; i < n-1; i++) {
        d1 = i/cot;
        c1 = i%cot;
        for (int j = i+1; j < n; j++) {
            d2 = j/cot;
            c2 = j%cot;
            if (a[d1][c1] < 0 && (a[d1][c1] < a[d2][c2])) {
                hoanVi(a[d1][c1], a[d2][c2]);
            }
        }
    }
    
    for (int i = 0; i < n-1; i++) {
        d1 = i/cot;
        c1 = i%cot;
        for (int j = i+1; j < n; j++) {
            d2 = j/cot;
            c2 = j%cot;
            if (a[d1][c1] > a[d2][c2] && (a[d2][c2] >= 0)) {
                hoanVi(a[d1][c1], a[d2][c2]);
            }
        }
    }
}

int main() {
    int a[MAX][MAX];
    int dong, cot;

    printf("Nhap ma tran:\n");
    nhap(a,dong,cot);
    xuat(a,dong,cot);

    // Thêm yêu cầu sắp xếp số dương tăng dần rồi đến số âm giảm dần theo thứ tự (khác với giữ nguyên vị trí các số trong ma trận) => ta sắp số âm trước thì nó sẽ tự động dồn về sau, sau đó xếp số dương hoặc ngươc lại nhưng điều kiện xét sẽ khác
    printf("Xuat cac gia tri am giam dan duong tang dan:\n");
    xuatGiaTriAmGiamDan(a,dong,cot);
    xuat(a,dong,cot);

    return 0;
}