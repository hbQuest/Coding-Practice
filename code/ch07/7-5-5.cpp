#include <stdio.h>
#include <math.h>
#define MAX 100

void nhap(int a[][MAX], int& n) {
    do {
        printf("Nhap n: ");
        scanf("%d", &n);
        if (n < 0 || n > MAX) {
            printf("So n khong hop le! Xin nhap lai!");
        }
    } while (n < 0 || n > MAX);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Nhap a[%d][%d]: ", i,j);
            scanf("%d", &a[i][j]);
        }
    }
}

void xuat(int a[][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
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

void sapXepTangDanTheoTongDong(int a[][MAX], int n) {
    int b[MAX] = {0};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            b[i] += a[i][j];
        }
    }
    
    // sap xep mang 1 chieu b voi phan tu la tong cac dong
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (b[i] > b[j]) {
                hoanVi(b[i], b[j]);
                for (int k = 0; k < n; k++) {
                    hoanVi(a[i][k], a[j][k]);
                }
            }
        }
    }
}

int main() {
    int a[MAX][MAX];
    int n;

    nhap(a,n);
    xuat(a,n);
    
    printf("Ma tran sau khi sap xep theo tong tung dong tang dan:\n");
    sapXepTangDanTheoTongDong(a,n);
    xuat(a,n);
    return 0;
}   