#include <stdio.h>
#include <math.h>
#define MAX 100

void nhap(double a[][MAX], int& n) {
    do {
        printf("Nhap n: ");
        scanf("%d", &n);
        if (n < 0 || n > MAX) {
            printf("So n khong hop le! Xin nhap lai!");
        }
    } while (n < 0 || n > MAX);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Nhap a[%d][%d]: ", i,j);
            scanf("%lf", &a[i][j]);
        }
    }
}

void xuat(double a[][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%6.2lf", a[i][j]);
        }
        printf("\n");
    }
}

void tim2GiaTriGanNhauNhat(double a[][MAX], int n) {
    double n1,n2;
    int dMin = 100;
    for (int i = 0; i < (n*n)-1; i++) {
        int d1 = i/n, c1 = i%n;
        for (int j = i+1; j < n*n; j++) {
            int d2 = j/n, c2 = j%n;
            int d = abs(a[d1][c1] - a[d2][c2]);
            if (dMin > d) {
                dMin = d;
                n1 = a[d1][c1];
                n2 = a[d2][c2];
            }
        }
    }
    printf("Hai gia tri gan nhau nhat la %.2lf va %.2lf, 2 gia tri cach nhau %d don vi", n1, n2, dMin);
}

int main() {
    double a[MAX][MAX];
    int n;

    nhap(a,n);
    xuat(a,n);
    
    tim2GiaTriGanNhauNhat(a,n);
    

    return 0;
}   