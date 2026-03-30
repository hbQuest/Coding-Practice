#include <stdio.h>
#include <math.h>

struct Diem {
    double x,y;
};

struct TamGiac {
    Diem A;
    Diem B;
    Diem C;
};

void nhapDiem(Diem &O) {
    printf("Nhap x: ");
    scanf("%lf", &O.x);
    printf("Nhap y: ");
    scanf("%lf", &O.y);
}

void nhapTamGiac(TamGiac &tg) {
    printf("Nhap toa do diem A\n");
    nhapDiem(tg.A);
    printf("Nhap toa do diem B\n");
    nhapDiem(tg.B);
    printf("Nhap toa do diem C\n");
    nhapDiem(tg.C);
}

double tinhKhoangCach(Diem A, Diem B) {
    double d = sqrt((A.x-B.x)*(A.x-B.x) + (A.y-B.y)*(A.y-B.y));
    return d;
}

bool kiemTraTamGiac(TamGiac tg) {
    double a = tinhKhoangCach(tg.A,tg.B);
    double b = tinhKhoangCach(tg.B,tg.C);
    double c = tinhKhoangCach(tg.C,tg.A);

    if (a + b > c && a + c > b && b + c > a) {
        return true;
    }
    return false;
}

void xuatTamGiac(TamGiac tg) {
    printf("(%.2lf, %.2lf), (%.2lf, %.2lf), (%.2lf, %.2lf)\n", tg.A.x,tg.A.y,tg.B.x,tg.B.y,tg.C.x,tg.C.y);
}   


double tinhDienTich(TamGiac tg) {
    double a,b,c;
    a = tinhKhoangCach(tg.A,tg.B);
    b = tinhKhoangCach(tg.B,tg.C);
    c = tinhKhoangCach(tg.C,tg.A);
    double p = (a+b+c) / 2;
    double DienTich = sqrt(p*(p-a)*(p-b)*(p-c));

    return DienTich;
}

double tinhChuVi(TamGiac tg) {
    double a,b,c;
    a = tinhKhoangCach(tg.A,tg.B);
    b = tinhKhoangCach(tg.B,tg.C);
    c = tinhKhoangCach(tg.A,tg.C);
    double p = a+b+c;
    return p;
}

Diem tinhToaDoTrongTam(TamGiac &tg) {
    Diem I;
    I.x = (tg.A.x + tg.B.x + tg.C.x) / 3.0;
    I.y = (tg.A.y + tg.B.y + tg.C.y) / 3.0;
    return I;
}

int main() {
    TamGiac tg;

    while (true) {
        nhapTamGiac(tg);
        if (!kiemTraTamGiac(tg)) {
            printf("3 diem khong the tao thanh tam giac! Xin nhap lai\n");
        } else {
            break;
        }
    }
    xuatTamGiac(tg);

    double s = tinhDienTich(tg);
    double p = tinhChuVi(tg);
    printf("Dien tich tam giac la: %.2lf\n", s);
    printf("Chu vi tam giac la: %.2lf\n", p);

    Diem I = tinhToaDoTrongTam(tg);
    printf("Trong tam cua tam giac la: (%.2lf, %.2lf)\n", I.x, I.y);

    return 0;
}