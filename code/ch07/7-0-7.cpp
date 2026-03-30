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

void hoanVi(double& a, double& b) {
    a = a + b;
    b = a - b;
    a = a - b;
}

void sapXepMangTangDan(double b[],int soPhanTu) {
    for (int i = 0; i < soPhanTu-1; i++) {
        for (int j = i+1; j < soPhanTu; j++) {
            if (b[i] > b[j]) {
                hoanVi(b[i], b[j]);
            }
        }
    }
}

void sapXepTangTuTrenXuongTuTraiSang(double a[][MAX], int n) {
    int soPhanTu = n*n, index = 0;
    double b[soPhanTu] = {0};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            b[index++] = a[i][j];
        }
    }

    sapXepMangTangDan(b,soPhanTu);
    index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = b[index++];
        }
    }
}

void sapXepKhongDungMangPhu(double a[][MAX], int n) {
    for (int i = 0; i < (n*n)-1; i++) {
        int d1 = i/n, c1 = i%n;
        for (int j = i+1; j < n*n; j++) {
            int d2 = j/n, c2 = j%n;
            if (a[d1][c1] > a[d2][c2]) {
                hoanVi(a[d1][c1], a[d2][c2]);
            }
        }
    }
}

int main() {
    double a[MAX][MAX];
    int n;

    nhap(a,n);
    xuat(a,n);
    
    printf("Ma tran vuong sau khi da sap xep tang dan tu tren xuong duoi va tu trai sang phai:\n");
    // sapXepTangTuTrenXuongTuTraiSang(a,n); // Có dùng mảng phụ
    sapXepKhongDungMangPhu(a,n);
    xuat(a,n);

    return 0;
}   