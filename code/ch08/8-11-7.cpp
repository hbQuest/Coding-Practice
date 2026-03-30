#include <stdio.h>

struct Date {
    int ng, th, n;
};

bool checkNamNhuan(int nam) {
    if (nam % 400 == 0 || (nam%4 == 0 && nam%100 != 0)) {
        return true;
    }
    return false;
}

int ngayTrongThang(int thang, int nam) {
    switch (thang) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return checkNamNhuan(nam) ? 29 : 28;
        default:    
            return 0; 
    }
}

void xuat(Date ngay) {
    printf("%d/%d/%d\n", ngay.ng, ngay.th,ngay.n);
}

Date timNgay(int nam,int soThuTuNgay) {
    Date ngay;
    int thang = 1;
    while (soThuTuNgay > ngayTrongThang(thang, nam)) {
        soThuTuNgay = soThuTuNgay - ngayTrongThang(thang, nam);
        thang++;
    }
    ngay.ng = soThuTuNgay;
    ngay.th = thang;
    ngay.n = nam;
    return ngay;
}

int main() {
    int nam, soThuTuNgay;
    do {
        printf("Nhap nam: ");
        scanf("%d", &nam);
        if (nam < 0) {
            printf("Nam khong hop le! Xin nhap lai!\n");
        }
    } while(nam < 0);
    do {
        printf("Nhap so thu tu ngay trong nam %d: ", nam);
        scanf("%d", &soThuTuNgay);
        if (soThuTuNgay < 1 || soThuTuNgay > 366) {
            printf("So thu tu ngay khong hop le! Xin nhap lai!\n");
        }
    } while(soThuTuNgay < 1 || soThuTuNgay > 366);

    Date ngay = timNgay(nam, soThuTuNgay);

    printf("Ngay thu %d trong nam %d la ngay: ", soThuTuNgay, nam);
    xuat(ngay);

    return 0;
}