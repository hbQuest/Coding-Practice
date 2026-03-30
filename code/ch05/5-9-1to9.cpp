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

// 5.9.1
void xoaPhanTuChiSoK(int a[], int &n, int k) {
    for (int i = k; i < n-1; i++) {
        a[i] = a[i+1];
    }
    n--;
}

// 5.9.2
void xoaTatCaSoLonNhat(int a[], int &n) {
    int max = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    int i = 0;
    while (i < n) {
        if (a[i] == max) {
            xoaPhanTuChiSoK(a,n,i);
        } else {
            i++;
        }
    }
}

// 5.9.3
void XoaTatCaSoAm(int a[], int &n) {
    int i = 0;
    while (i < n) {
        if (a[i] < 0) {
            xoaPhanTuChiSoK(a,n,i);
        } else {
            i++;
        }
    }
}

// 5.9.4
void XoaTatCaSoChan(int a[], int &n) {
    int i = 0;
    while (i < n) {
        if (a[i]%2 == 0) {
            xoaPhanTuChiSoK(a,n,i);
        } else {
            i++;
        }
    }
}

// 5.9.5
bool KiemTraChinhPhuong(int n) {
    if (n < 0) {return false;}
    int x = sqrt(n);
    if (x*x == n) {
        return true;
    }
    return false;
}

void XoaTatCaSoChinhPhuong(int a[], int &n) {
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (!KiemTraChinhPhuong(a[i])) {
            a[j] = a[i];
            j++;
        }
    }
    n = j;
}

// 5.9.6
void XoaTatCaPhanTuTrungX(int a[], int &n, int x) {
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != x) {
            a[j] = a[i];
            j++;
        }
    }
    n = j;
}

// 5.9.8
void XoaTatCaPhanTuTrungNhau(int a[], int &n) {
    int j = 0;
    for (int i = 0; i < n; i++) {
        bool trung = false;
        for (int k = 0; k < i; k++) {
            if (a[i] == a[k]) {
                trung = true;
                break;
            }
        }
        if (!trung) {
            a[j] = a[i];
            j++;
        }
    }
    n=j;
}

// 5.9.9
void XoaTatCaPhanTuNhieuHon1Lan(int a[], int &n) {
    int temp[100];
    int j=0;
    for (int i = 0; i < n; i++) {
        int dem = 0;
        for (int k = 0; k < n; k++) {
            if (a[i] == a[k]) {
                dem++;
            }
        }
        if (dem == 1) {
            temp[j++] = a[i];
        }
    }
    for (int i = 0; i < j; i++) {
        a[i] = temp [i];
    }
    n = j;
}

int main() {
    int a[100], n;
    nhapMang(a,n);
    xuatMang(a,n);

    // int k;
    // do {
    //     printf("Nhap chi so k can xoa: ");
    //     scanf("%d", &k);
    //     if (k < 0 || k >= n) {
    //         printf("Loi! Xin nhap lai!\n");
    //     }
    // } while (k<0 || k>=n);

    // xoaPhanTuChiSoK(a,n,k);
    // printf("Mang sau khi xoa!\n");
    // xuatMang(a,n);

    // xoaTatCaSoLonNhat(a,n);
    // printf("Mang sau khi xoa tat ca so lon nhat!\n");
    // xuatMang(a,n);

    // XoaTatCaSoAm(a,n);
    // printf("Mang sau khi xoa tat ca so am!\n");
    // xuatMang(a,n);

    // XoaTatCaSoChan(a,n);
    // printf("Mang sau khi xoa tat ca so chan!\n");
    // xuatMang(a,n);

    // XoaTatCaSoChinhPhuong(a,n);
    // printf("Mang sau khi xoa tat ca so chinh phuong!\n");
    // xuatMang(a,n);

    // int x;
    // printf("Nhap x: ");
    // scanf("%d", &x);

    // XoaTatCaPhanTuTrungX(a,n,x);
    // printf("Mang sau khi xoa tat ca gia tri %d\n", x);
    // xuatMang(a,n);

    // XoaTatCaPhanTuTrungNhau(a,n);
    // printf("Mang sau khi xoa tat ca gia tri trung nhau nhung giu lai 1 phan tu\n");
    // xuatMang(a,n);

    XoaTatCaPhanTuNhieuHon1Lan(a,n);
    printf("Mang sau khi xoa tat ca gia tri trung nhau\n");
    xuatMang(a,n);

    return 0;
}