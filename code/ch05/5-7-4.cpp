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

bool checkPrime(int n) {
    if (n == 2 || n == 3) {
        return true;
    } 
    if (n < 2 || n%2 == 0 || n %3 == 0) {
        return false;
    } 
    for (int i = 5; i*i <= n; i+=6) {
        if (n%i == 0 || n%(i+2) == 0) {
            return false;
        }
    }
    return true;
}

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void primeSort(int a[], int n) {
    for (int i = 0; i < n-1; i++) {
        if (checkPrime(a[i])) {
            for (int j = i+1; j < n; j++) {
                if (checkPrime(a[j])) {
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
    
    printf("Sau khi sap xep so nguyen to tang dan\n");
    primeSort(mangA, nA);
    display(mangA, nA);

    return 0;
}
