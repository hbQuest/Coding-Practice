#include <stdio.h>
#define MAX 100

void input(int a[], int& n) {
    do {
        printf("Nhap so phan tu n: ");
        scanf_s("%d", &n);
        if (n <= 0 || n > MAX) {
            printf("Xin nhap lai!");
        }
    } while (n <= 0 || n > MAX);
    for (int i = 0; i < n; i++) {
        printf("Nhap a[%d]: ", i);
        scanf_s("%d", &a[i]);
    }
}

void display(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
}

int countMax(int a[], int n) {
    int max = a[0], count = 1;
    for (int i = 1; i < n; i++) {
        if (max < a[i]) {
            max = a[i];
            count = 1;
        } else if (max == a[i]) {
            count++;
        }
    }
    return count;
}

int main() {
    int mangA[MAX];
    int n;

    input(mangA, n);
    printf("Mang A: ");
    display(mangA, n);

    int count = countMax(mangA, n);
    printf("\nSo gia tri lon nhat trong mang la: %d", count);
    return 0;
}