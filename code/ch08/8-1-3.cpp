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

DonThuc thuong2DonThuc(DonThuc d1, DonThuc d2) {
    DonThuc d3;
    d3.a = d1.a / d2.a;
    d3.n = d1.n - d2.n;
    return d3;
}

int main() {
    DonThuc d1;
    DonThuc d2;

    printf("Nhap don thuc 1:\n");
    nhap(d1);
    xuat(d1);
    printf("Nhap don thuc 2:\n");
    nhap(d2);
    xuat(d2);

    printf("Thuong 2 don thuc la: ");
    DonThuc d3 = thuong2DonThuc(d1,d2);
    xuat(d3);

    return 0;
}