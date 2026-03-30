#include <stdio.h>
#include <string.h>

struct Date {
    int ng,th,n;
};

struct HopSua {
    char nhanHieu[21];
    double trongLuong;
    Date hanSuDung;
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

bool checkNgayHopLe(int ngay,int thang,int nam) {
    if (thang < 1 || thang > 12) return false;
    if (ngay < 1 || ngay > ngayTrongThang(thang, nam)) {
        return false;
    }
    return true;
}

void nhapNgay(Date& ngay) {
    do {
        printf("Nhap nam: ");
        scanf("%d", &ngay.n);
        if (ngay.n < 1) {
            printf("Nam khong hop le! Xin nhap lai!\n");
        }
    } while(ngay.n < 1);
    
    do {
        printf("Nhap thang: ");
        scanf("%d", &ngay.th);
        if (ngay.th < 1 || ngay.th > 12) {
            printf("Thang khong hop le! Xin nhap lai!\n");
        }
    } while(ngay.th < 1 || ngay.th > 12);
    
    do {
        printf("Nhap ngay: ");
        scanf("%d", &ngay.ng);
        if (!checkNgayHopLe(ngay.ng, ngay.th, ngay.n)) {
            printf("Ngay khong hop le! Xin nhap lai!\n");
        }
    } while(!checkNgayHopLe(ngay.ng, ngay.th, ngay.n));
    
}

void xuatNgay(Date ngay) {
    printf("%d/%d/%d\n", ngay.ng, ngay.th,ngay.n);
}

void nhapThongTin(HopSua& h) {
    printf("Nhap nhan hieu: ");
    scanf("%s", h.nhanHieu);
    printf("Nhap trong luong (gram): ");
    scanf("%lf", &h.trongLuong);
    printf("Nhap han su dung\n");
    nhapNgay(h.hanSuDung);
}
void xuatThongTin(HopSua h) {
    printf("Thong tin hop sua\n");
    printf("Nhan hieu: %s\n", h.nhanHieu);
    printf("Trong luong (gram): %.2lf\n", h.trongLuong);
    printf("Han su dung: ");
    xuatNgay(h.hanSuDung);
}

int main() {
    HopSua h;

    nhapThongTin(h);
    xuatThongTin(h);

    return 0;
}