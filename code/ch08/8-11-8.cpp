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

int ngayTrongNam(int nam) {
    if (checkNamNhuan(nam)) {
        return 366;
    }
    return 365;
}

Date timNgay(long long soThuTuNgay) {
    Date ngay;
    int thang = 1, nam = 1;
    while (soThuTuNgay > ngayTrongNam(nam)) {
        soThuTuNgay = soThuTuNgay - ngayTrongNam(nam);
        nam++;
    }

    while (soThuTuNgay > ngayTrongThang(thang, nam)) {
        soThuTuNgay = soThuTuNgay - ngayTrongThang(thang,nam);
        thang++;
    }
    ngay.ng = soThuTuNgay;
    ngay.th = thang;
    ngay.n = nam;
    return ngay;
}

int main() {
    long long soThuTuNgay;
    do {
        printf("Nhap so thu tu ngay ke tu ngay 1/1/1: ");
        scanf("%d", &soThuTuNgay);
        if (soThuTuNgay < 1) {
            printf("So thu tu ngay khong hop le! Xin nhap lai!\n");
        }
    } while(soThuTuNgay < 1);

    Date ngay = timNgay(soThuTuNgay);

    printf("Ngay thu %d ke tu ngay 1/1/1 la ngay: ", soThuTuNgay);
    xuat(ngay);

    return 0;
}