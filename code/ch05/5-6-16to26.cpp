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
    printf("Liet ke mang: ");
    for (int i = 0; i < n; i++) {
        printf("%3d ", a[i]);
    }
    printf("\n");
}

// 5.6.16
void lietKeGiaTriXuatHien1Lan(int a[], int n) {
    bool flag = false;
    printf("Cac gia tri xuat hien dung 1 lan: ");
    for (int i = 0; i < n; i++) {
        int dem = 0;
        for (int j = 0; j < n; j++) {
            if (a[i] == a[j]) {
                dem++;
            }
        }
        if (dem == 1) {
            flag = true;
            printf("%d ", a[i]);
        }
    }
    if (!flag) {
        printf("Khong co");
    }
    printf("\n");
}
// 5.6.17
void lietKeGiaTriXuatHienQua1Lan(int a[], int n) {
    bool flag = false;
    printf("Cac gia tri xuat hien qua 1 lan: ");
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
            if (k > 1) {
                flag = true;
                printf("%d ", a[i]);
            }
        }
    }
    if (!flag) {
        printf("Khong co");
    }
    printf("\n");
}

// 5.6.18
void tanSuatGiaTriTrongDay(int a[], int n) {
    int b[100];
    int count=0;
    for (int i = 0; i < n; i++) {
        int j = 0;
        while (j < count) {
            if (a[i] == b[j]) {break;}
            j++;
        }
        if (j == count) {
            b[j] = a[i];
            count++;
        }
    }
    for (int i = 0; i < count; i++) {
        int dem = 0;
        for (int j = 0; j < n; j++) {
            if (b[i] == a[j]) {
                dem++;
            }
        }
        printf("Gia tri %d xuat hien %d lan\n", b[i], dem);
    }
}

// 5.6.19
bool kiemTraTonTai(int a[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            return true;
        }
    }
    return false;
}
int demGiaTriChiXuatHienTrong1Mang(int a[], int b[], int n, int m) {
    int dem = 0;
    // Kiem tra a trong b?
    for (int i = 0; i < n; i++) {
        bool soMoi = true;
        for (int j = 0; j < i; j++) {
            if (a[i] == a[j]) {
                soMoi = false;
                break;
            }
        }
        if (soMoi && !kiemTraTonTai(b,m,a[i])) {
            dem++;
        }
    }
    // Kiem tra b trong a?
    for (int i = 0; i < m; i++) {
        bool soMoi = true;
        for (int j = 0; j < i; j++) {
            if (b[i] == b[j]) {
                soMoi = false;
                break;
            }
        }
        if (soMoi && !kiemTraTonTai(a,n,b[i])) {
            dem++;
        }
    }
    return dem;
}

// 5.6.20
void lietKeGiaTriChiXuatHienTrong1Mang(int a[], int b[], int n, int m) {
    bool flag = false;
    printf("Cac gia tri chi xuat hien o 1 trong 2 mang: ");
    for (int i = 0; i < n; i++) {
        bool soMoi = true;
        for (int j = 0; j < i; j++) {
            if (a[i] == a[j]) {
                soMoi = false;
                break;
            }
        }
        if (soMoi && !kiemTraTonTai(b,m,a[i])) {
            printf("%d ", a[i]);
            flag = true;
        }
    }

    for (int i = 0; i < m; i++) {
        bool soMoi = true;
        for (int j = 0; j < i; j++) {
            if (b[i] == b[j]) {
                soMoi = false;
                break;
            }
        }
        if (soMoi && !kiemTraTonTai(a,n,b[i])) {
            printf("%d ", b[i]);
            flag = true;
        }
    }

    if (!flag) {
        printf("Khong co gia tri");
    }
    printf("\n");
}

// 5.6.21
int soLanXuatHienMangATrongMangB(int a[], int b[], int n, int m) {
    if (n > m) {return 0;}
    int dem = 0;
    int startA = a[0];
    
    for (int i = 0; i <= m-n; i++) {
        if (b[i] == startA) {
            bool coXuatHien = true;
            for (int j = 1; j < n; j++) {
                if (a[j] != b[i+j]) {
                    coXuatHien = false;
                    break;
                }
            }
            if (coXuatHien) {
                dem++;
            }
        }
    }
    return dem;
}

// 5.6.22
void lietKeGiaTriXuatHienNhieuNhat(int a[], int n) {
    int demMax = 0;
    for (int i = 0; i < n; i++) {
        int dem = 0;
        for (int j = 0; j < n; j++) {
            if (a[i] == a[j]) {
                dem++;
            }
        }
        if (dem > demMax) {
            demMax = dem;
        }
    }
    printf("Gia tri xuat hien nhieu nhat trong mang la ");
    for (int i = 0; i < n; i++) {
        int dem = 0;
        for (int j = 0; j < n; j++) {
            if (a[i] == a[j]) { dem++; }
        }
        if (dem == demMax) {
            bool soMoi = true;
            for (int k = 0; k < i; k++) {
                if (a[k] == a[i]) {
                    soMoi = false;
                    break;
                }
            }
            if (soMoi) {
                printf("%d ", a[i]);
            }
        }
    }
    printf("\n");
}

// 5.6.23
bool kiemTraNguyenTo(int n) {
    if (n == 2 || n == 3) {
        return true;
    }
    if (n < 2 || n%2 == 0 || n%3 == 0) {
        return false;
    }
    for (int i = 5; i*i <= n; i+=6) {
        if (n%i == 0 || n%(i+2) == 0) {
            return false;
        }
    }
    return true;
}

int demSoLuongNguyenToPhanBiet(int a[], int n) {
    int dem = 0;
    for (int i = 0; i < n; i++) {
        if (kiemTraNguyenTo(a[i])) {
            bool moi = true;
            for (int j = 0; j < i; j++) {
                if (a[i] == a[j]) {
                    moi = false;
                    break;
                }
            }
            if (moi) {
                dem++;
            }
        }
    }
    return dem;
}

int main() {
    int a[100], b[100];
    int n, m;

    nhapMang(a, n);
    xuatMang(a, n);
    // nhapMang(b, m);
    // xuatMang(b, m);

    // lietKeGiaTriXuatHien1Lan(a,n);
    // lietKeGiaTriXuatHienQua1Lan(a,n);

    // int dem = demGiaTriChiXuatHienTrong1Mang(a,b,n,m);
    // printf("So gia tri chi xuat hien 1 trong 2 mang: %d\n", dem);
    
    // lietKeGiaTriChiXuatHienTrong1Mang(a,b,n,m);
    
    // dem = soLanXuatHienMangATrongMangB(a,b,n,m);
    // printf("So lan xuat hien cua mang a trong mang b: %d\n", dem);

    lietKeGiaTriXuatHienNhieuNhat(a,n);

    int ketQua = demSoLuongNguyenToPhanBiet(a,n);
    printf("So luong so nguyen to phan biet la %d\n", ketQua);

    return 0;
}