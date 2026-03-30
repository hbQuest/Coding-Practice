#include <stdio.h>
#define MAXTEN 31

struct hocSinh {
    char tenHocSinh[MAXTEN];
    unsigned diemToan, diemVan;
    double diemTrungBinh;
};

void nhapThongTin(hocSinh& h) {
    printf("Nhap ten hoc sinh (viet lien toi da 30 ky tu): ");
    scanf("%s", h.tenHocSinh);
    printf("Nhap diem toan: ");
    scanf("%u", &h.diemToan);
    printf("Nhap diem van: ");
    scanf("%u", &h.diemVan);
    h.diemTrungBinh = (h.diemToan + h.diemVan)*1.0 / 2;
}

void xuatThongTin(hocSinh h) {
    printf("Thong tin diem hoc sinh\n");
    printf("Ten hoc sinh: %s\n", h.tenHocSinh);
    printf("Diem toan: %u\n", h.diemToan);
    printf("Diem van: %u\n", h.diemVan);
    printf("Diem trung binh: %.2lf\n", h.diemTrungBinh);
}

int main() {
    hocSinh h;

    nhapThongTin(h);
    xuatThongTin(h);

    return 0;
}