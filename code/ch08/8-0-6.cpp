#include <stdio.h>

struct Diem {
    double a;
    int n;
};

void nhap(Diem &d) {
    printf("Nhap co so a: ");
    scanf("%lf", &d.a);
    printf("Nhap so mu: ");
    scanf("%d", &d.n);
}
    
void xuat(Diem d) {
    for (int i = 0; i <= d.n; i++) {
        printf("%.2lfx^%d ", (d.a*i), i);
        if (i < d.n) {
            printf("+ ");
        }
    }
}   

int main() {
    Diem d;

    nhap(d);
    xuat(d);

    return 0;
}

