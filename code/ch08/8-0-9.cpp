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
    printf("((%.2lf, %.2lf), %.2lf)", dt.O.x,dt.O.y,dt.r);
}   

int main() {
    DuongTron dt;

    nhapDuongTron(dt);
    xuatDuongTron(dt);

    return 0;
}