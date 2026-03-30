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

int tinhTongNgay(int ngay,int thang,int nam) {
    int tongNgay = 0;
    for (int i = thang-1; i >= 1; i--) {
        if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) {
            tongNgay += 31;
        } else if (i == 2) {
            if (checkNamNhuan(nam)) {
                tongNgay += 29;
            } else {
                tongNgay += 28;
            }
        } else {
            tongNgay += 30;
        }
    }
    tongNgay += ngay;
    return tongNgay;
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

    int tongNgay = tinhTongNgay(ngay, thang, nam);
    printf("Ngay %d thang %d nam %d la ngay thu %d trong nam", ngay, thang, nam, tongNgay);

    return 0;
}