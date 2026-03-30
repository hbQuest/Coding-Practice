#include <stdio.h>

struct DonThuc {
    double a;
    int n;
};

void nhap(DonThuc &dt) {
    printf("Nhap co so a: ");
    scanf("%lf", &dt.a);
    printf("Nhap so mu: ");
    scanf("%d", &dt.n);
}
    
void xuat(DonThuc dt) {
    printf("%.2lfx^%d\n", dt.a, dt.n);
}   

DonThuc daoHamCap1(DonThuc d) {
    DonThuc d3;
    d3.a = d.a * d.n;
    d3.n = d.n - 1;
    return d3;
}

int main() {
    DonThuc d;

    printf("Nhap don thuc:\n");
    nhap(d);
    xuat(d);

    printf("Dao ham cap 1: ");
    DonThuc d3 = daoHamCap1(d);
    xuat(d3);

    return 0;
}