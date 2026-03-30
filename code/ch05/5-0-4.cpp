#include <stdio.h>

void input(int a[], int &n) {
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

void display(int a[], int n) {
    printf("Mang a: ");
    for (int i = 0; i < n; i++) {
        printf("%3d ", a[i]);
    }
}

bool checkSoNguyenTo(int n) {
    if (n == 2 || n == 3) {
        return true;
    } 
    if (n <= 1 || n % 2 == 0 || n % 3 == 0) {
        return false;
    } 
    for (int i = 5; i*i < n; i += 6) {
        if (n%i == 0 || n%(i + 2) == 0) {
            return false;
        }
    }
    return true;
}

int demSoLuongSoNTNhoHon100(int mang[],int n) {
    int count=0;
    for (int i = 0; i < n; i++) {
        if (mang[i] < 100 && checkSoNguyenTo(mang[i]) ) {
            count++;
        }
    }
    return count;
}

int main() {
    int mang[100];
    int n;
    input(mang, n);
    display(mang, n);

    int num = demSoLuongSoNTNhoHon100(mang, n);
    printf("\nSo luong so nguyen to nho hon 100 la: %d", num);
    return 0;
}

