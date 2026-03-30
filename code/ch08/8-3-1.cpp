#include <stdio.h>
#include <math.h>

struct PhanSo {
    int tuSo, mauSo;
};

void nhapPhanSo(PhanSo &ps) {
    printf("Nhap tu so: ");
    scanf("%d", &ps.tuSo);

    do {
        printf("Nhap mau so: ");
        scanf("%d", &ps.mauSo);
        if (ps.mauSo == 0) {
            printf("Mau so phai khac 0! Xin nhap lai!\n");
        }
    } while (ps.mauSo == 0);
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
    
void rutGonPhanSo(PhanSo &ps) {
    int a = UCLN(abs(ps.tuSo), abs(ps.mauSo));
    ps.tuSo /= a;
    ps.mauSo /= a;
    if (ps.tuSo < 0 && ps.mauSo < 0) {
        ps.tuSo = -ps.tuSo;
        ps.mauSo = -ps.mauSo;
    } else if (ps.tuSo > 0 && ps.mauSo < 0) {
        ps.tuSo = -ps.tuSo;
        ps.mauSo = -ps.mauSo;
    }
}

void xuatPhanSo(PhanSo ps) {
    printf("%d/%d\n", ps.tuSo, ps.mauSo);
}   

int main() {
    PhanSo ps;

    nhapPhanSo(ps);
    printf("Phan so truoc khi rut gon phan so: ");
    xuatPhanSo(ps);
    printf("Phan so sau khi rut gon phan so: ");
    rutGonPhanSo(ps);
    xuatPhanSo(ps);
    return 0;
}