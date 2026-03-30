#include <stdio.h>
#include <conio.h>

void giaiHePT(double a, double b, double c, double d, double e, double f) {
    //Lap dinh thuc
    double D = a*e - b*d;
    double Dx = b*f - c*e;
    double Dy = a*f - c*d;

    if (D != 0) {
        printf("He co nghiem duy nhat\n");
        printf("x = %.2lf\n", Dx/D);
        printf("y = %.2lf", Dy/D);
    } else {
        if (Dx != 0 || Dy != 0) {
            printf("He vo nghiem");
        } else {
            printf("He co vo so nghiem");
        }
    }
}

int main() {
    double a,b,c,d,e,f;
    printf("Nhap he so a: ");
    scanf("%lf", &a);
    printf("Nhap he so b: ");
    scanf("%lf", &b);
    printf("Nhap he so c: ");
    scanf("%lf", &c);
    printf("Nhap he so d: ");
    scanf("%lf", &d);
    printf("Nhap he so e: ");
    scanf("%lf", &e);
    printf("Nhap he so f: ");
    scanf("%lf", &f);

    giaiHePT(a,b,c,d,e,f);
    return 0;
}