#include <stdio.h>
#include <string.h>

struct CauThu {
    char ten[31];
};

struct DoiBong {
    char maDoiBong[6];
    char tenDoiBong[31];
    CauThu cauthu[30];
    int soLuongCauThu;
};

int nhapCauThu(CauThu c[]) {
    printf("Nhap ten cau thu viet lien toi da 30 ky tu. Nhap 0 de ngung nhap\n");
    int i;
    for (i = 0; i < 30; i++) {
        printf("Nhap ten cau thu %d: ", i+1);
        char temp[31];
        scanf("%s", temp);
        if (stricmp(temp, "0") == 0) {
            break;
        } 
        strcpy(c[i].ten,temp);
    }
    return i;
}

void xuatCauThu(CauThu c[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Cau thu %d: %s\n", i+1, c[i].ten);
    }
}

void nhapThongTin(DoiBong& d) {
    printf("Nhap ma doi bong (viet lien toi da 6 ky tu): ");
    scanf("%s", d.maDoiBong);
    printf("Nhap ten doi bong (viet lien toi da 30 ky tu): ");
    scanf("%s", d.tenDoiBong);
    printf("Nhap danh sach cac cau thu\n");
    d.soLuongCauThu = nhapCauThu(d.cauthu);
}

void xuatThongTin(DoiBong d) {
    printf("Thong tin doi bong\n");
    printf("Ma doi bong: %s\n", d.maDoiBong);
    printf("Ten doi bong: %s\n", d.tenDoiBong);
    printf("Danh sach cac cau thu\n");
    xuatCauThu(d.cauthu, d.soLuongCauThu);
}

int main() {
    DoiBong d;

    nhapThongTin(d);
    xuatThongTin(d);

    return 0;
}