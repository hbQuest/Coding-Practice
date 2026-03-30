#include <stdio.h>

void input(int a[], int &n) {
    do {
        printf("Nhap so phan tu n: ");
        scanf("%d", &n);
        if (n <= 0 || n > 100) {
            printf("Xin nhap lai!");
        }
    } while (n <= 0 || n > 100);
    for (int i = 0; i < n; i++) {
        printf("Nhap a[%d]: ", i);
        scanf("%d", &a[i]);
    }
}

void display(int a[], int n) {
    printf("Mang a: ");
    for (int i = 0; i < n; i++) {
        printf("%3d ", a[i]);
    }
}

int findMinIndex(int a[], int n) {
    int minIndex = 0;
    for (int i = 1; i < n; i++) {
        if (a[minIndex] > a[i]) {
            minIndex = i;
        }
    }
    return minIndex;
}

int main() {
    int mang[100];
    int n;
    input(mang, n);
    display(mang, n);

    int minIndex = findMinIndex(mang, n);
    printf("\nVi tri chua gia tri nho nhat trong mang a la: %d", minIndex);
    return 0;
}