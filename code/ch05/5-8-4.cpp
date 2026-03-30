#include <stdio.h>
#define MAX 100

void inputAndSort(int a[], int& n) {
    do {
        printf("Nhap so phan tu n: ");
        scanf("%d", &n);
        if (n <= 0 || n > MAX) {
            printf("Xin nhap lai!\n");
        }
    } while(n <= 0 || n > MAX);
    int x;
    for (int i = 0; i < n; i++) {
        printf("Nhap a[%d]: ", i);
        scanf("%d", &x);
        int k = i;

        while (k > 0 && x < a[k-1]) {
            a[k] = a[k-1];
            k--;
        }
        a[k] = x;
    }
}

void display(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%3d ", a[i]);
    }
    putchar('\n');
}


int main() {
    int mangA[MAX];
    int n;
    printf("Xin nhap mang A:\n");
    inputAndSort(mangA,n);
    display(mangA,n);

    return 0;
}