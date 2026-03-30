#include <stdio.h>

struct DonThuc {
    double a;
    int n;
};

void nhap(DonThuc &dt) {
    printf("Nhap co so a: ");
    scanf("%lf", &dt.a);
    printf("Nhap so mu: ");
    scanf("%d", &dt.n);
}
    
void xuat(DonThuc dt) {
    printf("%.2lfx^%d\n", dt.a, dt.n);
}   

DonThuc daoHamCapk(DonThuc d, int k) {
    for (int i = 1; i <= k; i++) {
        d.a = d.a * d.n;
        d.n = d.n - 1; 
    }
    return d;
}

int main() {
    DonThuc d;

    printf("Nhap don thuc:\n");
    nhap(d);
    xuat(d);

    int k;
    do {
        printf("Nhap dao ham cap k = ");
        scanf("%d", &k);
        if (k > d.n+1) {
            printf("k khong hop le! Xin nhap lai!\n");
        }
    } while (k > d.n+1);
    
    printf("Dao ham cap %d cua don thuc la: ", k);
    DonThuc d3 = daoHamCapk(d,k);
    if (d3.n == -1) {
        printf("0");
    } else {
        xuat(d3);
    }

    return 0;
}