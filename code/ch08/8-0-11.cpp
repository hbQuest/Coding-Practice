// #include <stdio.h>
// #include <math.h>

// struct Diem {
//     double x,y;
// };

// struct TamGiac {
//     Diem A;
//     Diem B;
//     Diem C;
// };

// void nhapDiem(Diem &O) {
//     printf("Nhap x: ");
//     scanf("%lf", &O.x);
//     printf("Nhap y: ");
//     scanf("%lf", &O.y);
// }

// void nhapTamGiac(TamGiac &tg) {
//     printf("Nhap toa do diem A\n");
//     nhapDiem(tg.A);
//     printf("Nhap toa do diem B\n");
//     nhapDiem(tg.B);
//     printf("Nhap toa do diem C\n");
//     nhapDiem(tg.C);
// }

// double tinhKhoangCach(Diem A, Diem B) {
//     double d = sqrt((A.x-B.x)*(A.x-B.x) + (A.y-B.y)*(A.y-B.y));
//     return d;
// }

// bool kiemTraTamGiac(TamGiac tg) {
//     double a = tinhKhoangCach(tg.A,tg.B);
//     double b = tinhKhoangCach(tg.B,tg.C);
//     double c = tinhKhoangCach(tg.C,tg.A);

//     if (a + b > c && a + c > b && b + c > a) {
//         return true;
//     }
//     return false;
// }

// void xuatTamGiac(TamGiac tg) {
//     printf("(%.2lf, %.2lf), (%.2lf, %.2lf), (%.2lf, %.2lf)\n", tg.A.x,tg.A.y,tg.B.x,tg.B.y,tg.C.x,tg.C.y);
// }   


// double tinhDienTich(TamGiac tg) {
//     double a,b,c;
//     a = tinhKhoangCach(tg.A,tg.B);
//     b = tinhKhoangCach(tg.B,tg.C);
//     c = tinhKhoangCach(tg.C,tg.A);
//     double p = (a+b+c) / 2;
//     double DienTich = sqrt(p*(p-a)*(p-b)*(p-c));

//     return DienTich;
// }

// double tinhChuVi(TamGiac tg) {
//     double a,b,c;
//     a = tinhKhoangCach(tg.A,tg.B);
//     b = tinhKhoangCach(tg.B,tg.C);
//     c = tinhKhoangCach(tg.A,tg.C);
//     double p = a+b+c;
//     return p;
// }

// Diem tinhToaDoTrongTam(TamGiac &tg) {
//     Diem I;
//     I.x = (tg.A.x + tg.B.x + tg.C.x) / 3.0;
//     I.y = (tg.A.y + tg.B.y + tg.C.y) / 3.0;
//     return I;
// }

// int main() {
//     TamGiac tg;

//     while (true) {
//         nhapTamGiac(tg);
//         if (!kiemTraTamGiac(tg)) {
//             printf("3 diem khong the tao thanh tam giac! Xin nhap lai\n");
//         } else {
//             break;
//         }
//     }
//     xuatTamGiac(tg);

//     double s = tinhDienTich(tg);
//     double p = tinhChuVi(tg);
//     printf("Dien tich tam giac la: %.2lf\n", s);
//     printf("Chu vi tam giac la: %.2lf\n", p);

//     Diem I = tinhToaDoTrongTam(tg);
//     printf("Trong tam cua tam giac la: (%.2lf, %.2lf)\n", I.x, I.y);

//     return 0;
// }

#include <stdio.h>
#include <math.h>

struct Diem {
    double x,y;
};

struct TamGiac {
    Diem A, B, C;
};

double KhoangCach(Diem d1, Diem d2) {
    double d = sqrt(pow((d1.x - d2.x),2.0) + pow((d1.y - d2.y),2.0));
    return d;
}

bool KiemTraTamGiacHopLe(TamGiac a) {
    double AB = KhoangCach(a.A, a.B);
    double AC = KhoangCach(a.A, a.C);
    double BC = KhoangCach(a.B, a.C);
    if (AB + AC > BC && AB + BC > AC && AC + BC > AB) {
        return true;
    }
    return false;
} 

void nhap(TamGiac &a) {
    do {
        printf("Nhap diem A:\n");
        printf("x = ");
        scanf("%lf", &a.A.x);
        printf("y = ");
        scanf("%lf", &a.A.y);
        printf("Nhap diem B:\n");
        printf("x = ");
        scanf("%lf", &a.B.x);
        printf("y = ");
        scanf("%lf", &a.B.y);
        printf("Nhap diem C:\n");
        printf("x = ");
        scanf("%lf", &a.C.x);
        printf("y = ");
        scanf("%lf", &a.C.y);
        if (!KiemTraTamGiacHopLe(a)) {
            printf("Tam giac khong hop le! Xin nhap lai!\n");
        }
    } while (!KiemTraTamGiacHopLe(a));
}

double TinhDienTich(TamGiac a) {
    double AB = KhoangCach(a.A, a.B);
    double AC = KhoangCach(a.A, a.C);
    double BC = KhoangCach(a.B, a.C);
    double p = (AB + AC + BC) / 2;
    double S = sqrt(p*(p-AB)*(p-AC)*(p-BC));
    return S;
}

double TinhChuVi(TamGiac a) {
    double AB = KhoangCach(a.A, a.B);
    double AC = KhoangCach(a.A, a.C);
    double BC = KhoangCach(a.B, a.C);
    return (AB + AC + BC);
}

Diem ToaDoTrongTam(TamGiac a) {
    Diem O;
    double x = (a.A.x + a.B.x + a.C.x)*1.0 / 3; 
    double y = (a.A.y + a.B.y + a.C.y)*1.0 / 3; 
    O.x = x;
    O.y = y;
    return O;
}

int main() {
    TamGiac tg;
    nhap(tg);
    double S =TinhDienTich(tg);
    double P =TinhChuVi(tg);
    Diem O = ToaDoTrongTam(tg);

    printf("Dien tich tam giac: %.2lf\n", S);
    printf("Chu vi: %.2lf\n", P);
    printf("Toa do trong tam O: (%.2lf, %.2lf)", O.x, O.y);


    return 0;
}