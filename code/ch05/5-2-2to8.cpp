#include <stdio.h>
#include <math.h>

void nhapMang(int a[], int &n) {
    do {
        printf("Nhap so phan tu n(1-100): ");
        scanf("%d", &n);
        if (n < 1 || n > 100) {
            printf("Xin nhap lai!");
        }
    } while (n < 1 || n > 100);
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

int giaTriDuongDauTien(int a[], int n) {
    for (int i = 0; i < n; i++) {
        if (a[i] > 0) {
            return a[i];
        }
    }
    return -1;
}

int soChanCuoi(int a[], int n) {
    for (int i = n-1; i >= 0; i--) {
        if (a[i]%2 == 0) {
            return a[i];
        }
    }
    return -1;
}

int viTriNhoNhat(int a[], int n) {
    int minIndex = 0, min = a[0];
    for (int i = 0; i < n; i++) {
        if (a[i] < min) {
            minIndex = i;
            min = a[i];
        }
    }
    return minIndex;
}

int viTriChanDau(int a[], int n) {
    for (int i = 0; i < n; i++) {
        if (a[i]%2 == 0) {
            return i;;
        }
    }
    return -1;
}

bool kiemTraSoHoanThien(int a) {
    int sum = 0;
    for (int i = 1; i < a; i++) {
        if (a%i == 0) {
            sum += i;
        }
    }
    if (sum == a) {
        return true;
    }
    return false;
}

int viTriSoHoanThienCuoi(int a[], int n) {
    for (int i = n-1; i >=0 ; i--) {
        if (kiemTraSoHoanThien(a[i])) {
            return i;
        }
    }
    return -1;
}

int giaTriDuongNhoNhat(int a[], int n) {
    int minIndex = -1, minDuong;
    for (int i = 0; i < n; i++) {
        if (a[i] > 0) {
            if (minIndex==-1 || a[i] < a[minIndex]) {
                minIndex = i;
            }
        }
    }
    return minIndex;
}

int viTriGiaTriDuongNhoNhat(int a[], int n) {
    int minIndex = -1, minDuong;
    for (int i = 0; i < n; i++) {
        if (a[i] > 0) {
            if (minIndex==-1 || a[i] < a[minIndex]) {
                minIndex = i;
            }
        }
    }
    return minIndex;
}

int main() {

    int n;
    int a[100];
    nhapMang(a, n);
    xuatMang(a, n);
    int i = giaTriDuongDauTien(a,n);

    if (i == -1) {
        printf("Mang khong co gia tri duong nao");
    } else {
        printf("Gia tri duong dau tien la: %d\n", i);
    }

    int j = soChanCuoi(a,n);

    if (j == -1) {
        printf("Mang khong co so chan nao");
    } else {
        printf("So chan cuoi cung la: %d\n", j);
    }
    
    int minIndex = viTriNhoNhat(a,n);
    printf("Vi tri chua gia tri nho nhat: %d\n", minIndex);
    
    int evenIndex = viTriChanDau(a,n);
    if (evenIndex == -1) {
        printf("Mang khong co gia tri chan\n");
    } else {
        printf("Vi tri chua gia tri chan dau tien: %d\n", evenIndex);
    }

    int k = viTriSoHoanThienCuoi(a,n);

    if (k == -1) {
        printf("Mang khong co so hoan thien");
    } else {
        printf("Vi tri so hoan thien cuoi cung la: %d\n", k);
    }

    int t = giaTriDuongNhoNhat(a,n);

    if (t == -1) {
        printf("Mang khong co gia tri duong nao");
    } else {
        printf("Gia tri duong nho nhat la: %d\n", a[t]);
    }

    int m = viTriGiaTriDuongNhoNhat(a,n);

    if (m == -1) {
        printf("Mang khong co gia tri duong nao");
    } else {
        printf("Vi tri gia tri duong nho nhat la: %d\n", m);
    }
    
    return 0;
}