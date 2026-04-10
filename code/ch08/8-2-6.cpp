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
        }
        if (da.heSo[i] < 0) {
            printf(" - ");
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

void DaoHamCap1(DaThuc &d) {
    for (int i = 0; i < d.bac; i++) {
        d.heSo[i] = d.heSo[i+1] * (i+1);
    }
    d.bac--;
}

int main() {
    DaThuc d1;

    NhapDaThuc(d1);
    XuatDaThuc(d1);

    DaoHamCap1(d1);
    printf("Dao ham cap 1 da thuc: ");
    XuatDaThuc(d1);

    return 0;
}