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

// 5.3.26
bool checkToanChuSoLe(int n) {
    if (n%2 == 0) {
        return false;
    }
    int soDu = 0;
    while (n != 0) {
        soDu = n%10;
        if (soDu%2 == 0) { return false; }
        n /= 10;
    }
    return true;
}

int giaTriToanChuSoLeLonNhat(int a[], int n) {
    int max = 0;
    for (int i = 0; i < n; i++) {
        if (checkToanChuSoLe(a[i])) {
            if (max == 0 || a[i] > max) {
                max = a[i];
            }
        }
    }
    return max;
}

// 5.3.27
bool checkDang5k(int n) {
    if (n <= 0) { return false; }
    while (n%5 == 0) {
        n /= 5;
    }
    if (n == 1) {return true;}
    return false;
}

int giaTriDang5kLonNhat(int a[], int n) {
    int max = 0;
    for (int i = 0; i < n; i++) {
        if (checkDang5k(a[i])) {
            if (max == 0 || a[i] > max) {
                max = a[i];
            }
        }
    }
    return max;
}

// 5.3.28
int soChanLonNhatThoaDieuKien(int a[], int n) {
    int minLe = 1;
    bool coSoLe = false;

    for (int i = 0; i < n; i++) {
        if (a[i]%2 != 0) {
            if (!coSoLe || a[i] < minLe) {
                coSoLe = true;
                minLe = a[i];
            }
        } 
    }
    int maxChan = 0;
    bool coSoChan = false;
    
    for (int i = 0; i < n; i++) {
        if (a[i]%2 == 0) {
            if (!coSoLe || a[i] < minLe) {
                if (!coSoChan || a[i] > maxChan) {
                    coSoChan = true;
                    maxChan = a[i];
                }
            }
        }
    }
    if (coSoChan) return maxChan;
    return -1;
}

// 5.3.29
int timMax(int a[], int n) {
    int max = a[0];
    for (int i = 0; i < n; i++) {
        if (max < a[i]) {
            max = a[i];
        }
    }
    return max;
}
bool checkSoNguyenTo(int n) {
    if (n < 2) {return false;}
    for (int i = 2; i <= sqrt(n); i++) {
        if (n%i == 0) {return false;}
    }
    return true;
}
int soNTNhoNhatLonHonMoiGiaTri(int a[], int n) {
    int max = timMax(a,n);
    int i = max+1;
    while (!checkSoNguyenTo(i)) {
        i++;
    }
    return i;
}

// 5.3.30
int uocChungLonNhat(int a, int b) {
    if (a == 0 || b == 0) {
        return a + b;
    }
    while (b != 0) {
        int phanDu = a%b;
        a=b;
        b=phanDu;
    }
    return a; 
}

int uocChungLonNhatCuaMang(int a[], int n) {
    int UCLN = a[0];
    for(int i = 1; i < n; i++) {
        UCLN = uocChungLonNhat(UCLN, a[i]);
    }
    return UCLN;
}

// 5.3.31
int boiChungNhoNhat(int a, int b) {
    if (a == 0 || b == 0) {
        return 0;
    }
    return ((a*b)/uocChungLonNhat(a,b));
}

int boiChungNhoNhatCuaMang(int a[], int n) {
    int BCNN = a[0];
    for(int i = 1; i < n; i++) {
        BCNN = boiChungNhoNhat(BCNN, a[i]);
    }
    return BCNN;
}

// 5.3.32
void demChuSo(int n, int b[]) {
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
    int dem[10] = {0};
    for(int i = 0; i < n; i++) {
        demChuSo(a[i], dem);
    }
    int min = -1;
    int choSoMin;
    for(int i = 0; i < 10; i++) {
        if (dem[i] != 0) {
            if (min == -1 || min > dem[i]) {
                min = dem[i];
                choSoMin = i;
            }
        }
    }
    return choSoMin;
}

// 5.3.33
void inCapGiaTriThoaDieuKien(int a[], int n) {
    printf("Cap gia tri (a,b) thoa dieu kien a <= b: ");
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (a[i] < a[j]) {
                printf("(%d,%d) ", a[i], a[j]);
            } else {
                printf("(%d,%d) ", a[j], a[i]);
            }
        }
    }
    printf("\n");
}

// 5.3.34
void haiGiaTriGanNhauNhat(int a[], int n) {
    int gt1 = a[0], gt2 = a[1];
    int khoangCachMin = abs(a[0] - a[1]);
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (abs(a[i] - a[j]) < khoangCachMin) {
                khoangCachMin = abs(a[i] - a[j]);
                gt1 = a[i];
                gt2 = a[j];
            } 
        }
    }
    printf("Gia tri gan nhau nhat la: %d va %d\n", gt1, gt2);
}


int main() {
    int a[100];
    int n;
    nhapMang(a,n);
    xuatMang(a,n);

    int x = giaTriToanChuSoLeLonNhat(a,n);
    if(x == 0) {
        printf("Khong co gia tri ma toan chu so le\n");
    } else {
        printf("Gia tri toan chu so le lon nhat la: %d\n", x);
    }

    x = giaTriDang5kLonNhat(a,n);
    if(x == 0) {
        printf("Khong co gia tri dang 5^k\n");
    } else {
        printf("Gia tri dang 5^k lon nhat la: %d\n", x);
    }

    x = soChanLonNhatThoaDieuKien(a,n);
    if(x == -1) {
        printf("Khong co gia tri thoa dieu kien\n");
    } else {
        printf("Gia tri chan lon nhat nho hon moi so le trong mang: %d\n", x);
    }

    x= soNTNhoNhatLonHonMoiGiaTri(a,n);
    printf("So nguyen to nho nhat ma lon hon moi gia tri trong mang: %d\n", x);
    
    x = uocChungLonNhatCuaMang(a,n);
    printf("Uoc chung lon nhat cua mang: %d\n", x);

    x = boiChungNhoNhatCuaMang(a,n);
    printf("Boi chung nho nhat cua mang: %d\n", x);
    
    x = chuSoXuatHienItNhat(a,n);
    printf("Chu so xuat hien it nhat trong mang: %d\n", x);

    inCapGiaTriThoaDieuKien(a,n);
    haiGiaTriGanNhauNhat(a,n);
    return 0;
}