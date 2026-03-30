#include <stdio.h>

struct Diem {
    double x, y;
};

void nhapToaDo(Diem &ps) {
    printf("Nhap x: ");
    scanf("%lf", &ps.x);
    printf("Nhap y: ");
    scanf("%lf", &ps.y);
}
    
void xuatToaDo(Diem ps) {
    printf("(%.2lf, %.2lf)", ps.x, ps.y);
}   

int main() {
    Diem d;

    nhapToaDo(d);
    xuatToaDo(d);

    return 0;
}