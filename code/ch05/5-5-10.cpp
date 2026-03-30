#include <stdio.h>
#include <math.h>

void nhapMang(int a[], int &n) {
    do {
        printf("Nhap so phan tu n: ");
        scanf("%d", &n);
        if (n <= 0 || n > 100) {
            printf("Xin nhap lai!");
        }
    } while (n <= 0 || n > 100);
    for (int i = 0; i < n; i++) {
        printf("Nhap a[%d]: ", i);
        scanf("%d", &a[i]);
    }
}

void xuatMang(int a[], int n) {
    printf("Mang a: ");
    for (int i = 0; i < n; i++) {
        printf("%3d ", a[i]);
    }
    printf("\n");
}

// 5.5.10
bool kiemTraDoiXung(int n) { 
    int soDao=0, donVi;
    int temp = n;
    while (temp != 0) {
        donVi = temp%10;
        soDao = soDao * 10 + donVi;
        temp /= 10;
    }
    if (soDao == n) {
        return true;
    }
    return false;
}
 
int tongCacSoDoiXung(int a[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (kiemTraDoiXung(a[i])) {
            sum += a[i];
        }
    }
    return sum;
}

// 5.5.16
double khoangCachTrungBinh(int a[], int n) {
    int khoangCach = 0, soCap = 0;
    for (int i = 0; i < n-1; i++) {
        for (int j = i + 1; j < n; j++) {
            khoangCach += (abs(a[i] - a[j]));
            soCap++;
        }
    }
    return (double)khoangCach/soCap;
}

int main() {

    int a[100];
    int n;
    nhapMang(a,n);
    xuatMang(a,n);
    int ketQua = tongCacSoDoiXung(a,n);
    printf("Tong cac so doi xung la: %d", ketQua);

    double k = khoangCachTrungBinh(a,n);
    printf("Khoang cach trung binh giua cac gia tri: %.2lf", k);
    return 0;
}