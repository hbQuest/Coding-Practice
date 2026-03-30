#include <stdio.h>

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

// 5.3.1
int giaTriNhoNhat(int a[], int n) {
    int min = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] < min) {
            min = a[i];
        }
    }
    return min;
}

// 5.3.2
int soChanDauTien(int a[], int n) {
    for (int i = 0; i < n; i++) {
        if (a[i]%2 == 0) {
            return a[i];
        }
    }
    return -1;
}

//5.3.3
bool checkSoNT(int a) {
    if (a == 2 || a == 3) {
        return true;
    }
    if (a < 2 || a % 2 == 0 || a % 3 == 0) {
        return false;
    }
    for (int j = 5; j*j <= a; j+=6) {
        if (a%j == 0 || a%(j+2) == 0) {
            return false;
        }
    }
    return true;
}

int soNguyenToDauTien(int a[], int n) {
    for (int i = 1; i < n; i++) {
        if (checkSoNT(a[i])) {
            return a[i];
        }
    }
    return -1;
}

// 5.3.4
bool checkSoHoanThien(int n) {
    if (n <= 0) { return false; }
    int sum = 0;
    for ( int i = 1; i < n; i ++) {
        if (n%i == 0) {
            sum += i;
        }
    }
    if (n == sum) {
        return true;
    }
    return false;
}

// 5.3.5
int giaTriAmDauTien(int a[], int n) {
    for (int i = 0; i < n; i++) {
        if (a[i] < 0) {
            return i;
        }
    }
    return -1;
}


int soHoanThienDauTien(int a[], int n) {
    for (int i = 0; i < n; i++) {
        if (checkSoHoanThien(a[i])) {
            return a[i];
        }
    }
    return -1;
}

// 5.3.9 Ky thuat dat linh canh
int timGiaTriAmLonNhat(int a[],int n) {
    int maxIndex = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] < 0) {
            if (maxIndex == -1 || a[i] > a[maxIndex]) {
                maxIndex = i;
            }
        }
    }
    return maxIndex;
}

// 5.3.10
int soNTLonNhat(int a[], int n) {
    int soNT = -1;
    for (int i = 0; i < n; i++) {
        if (checkSoNT(a[i])) {
            if (soNT == -1 || a[i] > soNT) {
                soNT = a[i];
            }
        }
    }
    return soNT;
}

// 5.3.11
int soHoanThienNhoNhat(int a[], int n) {
    int soHT = -1;
    for (int i = 0; i < n; i++) {
        if (checkSoHoanThien(a[i])) {
            if (soHT == -1 || soHT > a[i]) {
                soHT = a[i];
            }
        }
    }
    return soHT;
}

// 5.3.12
int giaTriChanNhoNhat(int a[], int n) {
    int minChan = -1;
    for (int i = 0; i < n; i++) {
        if (a[i]%2 == 0) {
            if (minChan == -1 || minChan > a[i]) {
                minChan = a[i];
            }
        }
    }
    return minChan;
}

// 5.3.13
int viTriAmLonNhat(int a[], int n) {
    int maxIndex = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] < 0) {
            if (maxIndex == -1 || a[maxIndex] < a[i]) {
                maxIndex = i;
            }
        }
    }
    return maxIndex;
}
int main() {
    int a[100];
    int n;
    nhapMang(a, n);
    xuatMang(a, n);

    int num = timGiaTriAmLonNhat(a, n);
    if (num == -1) {
        printf("Mang khong co gia tri am\n");
    } else {
        printf("Gia tri am lon nhat la %d\n", a[num]);
    }

    int min = giaTriNhoNhat(a, n);
    printf("Gia tri nho nhat: %d\n", min);

    int i = soChanDauTien(a,n);
    if (i == -1) {
        printf("Mang khong co so chan\n");
    } else {
        printf("So chan dau tien la: %d\n", i);
    }

    int j = soNguyenToDauTien(a,n);
    if (j == -1) {
        printf("Mang khong co so nguyen to\n");
    } else {
        printf("So nguyen to dau tien la: %d\n", j);
    }

    int k = soHoanThienDauTien(a,n);
    if (k == -1) {
        printf("Mang khong co so hoan thien\n");
    } else {
        printf("So hoan thien dau tien la: %d\n", k);
    }

    int viTriAm = giaTriAmDauTien(a,n);
    if (viTriAm == -1) {
        printf("Mang khong co so am\n");
    } else {
        printf("So am dau tien la: %d\n", a[viTriAm]);
    }

    int soNT = soNTLonNhat(a,n);
    if (soNT == -1) {
        printf("Mang khong co so nguyen to\n");
    } else {
        printf("So nguyen to lon nhat la: %d\n", soNT);
    }

    int soHT = soHoanThienNhoNhat(a,n);
    if (soHT == -1) {
        printf("Mang khong co so hoan thien\n");
    } else {
        printf("So hoan thien nho nhat la: %d\n", soHT);
    }

    int minChan = giaTriChanNhoNhat(a,n);
    if (minChan == -1) {
        printf("Mang khong co so chan\n");
    } else {
        printf("So chan nho nhat la: %d\n", minChan);
    }

    int maxIndex = viTriAmLonNhat(a,n);
    if (maxIndex == -1) {
        printf("Mang khong co so am\n");
    } else {
        printf("Vi tri so am lon nhat la: %d\n", maxIndex);
    }
    
    return 0;
}