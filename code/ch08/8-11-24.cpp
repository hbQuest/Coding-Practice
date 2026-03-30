#include <stdio.h>
#define MAXTEN 31
#define MAXTENLUANVAN 101
#define MAXMA 11

struct LuanVan {
    char maLuanVan[MAXMA];
    char tenLuanVan[MAXTEN];
    char tenSinhVien[MAXTEN];
    char tenGiangVien[MAXTEN];
    unsigned namThucHien;
};

void nhapThongTin(LuanVan& h) {
    printf("Nhap ma luan van (viet lien toi da 10 ky tu): ");
    scanf("%s", h.maLuanVan);
    printf("Nhap ten luan van (viet lien toi da 100 ky tu): ");
    scanf("%s", h.tenLuanVan);
    printf("Nhap ten sinh vien (viet lien toi da 30 ky tu): ");
    scanf("%s", h.tenSinhVien);
    printf("Nhap ten giang vien huong dan (viet lien toi da 30 ky tu): ");
    scanf("%s", h.tenGiangVien);
    printf("Nhap nam thuc hien: ");
    scanf("%u", &h.namThucHien);
}

void xuatThongTin(LuanVan h) {
    printf("Thong tin luan van\n");
    printf("Ma luan van: %s\n", h.maLuanVan);
    printf("Ten luan van: %s\n", h.tenLuanVan);
    printf("Ten sinh vien thuc hien: %s\n", h.tenSinhVien);
    printf("Ten giang vien huong dan: %s\n", h.tenGiangVien);
    printf("Nam thuc hien: %u\n", h.namThucHien);
}

int main() {
    LuanVan h;

    nhapThongTin(h);
    xuatThongTin(h);

    return 0;
}