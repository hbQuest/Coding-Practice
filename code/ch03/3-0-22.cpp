#include <stdio.h>
#include <math.h>

bool checkNamNhuan(int nam) {
    if (nam%400 == 0 || (nam%4 == 0 && nam%100 != 0)) {
        return true;
    } else {
        return false;
    }
}

bool checkNgayHopLe(int ngay, int thang, int nam) {
    if (thang == 1 || thang == 3 || thang == 5 || thang == 7 || thang == 8 || thang == 10 || thang == 12) {
        if (ngay < 0 || ngay > 31) {
            return false;
        }
    } else if (thang == 2) {
        if (checkNamNhuan(nam)) {
            if (ngay < 0 || ngay > 29) {
                return false;
            }
        } else {
            if (ngay < 0 || ngay > 28) {
                return false;
            }
        }
    } else {
        if (ngay < 0 || ngay > 30) {
            return false;
        }
    }
    return true;
}

void timNgayTruoc(int ngay,int thang,int nam) {
    int ng, th, n;
    if (ngay == 1 && thang == 1) {
        n = nam - 1;
        th = 12;
        ng = 31;
    } else if (ngay == 1 && thang != 1) {
        th = thang - 1;
        if (th == 1 || th == 3 || th == 5 || th == 7 || th == 8 || th == 10 || th == 12) {
            ng = 31;
        } else if (th == 2) {
            if (checkNamNhuan(nam)) {
                ng = 29;
            } else {
                ng = 28;
            }
        } else {
            ng = 30;
        }
        n = nam;
    }  else {
        n = nam;
        th = thang;
        ng = ngay - 1;
    }
    
    printf("Ngay truoc ngay %d thang %d nam %d la ngay %d thang %d nam %d", ngay, thang, nam, ng, th, n);
}

int main() {
    int ngay, thang, nam;
    
    do {
        printf("Nhap nam: ");
        scanf("%d", &nam);
        if (nam < 0) {
            printf("Nam khong hop le! Xin nhap lai!\n");
        }
    } while (nam < 0);

    do {
        printf("Nhap thang: ");
        scanf("%d", &thang);
        if (thang < 0 || thang > 12) {
            printf("Thang khong hop le! Xin nhap lai!\n");
        }
    } while (thang < 0 || thang > 12);

    do {
        printf("Nhap ngay: ");
        scanf("%d", &ngay);
        if (!checkNgayHopLe(ngay, thang, nam)) {
            printf("Ngay khong hop le! Xin nhap lai!\n");
        }
    } while (!checkNgayHopLe(ngay, thang, nam));

    timNgayTruoc(ngay, thang, nam);

    return 0;
}