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

void insert(int a[], int& n) {
    int x, k;
    do {
        printf("Nhap vi tri muon them k = ");
        scanf("%d", &k);
        if (k < 0 || k > n) {
            printf("Error! Xin nhap lai!");
        }
    } while (k < 0 || k > n);
    printf("Nhap gia tri them vao x = ");
    scanf("%d", &x);

    for (int i = n; i > k; i--) {
        a[i] = a[i-1];
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

    printf("Them 1 phan tu vao mang A!\n");
    insert(mangA,n);
    display(mangA,n);
    return 0;
}