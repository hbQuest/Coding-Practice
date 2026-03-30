#include <stdio.h>

struct PTDuongThang {
    double a,b,c;
};

void nhap(PTDuongThang &d) {
    printf("Nhap a: ");
    scanf("%lf", &d.a);
    printf("Nhap b: ");
    scanf("%lf", &d.b);
    printf("Nhap c: ");
    scanf("%lf", &d.c);
}
    
void xuat(PTDuongThang d) {
    printf("%.2lfx + %.2lfy + %.2lf = 0", d.a,d.b,d.c);
}   

int main() {
    PTDuongThang d;

    nhap(d);
    xuat(d);

    return 0;
}