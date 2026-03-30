#include <stdio.h>
#include <math.h>

struct HonSo {
    int phanNguyen, tuSo, mauSo;
};

struct PhanSo {
    int tuSo, mauSo;
};

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

PhanSo hieu2PhanSo(PhanSo ps1, PhanSo ps2) {
    PhanSo ps3;
    int mauSoChung = BCNN(abs(ps1.mauSo),abs(ps2.mauSo));
    ps3.tuSo = ps1.tuSo * (mauSoChung/ps1.mauSo) - ps2.tuSo * (mauSoChung/ps2.mauSo);
    ps3.mauSo = mauSoChung;
    rutGonPhanSo(ps3);
    return ps3;
}

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
        printf("%d\n", hs.phanNguyen);
    } else {
        printf("%d(%d/%d)\n", hs.phanNguyen, hs.tuSo, hs.mauSo);
    }
}

PhanSo honSoSangPhanSo(HonSo hs) {
    PhanSo ps;
    if (hs.phanNguyen >= 0) {
        ps.tuSo = (hs.mauSo * hs.phanNguyen) + hs.tuSo;
    } else {
        ps.tuSo = (hs.mauSo * hs.phanNguyen) - hs.tuSo;
    }
    ps.mauSo = hs.mauSo;
    return ps;
}

HonSo phanSoSangHonSo(PhanSo ps) {
    PhanSo temp;
    HonSo hs3;
    if (ps.tuSo < 0) {
        temp.tuSo = -ps.tuSo;
        temp.mauSo = ps.mauSo;
    } else {
        temp.tuSo = ps.tuSo;
        temp.mauSo = ps.mauSo;
    }
    if (temp.tuSo >= temp.mauSo) {
        hs3.tuSo = temp.tuSo % temp.mauSo;
        hs3.mauSo = temp.mauSo;
    } else {
        hs3.tuSo = temp.tuSo;
        hs3.mauSo = temp.mauSo;
    }
    if (ps.tuSo < 0) {
        hs3.phanNguyen = -(temp.tuSo / temp.mauSo);
    } else {
        hs3.phanNguyen = temp.tuSo / temp.mauSo;
    }
    return hs3;
}

HonSo hieu2HonSo(HonSo hs1, HonSo hs2) {
    PhanSo ps1 = honSoSangPhanSo(hs1);
    PhanSo ps2 = honSoSangPhanSo(hs2);
    ps1 = hieu2PhanSo(ps1, ps2);
    HonSo hs3 = phanSoSangHonSo(ps1);
    return hs3;
}

int main() {
    HonSo hs1;
    HonSo hs2;

    printf("Nhap hon so 1:\n");
    nhapHonSo(hs1);
    xuatHonSo(hs1);
    printf("Nhap hon so 2:\n");
    nhapHonSo(hs2);
    xuatHonSo(hs2);

    HonSo hs3 = hieu2HonSo(hs1, hs2);
    printf("Hieu 2 hon so la: ");
    xuatHonSo(hs3);
    return 0;
}