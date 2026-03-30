#include <stdio.h>
#include <math.h>

bool checkNamNhuan(int nam) {
    if (nam%400 == 0 || (nam%4 == 0 && nam%100 != 0)) {
        return true;
    } else {
        return false;
    }
}

int tinhNgay(int thang, int nam) {
    if (thang == 1 || thang == 3 || thang == 5 || thang == 7 || thang == 8 || thang == 10 || thang == 12) {
        return 31;
    } else if (thang == 2) {
        if (checkNamNhuan(nam)) {
            return 29;
        } else {
            return 28;
        }
    } else {
        return 30;
    }
}

int main() {
    int thang, nam;
    
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

    int ngay = tinhNgay(thang, nam);
    printf("Thang %d nam %d co %d ngay", thang, nam, ngay);

    return 0;
}