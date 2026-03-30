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

bool checkNgayHopLe(int ngay,int thang,int nam) {
    if (thang < 1 || thang > 12) return false;
    if (ngay < 1 || ngay > ngayTrongThang(thang, nam)) {
        return false;
    }
    return true;
}

void nhap(Date& ngay) {
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

void xuat(Date ngay) {
    printf("%d/%d/%d\n", ngay.ng, ngay.th,ngay.n);
}

int tinhSoThuTuNgayTrongNam(Date ngay) {
    int tong = 0;
    for (int i = 1; i < ngay.th; i++) {
        tong += ngayTrongThang(i, ngay.n);
    }
    tong += ngay.ng;
    return tong;
}


int main() {
    Date ngay;

    nhap(ngay);
    xuat(ngay);

    int n = tinhSoThuTuNgayTrongNam(ngay);
    printf("%d/%d/%d la ngay thu %d trong nam %d", ngay.ng, ngay.th, ngay.n , n, ngay.n);
    return 0;
}