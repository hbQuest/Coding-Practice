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

SoPhuc tich2SoPhuc(SoPhuc sp1, SoPhuc sp2) {
    SoPhuc sp3;
    sp3.phanThuc = (sp1.phanThuc * sp2.phanThuc) - (sp1.phanAo * sp2.phanAo);
    sp3.phanAo = (sp1.phanThuc * sp2.phanAo) + (sp2.phanThuc * sp1.phanAo);
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

    printf("Tich 2 so phuc la: ");
    SoPhuc sp3 = tich2SoPhuc(sp1,sp2);
    xuatSoPhuc(sp3);
    return 0;
}