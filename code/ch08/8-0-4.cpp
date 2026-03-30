#include <stdio.h>

struct Diem {
    double x, y, z;
};

void nhap(Diem &ps) {
    printf("Nhap x: ");
    scanf("%lf", &ps.x);
    printf("Nhap y: ");
    scanf("%lf", &ps.y);
    printf("Nhap z: ");
    scanf("%lf", &ps.z);
}
    
void xuat(Diem ps) {
    printf("(%.2lf, %.2lf, %.2lf)", ps.x, ps.y, ps.z);
}   

int main() {
    Diem d;

    nhap(d);
    xuat(d);

    return 0;
}