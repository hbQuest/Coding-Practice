#include <stdio.h>
#include <string.h>

struct Time {
    int h,m,s;
};

struct Date {
    int ng,th,n;
};

struct Ve {
    char tenPhim[21];
    int giaTien;
    Time xuatChieu;
    Date ngayXem;
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

void nhapThoiGian(Time& t) {
    do {
        printf("Nhap gio: ");
        scanf("%d", &t.h);
        if (t.h < 0 || t.h > 24) {
            printf("Gio khong hop le! Xin nhap lai!\n");
        }
    } while (t.h < 0 || t.h > 24);
    do {
       printf("Nhap phut: ");
        scanf("%d", &t.m);
        if (t.m < 0 || t.m > 60) {
            printf("Phut khong hop le! Xin nhap lai!\n");
        }
    } while (t.m < 0 || t.m > 60);
    do {
        printf("Nhap giay: ");
        scanf("%d", &t.s);
        if (t.s < 0 || t.s > 60) {
            printf("Giay khong hop le! Xin nhap lai!\n");
        }
    } while (t.s < 0 || t.s > 60);
}

void xuatThoiGian(Time t) {
    printf("%d:%d:%d\n", t.h,t.m,t.s);
}

void nhapThongTin(Ve& v) {
    printf("Nhap ten phim (viet lien duoi 20 ky tu): ");
    scanf("%s", v.tenPhim);
    printf("Nhap gia tien (VND): ");
    scanf("%d", &v.giaTien);
    printf("Nhap xuat chieu\n");
    nhapThoiGian(v.xuatChieu);
    printf("Nhap ngay xem\n");
    nhapNgay(v.ngayXem);
}
void xuatThongTin(Ve v) {
    printf("Thong tin ve xem phim\n");
    printf("Tem phim: %s\n", v.tenPhim);
    printf("Gia tien (VND): %.d\n", v.giaTien);
    printf("Xuat chieu: ");
    xuatThoiGian(v.xuatChieu);
    printf("Ngay xem: ");
    xuatNgay(v.ngayXem);
}

int main() {
    Ve v;

    nhapThongTin(v);
    xuatThongTin(v);

    return 0;
}