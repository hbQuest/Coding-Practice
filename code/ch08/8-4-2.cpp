#include <stdio.h>
#include <math.h>

struct HonSo {
    int phanNguyen, tuSo, mauSo;
};

void nhapHonSo(HonSo &hs) {
    printf("Nhap phan nguyen: ");
    scanf("%d", &hs.phanNguyen);

    do {
        printf("Nhap tu so: ");
        scanf("%d", &hs.tuSo);
        if (hs.tuSo < 0) {
            printf("Tu so phai >= 0! Xin nhap lai!\n");
        }
    } while (hs.tuSo < 0);

    do {
        printf("Nhap mau so: ");
        scanf("%d", &hs.mauSo);
        if (hs.mauSo == 0) {
            printf("Mau so phai khac 0! Xin nhap lai!\n");
        }
    } while (hs.mauSo == 0);
}

int UCLN(int a, int b) {
    int min = (a > b ? b : a);
    for (int i = min; i > 1; i--) {
        if (a%i == 0 && b%i == 0) {
            return i;
        }
    }
    return 1;
}
    
void xuLyHonSo(HonSo &hs) {
    int ucln = UCLN(hs.tuSo, hs.mauSo);
    hs.tuSo /= ucln;
    hs.mauSo /= ucln;
    if (hs.tuSo >= hs.mauSo) {
        int tangThem = hs.tuSo / hs.mauSo;
        hs.tuSo = hs.tuSo % hs.mauSo;
        if (hs.phanNguyen >= 0) {
            hs.phanNguyen += tangThem;
        } else {
            hs.phanNguyen -= tangThem;
        }
    }
}

void xuatHonSo(HonSo hs) {
    xuLyHonSo(hs);
    if (hs.tuSo == 0) {
        printf("%d", hs.phanNguyen);
    } else {
        printf("%d(%d/%d)", hs.phanNguyen, hs.tuSo, hs.mauSo);
    }
}

int main() {
    HonSo hs;

    nhapHonSo(hs);
    xuatHonSo(hs);

    return 0;
}