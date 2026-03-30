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
    printf("(%.2lfx^%d)", dt.a, dt.n);
}   

int main() {
    DonThuc dt;

    nhap(dt);
    xuat(dt);

    return 0;
}