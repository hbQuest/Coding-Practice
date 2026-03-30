#include <stdio.h>

struct Diem {
    double x, y;
};

void nhap(Diem &ps) {
    printf("Nhap x: ");
    scanf("%lf", &ps.x);
    printf("Nhap y: ");
    scanf("%lf", &ps.y);
}
    
void xuat(Diem ps) {
    printf("(%.2lf, %.2lf)", ps.x, ps.y);
}   

int main() {
    Diem d;

    nhap(d);
    xuat(d);

    return 0;
}