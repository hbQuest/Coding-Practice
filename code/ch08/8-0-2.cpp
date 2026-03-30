#include <stdio.h>

struct HonSo {
    int soNguyen, tuSo, mauSo;

};

void nhap(HonSo &hs) {
    printf("Nhap so nguyen: ");
    scanf("%d", &hs.soNguyen);
    printf("Nhap tu so: ");
    scanf("%d", &hs.tuSo);

    do {
        printf("Nhap mau so: ");
        scanf("%d", &hs.mauSo);
        if (hs.mauSo == 0) {
            printf("Mau so khong the bang 0! Xin nhap lai!\n");
        }
    } while (hs.mauSo == 0);
}

void xuat(HonSo hs) {
    printf("%d(%d/%d)", hs.soNguyen, hs.tuSo, hs.mauSo);
}

int main() {
    HonSo hs;

    nhap(hs);
    xuat(hs);

    return 0;
}