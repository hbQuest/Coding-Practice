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

// 5.4.11
void lietKeViTriChuaSoAmDauTien(int a[], int n) {
    bool flag = false;
    int soAmDauTien = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] < 0) {
            flag = true;
            soAmDauTien = a[i];
            break;
        }
    }
    if (!flag) {
        printf("Mang khong co so am\n");
        return;
    }
    printf("Cac vi tri chua so am dau tien: ");
    for (int i = 0; i < n; i++) {
        if (a[i] == soAmDauTien) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

// 5.4.12
void lietKeViTriChuaSoDuongNhoNhat(int a[], int n) {
    bool flag = false;
    int soDuongNhoNhat;
    for (int i = 0; i < n; i++) {
        if (a[i] > 0) {
            if (!flag || a[i] < soDuongNhoNhat) {
                flag = true;
                soDuongNhoNhat = a[i];
            }
        }
    }
    if (!flag) {
        printf("Mang khong co so duong\n");
        return;
    }
    printf("Cac vi tri chua so duong nho nhat: ");
    for (int i = 0; i < n; i++) {
        if (a[i] == soDuongNhoNhat) {
            printf("%d ", i);
        }
    }
    printf("\n");   
}

// 5.4.13
void lietKeViTriChanLonNhat(int a[], int n) {
    bool flag = false;
    int chanLonNhat;
    for (int i = 0; i < n; i++) {
        if (a[i]%2 == 0) {
            if (!flag || a[i] > chanLonNhat) {
                flag = true;
                chanLonNhat = a[i];
            }
        }
    }
    if (!flag) {
        printf("Mang khong co so chan\n");
        return;
    }       
    printf("Cac vi tri chua so chan lon nhat: ");   
    for (int i = 0; i < n; i++) {
        if (a[i] == chanLonNhat) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

// 5.4.14
bool checkSoNguyenTo(int n) {
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
bool checkChuSoDauTienLaSoLe(int n) {
    n = abs(n);
    while (n >= 10) {
        n /= 10;
    }
    if (n%2 == 1) {
        return true;
    }
    return false;
}
void lietKeSoCoChuSoDauTienLaSoLe(int a[], int n) {
    bool flag = false;
    printf("Cac so nguyen to co chu so dau tien la so le: ");
    for (int i = 0; i < n; i++) {
        if (checkSoNguyenTo(a[i]) && checkChuSoDauTienLaSoLe(a[i])) {
            printf("%d ", a[i]);
            flag = true;
        }
    }
    if (!flag) {
        printf("Khong co so nao thoa dieu kien");
    }
    printf("\n");
}

// 5.4.15
bool checkToanSoLe(int n) {
    n = abs(n);
    if (n == 0) {
        return false;
    }
    while (n != 0) {
        int soDu = n%10;
        if (soDu%2 == 0) {
            return false;
        }
        n /= 10;
    }
    return true;
}
void lietKeToanChuSoLe(int a[], int n) {
    bool flag = false;  
    printf("Cac so toan chu so le: ");
    for (int i = 0; i < n; i++) {
        if (checkToanSoLe(a[i])) {
            printf("%d ", a[i]);
            flag = true;
        }
    }
    if (!flag) {
        printf("Khong co so nao thoa dieu kien");
    }
    printf("\n");
}

// 5.4.16
void lietKeGiaTriCucDai(int a[], int n) {
    bool flag = false;
    printf("Cac gia tri cuc dai: ");
    for (int i = 0; i < n; i++) {
        bool coGiaTriTraiNhoHon = false;
        bool coGiaTriPhaiNhoHon = false;
        if (i == 0 || a[i-1] < a[i]) {
            coGiaTriTraiNhoHon = true;
        }
        if (i == n-1 || a[i+1] < a[i]) {
            coGiaTriPhaiNhoHon = true;
        }
        if (coGiaTriTraiNhoHon && coGiaTriPhaiNhoHon) {
            printf("%d ", a[i]);
            flag = true;
        }
    }
    if (!flag) {
        printf("Khong co gia tri nao thoa dieu kien");  
    }
    printf("\n");
}

// 5.4.17
bool checkChuSuDauTienChan(int n) {
    n = abs(n);
    while (n >= 10) {
        n /= 10;
    }
    if (n%2 == 0) {
        return true;
    }
    return false;
}
void lietKeSoCoChuSoDauTienLaChan(int a[], int n) {
    bool flag = false;
    printf("Cac so co chu so dau tien la so chan: ");
    for (int i = 0; i < n; i++) {
        if (checkChuSuDauTienChan(a[i])) {
            printf("%d ", a[i]);
            flag = true;
        }
    }
    if (!flag) {
        printf("Khong co so nao thoa dieu kien");
    }
    printf("\n");
}

// 5.4.18
bool checkDang3k(int n) {
    if (n <= 0) {
        return false;
    } 
    while (n%3 == 0) {
        n /= 3;
    }
    if (n == 1) {
        return true;
    }
    return false;
}
int lietKeSoDang3k(int a[], int n) {
    bool flag = false;
    printf("Cac so dang 3^k: ");
    for (int i = 0; i < n; i++)
    {
        if (checkDang3k(a[i])) {
            printf("%d ", a[i]);
            flag = true;
        }
    }
    if (!flag) {
        return 0;
    }
    printf("\n");
    return 1;
}

// 5.4.19
void lietKeCapGiaTriGanNhauNhat(int a[], int n) {
    int khoangCachMin = abs(a[0] - a[1]);
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (abs(a[i] - a[j]) < khoangCachMin) {
                khoangCachMin = abs(a[i] - a[j]);
            }
        }
    }
    printf("Cap gia tri gan nhau nhat: ");
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (abs(a[i] - a[j]) == khoangCachMin) {
                printf("(%d,%d) ", a[i], a[j]);
            }
        }
    }
    printf("\n");
}

// 5.4.20
void lietKeBoBaThoaDieuKien(int a[], int n) {
    bool flag = false;
    printf("Cac bo ba thoa dieu kien: ");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (i != j && i != k && j != k && a[i] == a[j] + a[k]) {
                    printf("(%d,%d,%d) ", a[i], a[j], a[k]);
                    flag = true;
                }
            }
        }
    }
    if (!flag) {
        printf("Khong co bo ba nao thoa dieu kien");
    }
    printf("\n");
}
int main() {
    int a[100];
    int n;
    nhapMang(a,n);
    xuatMang(a,n);

    lietKeViTriChuaSoAmDauTien(a,n);
    lietKeViTriChuaSoDuongNhoNhat(a,n);
    lietKeViTriChanLonNhat(a,n);
    lietKeSoCoChuSoDauTienLaSoLe(a,n);      
    lietKeToanChuSoLe(a,n);
    lietKeGiaTriCucDai(a,n);
    lietKeSoCoChuSoDauTienLaChan(a,n);
    if (lietKeSoDang3k(a,n) == 0) {
        printf("Khong co so nao thoa dieu kien\n");
    }
    lietKeCapGiaTriGanNhauNhat(a,n);
    lietKeBoBaThoaDieuKien(a,n);

    return 0;
}
