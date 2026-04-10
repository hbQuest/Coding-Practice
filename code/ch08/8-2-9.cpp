#include <stdio.h>
#include <math.h>

struct DaThuc {
    int bac;
    double heSo[50] = {0};
};

void NhapDaThuc(DaThuc &da) {
    printf("Nhap bac cua da thuc: ");
    scanf("%d", &da.bac);
    printf("Nhap he so:\n");
    for (int i = 0; i <= da.bac; i++) {
        printf("Bac %d: ", i);
        scanf("%lf", &da.heSo[i]);
    }
}

void XuatDaThuc(DaThuc da) {
    bool dauTien = true;
    for (int i = da.bac; i >= 0; i--) {
        if (da.heSo[i] == 0) {
            continue;
        }
        if (!dauTien && da.heSo[i] > 0) {
            printf(" + ");
        } else if (da.heSo[i] < 0) {
            if (dauTien) {
                printf("-");
            } else {
                printf(" - ");
            }
        }
        double heSo = fabs(da.heSo[i]);
        if (i == 0) {
            printf("%.2lf", heSo);
        } else if (i == 1) {
            printf("%.2lf.x", heSo);
        } else {
            printf("%.2lf.x^%d", heSo, i);
        }
        dauTien = false;
    }
    printf("\n");
}

DaThuc operator+(DaThuc d1, DaThuc d2) {
    DaThuc d3;
    int max;
    if (d1.bac >= d2.bac) {
        max = d1.bac;
    } else {
        max = d2.bac;
    }
    d3.bac = max;
    for (int i = 0; i <= max; i++) {
        double h1,h2;
        if (i <= d1.bac) {
            h1 = d1.heSo[i];
        } else {
            h1 = 0;
        }
        if (i <= d2.bac) {
            h2 = d2.heSo[i];
        } else {
            h2 = 0;
        }
        d3.heSo[i] = h1+h2;
    }
    return d3;
}

int main() {
    DaThuc d1;
    DaThuc d2;

    printf("Da thuc 1:\n");
    NhapDaThuc(d1);
    XuatDaThuc(d1);
    printf("Da thuc 2:\n");
    NhapDaThuc(d2);
    XuatDaThuc(d2);

    DaThuc d3 = d1 + d2;
    printf("d1 + d2 = ");
    XuatDaThuc(d3);

    return 0;
}