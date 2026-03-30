#include <stdio.h>
#include <math.h>
#define MAX 100

void nhap(int a[][MAX], int& n) {
    do {
        printf("Nhap n (n>=3): ");
        scanf("%d", &n);
        if (n < 3 || n > MAX) {
            printf("So n khong hop le! Xin nhap lai!");
        }
    } while (n < 3 || n > MAX);

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

void sapXepTamGiacTrenTangDan(int a[][MAX], int n) {
    int b[MAX] = {0}, index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            b[index++] += a[i][j];
        }
    }

    for (int i = 0; i < index-1; i++) {
        for (int j = i+1; j < index; j++) {
            if (b[i] > b[j]) {
                hoanVi(b[i], b[j]);
            }
        }
    }
    
    index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            a[i][j] = b[index++];
        }
    }
}

int main() {
    int a[MAX][MAX];
    int n;

    nhap(a,n);
    xuat(a,n);
    
    printf("Ma tran sau khi sap xep tam giac tren tang dan tu tren xuong duoi tu trai sang phai:\n");
    sapXepTamGiacTrenTangDan(a,n);
    xuat(a,n);
    return 0;
}   