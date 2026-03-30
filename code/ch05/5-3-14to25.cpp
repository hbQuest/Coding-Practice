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

int giaTriXaXNhat(int a[], int n, int x) {
    int khoangCach=0;
    int khoangCachMax=abs(a[0] - x), max = a[0];
    for (int i = 0; i < n; i++) {
        khoangCach = abs(a[i] - x);
        if (khoangCach > khoangCachMax) {
            max = a[i];
            khoangCachMax = khoangCach;
        }
    }
    return max;
}

// 5.3.15
int giaTriGanXNhat(int a[], int n, int x) {
    int khoangCach;
    int khoangCachMin = abs(a[0] - x), min = a[0];
    for (int i = 0; i < n; i++) {
        khoangCach = abs(a[i] - x);
        if (khoangCach < khoangCachMin) {
            min = a[i];
            khoangCachMin = khoangCach;
        }
    }
    return min;
}

// 5.3.16
void timDoan(int a[], int n) {
    int max = a[0];
    int min = a[0];
    for (int i = 0; i < n; i++) {
        if (min > a[i]) {
            min = a[i];
        }
        if (max < a[i]) {
            max = a[i];
        }
    }
    printf("Doan chua tat ca gia tri trong mang la [%d,%d]\n", min, max);
}

// 5.3.17
void timGiaTri(int a[], int n) {
    int max = a[0];
    for (int i = 0; i < n; i++) {
        if (max < abs(a[i])) {
            max = abs(a[i]);
        }
    }
    printf("Gia tri x = %d de [-%d,%d] chua tat ca gia tri trong mang\n", max, max, max);
}

// 5.3.18
int giaTriDauTien(int a[], int n) {
    for (int i = 0; i < n; i++) {
        if (a[i] > 2003) {
            return a[i];
        }
    }
    return -1;
}
// 5.3.19 : xem a nhu mang so thuc
int giaTriAmCuoi(int a[], int n) {
    for (int i = 0; i < n; i++) {
        if (a[i] < 0 && a[i] > -1) {
            return a[i];
        }
    }
    return -1;
}
// 5.3.20
int giaTriDauTrongKhoang(int a[], int n, int x, int y) {
    for (int i = 0; i < n; i++) {
        if (a[i] > x && a[i] < y) {
            return a[i];
        }
    }
    return -1;
}
// 5.3.21  (có hai giá trị lân cận và giá trị tại vị trí đó bằng tích hai giá trị lân cận)
int viTriThoaDieuKien(int a[], int n) {
    for (int i = 1; i < n-1; i++) {
        if (a[i] == (a[i-1]*a[i+1])) {
            return i;
        }
    }
    return -1;
}
// 5.3.22
bool checkSoChinhPhuong(int n) {
    if (n < 0) {
        return false;
    }
    for (int i = 0; i <= sqrt(n); i++) {
        if (i*i == n) {
            return true;
        }
    }
    return false;
}
int soChinhPhuongDau(int a[], int n) {
    for (int i = 1; i < n-1; i++) {
        if (checkSoChinhPhuong(a[i])) {
            return a[i];
        }
    }
    return -1;
}
// 5.3.23
bool checkSoGanh(int n) {
    if (n < 0) {
        return false;
    }
    int soNguoc=0;
    int temp = n, soDu;
    while (temp > 0) {
        soDu = temp%10;
        soNguoc = soNguoc * 10 + soDu;
        temp /= 10;
    }
    return (soNguoc == n);
}
int soGanh(int a[], int n) {
    for (int i = 0; i < n; i++) {
        if (checkSoGanh(a[i])) {
            return a[i];
        }
    }
    return -1;
}

// 5.3.24
bool checkChuSoLeDauTien(int n) {
    n = abs(n);
    int temp = n;
    while (temp >= 10) {
        temp /= 10;
    }
    if (temp%2 != 0) {
        return true;
    }
    return false;
}
int chuSoLeDauTien(int a[], int n) {
    for (int i = 0; i < n; i++) {
        if (checkChuSoLeDauTien(a[i])) {
            return a[i];
        }
    }
    return 0;
}

// 5.3.25
bool checkDang2k(int n) {
    if (n <= 0) {
        return false;
    }
    while (n%2 == 0) {
        n /= 2;
    }
    if (n == 1) return true;
    return false;
}

int giaTriDang2k(int a[], int n) {
    for (int i = 0; i < n; i++) {
        if (checkDang2k(a[i])) {
            return a[i];
        }
    }
    return 0;
}

int main() {
    int a[100];
    int n,x;
    nhapMang(a,n);
    xuatMang(a,n);
    printf("Nhap gia tri x: ");
    scanf("%d", &x);
    int d = giaTriXaXNhat(a,n,x);
    printf("Gia tri xa %d nhat la %d\n", x, d);
    int t = giaTriGanXNhat(a,n,x);
    printf("Gia tri gan %d nhat la %d\n", x, t);

    timDoan(a,n);
    timGiaTri(a,n);

    int u = giaTriDauTien(a,n);
    if ( u == -1) {
        printf("Mang khong co gia tri nao lon hon 2003\n");
    } else {
        printf("Gia tri dau tien lon hon 2003 la %d", u);
    }

    int l,v;
    printf("Nhap khoang (x,y) cho truoc!\n");
    printf("x: ");
    scanf("%d", &l);
    printf("y: ");
    scanf("%d", &v);

    int r = giaTriDauTrongKhoang(a,n,l,v);
    if (r == -1) {
        printf("Khong co gia tri trong mang thoa dieu kien\n");
    } else {
        printf("Gia tri dau tien trong mang thoa dieu kien: %d\n", r);
    }

    int w = viTriThoaDieuKien(a,n);
    if (w == -1) {
        printf("Khong co vi tri nao trong mang thoa dieu kien\n");
    } else {
        printf("Vi tri trong mang thoa dieu kien: %d\n", w);
    }

    int q = soChinhPhuongDau(a,n);
    if (q == -1) {
        printf("Khong co so chinh phuong trong mang\n");
    } else {
        printf("So chinh phuong dau tien trong mang la: %d\n", q);
    }

    int s = soGanh(a,n);
    if (s == -1) {
        printf("Khong co so ganh trong mang\n");
    } else {
        printf("So ganh dau tien trong mang la: %d\n", s);
    }

    int z = chuSoLeDauTien(a,n);
    if (z == 0) {
        printf("Khong co so thoa chua so dau tien la so le trong mang\n");
    } else {
        printf("So ma chu so dau tien la chu so le trong mang la: %d\n", z);
    }

    int g = giaTriDang2k(a,n);
    if (g == 0) {
        printf("Khong co so dang 2^k trong mang\n");
    } else {
        printf("So co dang 2^k trong mang la: %d\n", g);
    }
    return 0;
}