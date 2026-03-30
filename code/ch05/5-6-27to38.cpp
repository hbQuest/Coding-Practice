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

// 5.6.30
bool kiemTraMangDoiXung(int a[], int n) {
    for (int i = 0; i < n/2; i++) {
        if (a[i] != a[n-1-i]) {
            return false;
        }
    }
    return true;
}

// 5.6.31
bool kiemTraMangCoTinhChatLe(int a[], int n) {
    for (int i = 0; i < n-1; i++) {
        if ((a[i] + a[i+1])%2 == 0) {
            return false;
        }
    }
    return true;
}

// 5.6.34
bool kiemTraCapSoCong(int a[], int n, int &d) {
    if (n <= 1) {
        return false;
    }
    d = a[1] - a[0];
    for (int i = 1; i < n-1; i++) {
        if ((a[i+1] - a[i]) != d) {
            return false;
        }
    }
    return true;
} 

// 5.6.36
bool kiemTraMangDangSong(int a[], int n) {
    if (n < 3) { return false; }
    bool flag = false;
    for (int i = 1; i < n-1; i++) {
        if ((a[i] > a[i-1] && a[i] > a[i+1]) || (a[i] < a[i-1] && a[i] < a[i+1])) {
            flag = true;
        }
        if (!flag) { return false; }
    }
    return flag;
}

// 5.6.37
bool kiemTraMangATrongMangB(int a[], int b[], int n, int m) {
    if (n > m) {return false;}
    for (int i = 0; i < m; i++) {
        if (a[0] == b[i]) {
            bool flag = true;
            for (int j = 0; j < n; j++) {
                if (a[j] != b[j+i]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {return true;}
        }
    }
    return false;
}

// 5.6.38
int demGiaTriLonHonMoiGiaTriTruoc(int a[], int n) {
    int dem = 0;
    for (int i = 0; i < n; i++) {
        bool lonHon = true;
        for (int j = 0; j < i; j++) {
            if (a[i] < a[j]) {
                lonHon = false;
                break;
            }
        }
        if (lonHon) {
            dem++;
        }
    }
    return dem;
}
int main() {
    int a[100];
    int n;

    nhapMang(a, n);
    xuatMang(a, n);

    bool doiXung = kiemTraMangDoiXung(a,n);
    if (doiXung) {
        printf("Mang co doi xung\n");
    } else {
        printf("Mang khong doi xung\n");
    }

    bool tinhChatLe = kiemTraMangCoTinhChatLe(a,n);
    if (tinhChatLe) {
        printf("Mang co tinh chat le\n");
    } else {
        printf("Mang khong co tinh chat le\n");
    }

    int d=0;
    bool capSoCong = kiemTraCapSoCong(a,n,d);
    if (capSoCong) {
        printf("Cac phan tu lap thanh cap so cong co cong sai d = %d\n", d);
    } else {
        printf("Mang khong lap thanh cap so cong\n");
    }

    int dangSong = kiemTraMangDangSong(a,n);
    if (dangSong) {
        printf("Mang co dang song\n");
    } else {
        printf("Mang khong co dang song\n");
    }

    // int b[100], m;
    // nhapMang(b, n);
    // xuatMang(b, n);
    // int aTrongB = kiemTraMangATrongMangB(a,b,n,m);
    // if (aTrongB) {
    //     printf("Mang a co nam trong mang b\n");
    // } else {
    //     printf("Mang a khong nam trong mang b\n");
    // }

    int dem = demGiaTriLonHonMoiGiaTriTruoc(a,n);
    printf("So gia tri lon hon moi gia tri truoc do la %d", dem);
    return 0;
}