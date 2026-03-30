#include <stdio.h>

struct PhanSo {
    int tuSo, mauSo;
};

void nhap(PhanSo &ps) {
    printf("Nhap tu so: ");
    scanf("%d", &ps.tuSo);

    do {
        printf("Nhap mau so: ");
        scanf("%d", &ps.mauSo);
        if (ps.mauSo == 0) {
            printf("Mau so khong the bang 0! Xin nhap lai!\n");
        }
    } while (ps.mauSo == 0);
}
    
void xuat(PhanSo ps) {
    printf("%d/%d", ps.tuSo, ps.mauSo);
}   

int main() {
    PhanSo ps;

    nhap(ps);
    xuat(ps);

    return 0;
}