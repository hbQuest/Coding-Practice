#include <stdio.h>
#include <math.h>

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

int tinhThuCTZeller(Date ngay) {
    if (ngay.th < 3) {
        ngay.th += 12;
        ngay.n -=1;
    }

    int k = ngay.n % 100;
    int j = ngay.n / 100;

     // Công thức Zeller
    int h = (ngay.ng + 13*(ngay.th + 1)/5 + k + k/4 +j/4 + 5*j) % 7;

    return h;
}

int tinhThuCTSakamoto(Date ngay) {
    // Mảng bù cho từng tháng (từ tháng 1 đến tháng 12)
    static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    
    // Nếu là tháng 1 hoặc 2, ta coi nó thuộc về năm trước đó
    if (ngay.th < 3) {
        ngay.n -= 1;
    }
    
    // Công thức Sakamoto
    return (ngay.n + ngay.n/4 - ngay.n/100 + ngay.n/400 + t[ngay.th-1] + ngay.ng) % 7;
}

void timThu(Date ngay) {
    // int n = tinhThuCTZeller(ngay);
    int n = tinhThuCTSakamoto(ngay);
    
    printf("Ngay ");
    xuat(ngay);
    printf(" la ngay: ");
    // Dùng cho công thức Zeller
    // switch (n) {
    //     case 0: printf("Thu bay"); break;
    //     case 1: printf("Chu nhat"); break;
    //     case 2: printf("Thu hai"); break;
    //     case 3: printf("Thu ba"); break;
    //     case 4: printf("Thu tu"); break;
    //     case 5: printf("Thu nam"); break;
    //     case 6: printf("Thu sau"); break;
    // }
    // Dùng cho công thức Sakamoto
    switch (n) {
        case 0: printf("Chu nhat"); break;
        case 1: printf("Thu hai"); break;
        case 2: printf("Thu ba"); break;
        case 3: printf("Thu tu"); break;
        case 4: printf("Thu nam"); break;
        case 5: printf("Thu sau"); break;
        case 6: printf("Thu bay"); break;
    }
}

int main() {
    Date ngay;

    nhap(ngay);

    timThu(ngay);
    return 0;
}