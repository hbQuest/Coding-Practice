#include <stdio.h>
#include <math.h>

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
    printf("(%.2lf, %.2lf)\n", ps.x, ps.y);
}   

double tinhKhoangCach2Diem(Diem d1, Diem d2) {
    double d = sqrt((d2.x - d1.x)*(d2.x - d1.x) + (d2.y - d1.y)*(d2.y - d1.y));
    return d;
}

int main() {
    Diem d1;
    Diem d2;

    printf("Nhap toa do diem d1:\n");
    nhapToaDo(d1);
    xuatToaDo(d1);
    printf("Nhap toa do diem d2:\n");
    nhapToaDo(d2);
    xuatToaDo(d2);

    double d = tinhKhoangCach2Diem(d1,d2);
    printf("Khoang cach giua 2 diem la: %.2lf", d);

    return 0;
}