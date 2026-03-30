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

Diem timDiemDoiXungQuaGocToaDo(Diem d) {
    Diem d1;
    if (d.x != 0 && d.y != 0) {
        d1.x = -d.x;
        d1.y = -d.y;
    } else if (d.x == 0) {
        d1.x = 0;
        d1.y = -d.y;
    } else if (d.y == 0) {
        d1.y = 0;
        d1.x = -d.x;
    }
    return d1;
}

int main() {
    Diem d;

    nhap(d);
    xuat(d);

    Diem d1 = timDiemDoiXungQuaGocToaDo(d);
    printf("Toa do diem doi xung qua goc toa do cua diem d la: ");
    xuat(d1);
    return 0;
}