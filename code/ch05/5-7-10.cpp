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

void sort(int a[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (a[i] > a[j]) {
                swap(a[i], a[j]);
            }
        }
    }
}

void mergeAndSort(int a[], int b[], int c[], int nA, int nB, int nC) {
    int indexA = 0 , indexB = 0;
    for (int i = 0; i < nC; i++) {
        if (indexA < nA && indexB < nB) {
            if (a[indexA] > b[indexB]) {
                c[i] = b[indexB];
                indexB++;
            } else {
                c[i] = a[indexA];
                indexA++;
            } 
        } else if (indexA == nA) {
            c[i] = b[indexB];
            indexB++;
        } else if (indexB == nB) {
            c[i] = a[indexA];
            indexA++;
        }
    }
}

// Lam lai
void Tron2MangTang(int a[], int b[], int c[], int n, int m, int t) {
    int iA = 0, iB = 0;
    for (int i = 0; i < t; i++) {
        if (iA < n && iB < m) {
            if (a[iA] <= b[iB]) {
                c[i] = a[iA];
                iA++;
            } else {
                c[i] = b[iB];
                iB++;
            } 
        } else if (iA == n) {
            c[i] = b[iB];
            iB++;
        } else if (iB == m) {
            c[i] = b[iA];
            iA++;
        }
    }
}

int main() {
    int mangA[MAX], mangB[MAX];
    int nA, nB;

    printf("Nhap mang A!\n");
    input(mangA, nA);
    printf("Nhap mang B!\n");
    input(mangB, nB);
    printf("Mang A: ");
    display(mangA, nA);
    printf("Mang B: ");
    display(mangB, nB);
    
    printf("Sau khi sap xep tang dan\n");
    sort(mangA, nA);
    sort(mangB, nB);
    printf("Mang A: ");
    display(mangA, nA);
    printf("Mang B: ");
    display(mangB, nB);

    int mangC[MAX];
    int nC = nA + nB;

    printf("Tron mang A va B va sap xep thanh mang tang dan!\n");
    Tron2MangTang(mangA, mangB, mangC, nA, nB, nC);
    display(mangC, nC);
    return 0;
}
