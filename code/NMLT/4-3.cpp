// De 2013-2014 - HK1

#include <stdio.h>
#define MAX 100

void nhapMang(int a[], int& n) {
    do {
        printf("Nhap so phan n: ");
        scanf("%d", &n);
        if ( n<0 || n>=MAX) {
            printf("Nhap lai n!\n");
        }
    } while (n <0 || n >= 100);

    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu %d: ", i);
        scanf("%d", &a[i]);
    }
}

int xoaK(int a[], int& n, int k) {
    printf("Nhap chi so k can xoa: ");
    scanf("%d", &k);
    if ( k<0 || k >= n) {
        return 0;
    } else {
        for (int i = k; i < n-1; i++) {
            a[i] = a[i+1];
        }
        n--;
        return 1;
    }
}

void xuatMang(int a[],int n) {
    printf("Phan tu trong mang: ");
    for (int i = 0; i < n; i++) {
        printf("%d  ", a[i]);
    }
    printf("\n");
}

int timX(int a[], int n,int x) {
    printf("Nhap x: ");
    scanf("%d", &x);
    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            return i;
        }
    }
    return -1;
}

void xoaSoAm(int a[],int& n) {
    int i=0;
    while (i < n) {
        if (a[i] < 0) {
            for (int j = i; j < n-1; j++) {
                a[j] = a[j+1];
            }
            n--;
        } else {
            i++;
        }
    }
}

int main() {
    int n;
    int a[MAX];
    
    nhapMang(a,n);
    int k;
    int xoa = xoaK(a,n,k);

    xuatMang(a,n);
    int x;
    int tim = timX(a,n,x);
    printf("Tim thay gia tri x o vi tri %d trong mang\n", tim);
    
    xoaSoAm(a,n);
    xuatMang(a,n);
    return 0;
}