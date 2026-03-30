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
    printf("(%.2lf, %.2lf)\n", ps.x, ps.y);
}   

Diem timDiemDoiXungQuaDuongPhanGiacThu2(Diem d) {
    Diem d1;
    d1.x = -d.y;
    d1.y = -d.x;
    return d1;
}

int main() {
    Diem d;

    nhap(d);
    xuat(d);

    Diem d1 = timDiemDoiXungQuaDuongPhanGiacThu2(d);
    printf("Toa do diem doi xung qua duong phan giac thu hai y = -x la: ");
    xuat(d1);
    return 0;
}