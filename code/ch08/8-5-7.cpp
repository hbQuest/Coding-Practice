#include <stdio.h>
#include <math.h>

struct SoPhuc {
    double phanThuc, phanAo;
};

void nhapSoPhuc(SoPhuc &sp) {
    printf("Nhap phan thuc: ");
    scanf("%lf", &sp.phanThuc);
    printf("Nhap phan ao: ");
    scanf("%lf", &sp.phanAo);
}

void xuatSoPhuc(SoPhuc sp) {
    if (sp.phanAo < 0) {
        printf("%.2lf - %.2lfi\n", sp.phanThuc, abs(sp.phanAo));
    } else {
        printf("%.2lf + %.2lfi\n", sp.phanThuc, sp.phanAo);
    }
}

SoPhuc thuong2SoPhuc(SoPhuc sp1, SoPhuc sp2) {
    SoPhuc sp3;
    double trucCanThuc = sp2.phanThuc*sp2.phanThuc + sp2.phanAo * sp2.phanAo;
    sp3.phanThuc = ((sp1.phanThuc * sp2.phanThuc) + (sp1.phanAo * sp2.phanAo)) / trucCanThuc;
    sp3.phanAo = ((sp1.phanAo *sp2.phanThuc) - (sp1.phanThuc * sp2.phanAo)) / trucCanThuc;
    return sp3;
}

int main() {
    SoPhuc sp1;
    SoPhuc sp2;

    printf("Nhap so phuc 1:\n");
    nhapSoPhuc(sp1);
    xuatSoPhuc(sp1);
    printf("Nhap so phuc 2:\n");
    nhapSoPhuc(sp2);
    xuatSoPhuc(sp2);

    printf("Thuong 2 so phuc la: ");
    SoPhuc sp3 = thuong2SoPhuc(sp1,sp2);
    xuatSoPhuc(sp3);
    return 0;
}