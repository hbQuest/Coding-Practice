#include <stdio.h>
#include <math.h>

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

double tinhGiaTriDonThuc(DonThuc d, double x) {
    double s = d.a * pow(x, d.n);
    return s;
}

int main() {
    DonThuc d;

    printf("Nhap don thuc:\n");
    nhap(d);
    xuat(d);

    double x;
    printf("Nhap gia tri x = ");
    scanf("%lf", &x);
    double s = tinhGiaTriDonThuc(d,x);
    printf("Gia tri don thuc tai x = %.2lf la: %.2lf", x, s);

    return 0;
}