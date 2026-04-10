#include <stdio.h>

struct Ngay {
    int ngay, thang, nam;
};
bool KiemTraNamNhuan(int n) {
    if (n%400 == 0 || (n%4 == 0 && n%100 != 0)) {
        return true;
    }
    return false;
}

bool KiemTraNgayHopLe(int n, int t, int ng) {
    if (t == 1 || t == 3 || t == 5 || t == 8 || t == 10 || t == 12) {
        if (ng < 0 || ng > 31) {
            return false;
        }
    } else if (KiemTraNamNhuan(n) && t == 2) {
        if (ng < 0 || ng > 29) {
            return false;
        }
    } else if (t == 2) {
        if (ng < 0 || ng > 28) {
            return false;
        }
    } else {
        if (ng < 0 || ng > 30) {
            return false;
        }
    }
    return true;
}

void nhap(Ngay &n) {
    do {
        printf("Nhap nam: ");
        scanf("%d", &n.nam);
        if (n.nam < 0 || n.nam > 2026) {
            printf("Nam khong hop le! Xin nhap lai!\n");
        }
    } while (n.nam < 0 || n.nam > 2026);
    do {
        printf("Nhap thang: ");
        scanf("%d", &n.thang);
        if (n.thang < 0 || n.thang > 12) {
            printf("Thang khong hop le! Xin nhap lai!\n");
        }
    } while (n.thang < 0 || n.thang > 12);
    
    do {
        printf("Nhap ngay: ");
        scanf("%d", &n.ngay);
        if (!KiemTraNgayHopLe(n.nam,n.thang,n.ngay)) {
            printf("Ngay khong hop le! Xin nhap lai!\n");
        }

    } while (!KiemTraNgayHopLe(n.nam,n.thang,n.ngay));
}
    
void xuat(Ngay n) {
    printf("%d-%d-%d", n.ngay, n.thang, n.nam);
}   

int main() {
    Ngay n;

    nhap(n);
    xuat(n);

    return 0;
}

