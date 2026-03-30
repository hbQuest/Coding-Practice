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

void oddSort(int a[], int n) {
    for (int i = 0; i < n-1; i++) {
        if (a[i]%2 != 0) {
            for (int j = i+1; j < n; j++) {
                if (a[j]%2 != 0) {
                    if (a[i] > a[j]) {
                        swap(a[i], a[j]);
                    }
                }  
            }
        }
    }
}

int main() {
    int mangA[MAX];
    int nA;

    printf("Nhap mang A!\n");
    input(mangA, nA);
    
    printf("Sau khi sap xep so le tang dan\n");
    oddSort(mangA, nA);
    display(mangA, nA);

    return 0;
}
