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
    printf("%d/%d/%d", ngay.ng, ngay.th,ngay.n);
}

Date timNgayHomQua(Date ngay) {
    if (ngay.th == 1 && ngay.ng == 1) {
        ngay.n--;
        ngay.th = 12;
        ngay.ng = 31;
    } else if (ngay.ng == 1) {
        ngay.th--;
        ngay.ng = ngayTrongThang(ngay.th, ngay.n);
    } else {
        ngay.ng--;
    }
    return ngay;
}

Date timKNgayTruocDo(Date ngay, int k) {
    for (int i = 1; i <= k; i++) {
        ngay = timNgayHomQua(ngay);
    }
    return ngay;
}

int main() {
    Date ngay;
    int k;
    nhap(ngay);
    do {
        printf("Nhap k ngay truoc do: ");
        scanf("%d", &k);
        if (k < 0) {
            printf("So ngay khong hop le! Xin nhap lai!\n");
        }
    } while(k < 0);

    Date ngayTruoc = timKNgayTruocDo(ngay, k);
    xuat(ngayTruoc);
    printf(" la ngay truoc do %d ngay cua ngay ", k);
    xuat(ngay);
    return 0;
}