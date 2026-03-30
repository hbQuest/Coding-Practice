#include <stdio.h>
#include <math.h>

void nhapMang(int a[], int &n) {
    do {
        printf("Nhap so phan tu n(1-100): ");
        scanf("%d", &n);
        if (n < 1 || n > 100) {
            printf("Xin nhap lai!");
        }
    } while (n < 1 || n > 100);
    for (int i = 0; i < n; i++) {
        printf("Nhap a[%d]: ", i);
        scanf("%d", &a[i]);
    }
}

void xuatMang(int a[], int n) {
    printf("Mang a: ");
    for (int i = 0; i < n; i++) {
        printf("%3d ", a[i]);
    }
    printf("\n");
}

int tongGiaTriAm(int a[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] < 0) {
            sum += a[i];
        }
    }
    return sum;
}

void hoanVi(int &a, int &b) {
    int temp = b;
    b = a;
    a = temp;
}

void sapXepTangDan(int a[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (a[i] > a[j]) {
                hoanVi(a[i], a[j]);
            }
        }
    }
}

int main() {

    int n;
    int a[100];
    nhapMang(a, n);
    xuatMang(a, n);
    int sum = tongGiaTriAm(a,n);
    printf("Tong cac gia tri am: %d\n", sum);
    printf("Sau khi sap xep tang dan\n");
    sapXepTangDan(a,n);
    xuatMang(a, n);

    return 0;
}