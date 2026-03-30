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

int BCNN(int a, int b) {
    return (a*b) / UCLN(a,b);
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

PhanSo hieu2PhanSo(PhanSo ps1, PhanSo ps2) {
    PhanSo ps3;
    int mauSoChung = BCNN(abs(ps1.mauSo),abs(ps2.mauSo));
    ps3.tuSo = (ps1.tuSo * (mauSoChung/ps1.mauSo)) - (ps2.tuSo * (mauSoChung/ps2.mauSo));
    ps3.mauSo = mauSoChung;
    return ps3;
}
int main() {
    PhanSo ps1;
    PhanSo ps2;

    nhapPhanSo(ps1);
    xuatPhanSo(ps1);
    nhapPhanSo(ps2);
    xuatPhanSo(ps2);
    
    PhanSo ps3 = hieu2PhanSo(ps1,ps2);
    printf("Hieu 2 phan so sau khi rut gon phan so: ");
    rutGonPhanSo(ps3);
    xuatPhanSo(ps3);
    return 0;
}