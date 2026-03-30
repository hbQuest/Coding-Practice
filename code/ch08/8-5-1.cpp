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

int main() {
    SoPhuc sp;

    printf("Nhap so phuc:\n");
    nhapSoPhuc(sp);
    xuatSoPhuc(sp);

    return 0;
}