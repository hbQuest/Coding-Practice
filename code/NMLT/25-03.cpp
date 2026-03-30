#include <stdio.h>
#include <math.h>

void nhapMang(int a[], int& n) {
    do {
        printf("Nhap so phan n: ");
        scanf("%d", &n);
        if (n<0 || n>100) {
            printf("Nhap lai n!\n");
        }
    } while (n < 0 || n > 100);

    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu %d: ", i);
        scanf("%d", &a[i]);
    }
}

void xuatMang(int a[],int n) {
    printf("Phan tu trong mang: ");
    for (int i = 0; i < n; i++) {
        printf("%d  ", a[i]);
    }
    printf("\n");
}

void demChuSoXuatHien(int n, int b[]) {
    if (n == 0) {
        b[0]++;
        return;
    }
    n = abs(n);
    while (n != 0) {
        int soDu = n % 10;
        b[soDu]++;
        n /= 10;
    }
}

int chuSoXuatHienItNhat(int a[], int n) {
    int demChuSo[10] = {0};
    for(int i = 0; i < n; i++) {
        demChuSoXuatHien(a[i], demChuSo);
    }
    int minIndex = -1;
    for(int i = 0; i < 10; i++) {
        if (demChuSo[i] != 0) {
            if (minIndex == -1 || demChuSo[minIndex] > demChuSo[i]) {
                minIndex = i;
            }
        }
    }
    return minIndex;
}

void CacChuSoXuatHienItNhat(int a[], int n, int b[], int &m) {
    int demChuSo[10] = {0};
    for(int i = 0; i < n; i++) {
        demChuSoXuatHien(a[i], demChuSo);
    }
    int min = -1;

    for(int i = 0; i < 10; i++) {
        if (demChuSo[i] != 0) {
            if (min == -1 || min > demChuSo[i]) {
                min = demChuSo[i];
                b[0] = i;
                m = 1;
            } else {
                if (min == demChuSo[i]) {
                    b[m] = i;
                    m++;
                }
            }
        }
    }
}

void TanSuatXuatHienCacGiaTri(int a[], int n) {
    for (int i = 0; i < n; i++) {
        bool soMoi = true;
        for (int j = 0; j < i; j++) {
           if (a[i] == a[j]) {
                soMoi = false;    
                break;
            } 
        }
        if (soMoi) {
            int k = 1;
            for (int j = i+1; j < n; j++) {
                if (a[i] == a[j]) {
                    k++;
                }
            }
            printf("So %d xuat hien %d lan\n", a[i], k);
        }
    }
}

int main() {
    int a[100];
    int n;
    nhapMang(a,n);
    xuatMang(a,n);
    int ketQua = chuSoXuatHienItNhat(a,n);
    printf("Chu so xuat hien it nhat trong mang la: %d\n", ketQua);

    int b[10];
    int m;
    printf("Cac chu so xuat hien it nhat: ");
    CacChuSoXuatHienItNhat(a,n,b,m);
    xuatMang(b,m);

    TanSuatXuatHienCacGiaTri(a,n);
    return 0;
}