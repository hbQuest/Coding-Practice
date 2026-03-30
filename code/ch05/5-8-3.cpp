#include <stdio.h>
#define MAX 100

void input(int a[], int& n) {
    do {
        printf("Nhap so phan tu n: ");
        scanf("%d", &n);
        if (n <= 0 || n > MAX) {
            printf("Xin nhap lai!\n");
        }
    } while(n <= 0 || n > MAX);
    for (int i = 0; i < n; i++) {
        printf("Nhap a[%d]: ", i);
        scanf("%d", &a[i]);
    }
}

void display(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%3d ", a[i]);
    }
    putchar('\n');
}

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void ascendingSort(int a[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                swap(a[i], a[j]);
            }
        }
    }
}

void insert(int a[], int& n) {
    int x;
    printf("Nhap gia tri them vao x = ");
    scanf("%d", &x);

    for (int i = 0; i < n; i++) {
        if (a[i] > x) {
            int j;
            for (j = n; j > i; j--) {
                a[j] = a[j-1];
            }
            a[j] = x;
            break;
        }
    }
    n++;
}

void insert2(int a[], int &n) {
    int x;
    printf("Nhap gia tri them vao x = ");
    scanf("%d", &x);

    int k = n;
    while (x < a[k-1]) {
        a[k] = a[k-1];
        k--;
    }
    a[k] = x;
    n++;
}

int main() {
    int mangA[MAX];
    int n;
    printf("Xin nhap mang A:\n");
    input(mangA,n);
    display(mangA,n);
    printf("Mang A sau sap xep tang dan:\n");
    ascendingSort(mangA,n);
    display(mangA,n);

    printf("Them 1 phan tu vao mang A!\n");
    insert2(mangA,n);
    display(mangA,n);
    return 0;
}