#include <stdio.h>

struct Diem {
    double x,y;
};

struct DuongTron {
    Diem O;
    double r;
};

void nhapDiem(Diem &O) {
    printf("Nhap toa do x: ");
    scanf("%lf", &O.x);
    printf("Nhap toa do y: ");
    scanf("%lf", &O.y);
}

void nhapDuongTron(DuongTron &dt) {
    Diem I;
    nhapDiem(dt.O);
    printf("Nhap ban kinh r: ");
    scanf("%lf", &dt.r);
}
    
void xuatDuongTron(DuongTron dt) {
    printf("((%.2lf, %.2lf), %.2lf)\n", dt.O.x,dt.O.y,dt.r);
}   

double tinhDienTich(DuongTron dt) {
    double s = 3.14*dt.r*dt.r;
    return s;
}

double tinhChuVi(DuongTron dt) {
    double p = 2*3.14*dt.r;
    return p;
}

int main() {
    DuongTron dt;

    nhapDuongTron(dt);
    xuatDuongTron(dt);

    double s = tinhDienTich(dt);
    double p = tinhChuVi(dt);

    printf("Dien tich duong tron la: %.2lf\n", s);
    printf("Chu vi duong tron la: %.2lf", p);

    return 0;
}