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
        double heSo = abs(da.heSo[i]);
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

DaThuc TinhTong2DaThuc(DaThuc da1, DaThuc da2) {
    DaThuc da3;
    int maxBac; 
    if (da1.bac >= da2.bac) {
        maxBac = da1.bac;
    } else {
        maxBac = da2.bac;
    }

    for (int i = 0; i <= maxBac; i++) {
        double t1,t2;
        if (i > da1.bac) {
            t1 = 0;
        } else {
            t1 = da1.heSo[i];
        }
        if (i > da2.bac) {
            t2 = 0;
        } else {
            t2 = da2.heSo[i];
        }

        da3.heSo[i] = t1 + t2;
    }
    da3.bac = maxBac;
    return da3;
}

int main() {
    DaThuc da1;
    DaThuc da2;

    NhapDaThuc(da1);
    XuatDaThuc(da1);
    NhapDaThuc(da2);
    XuatDaThuc(da2);

    DaThuc da3 = TinhTong2DaThuc(da1,da2);
    printf("Tong 2 da thuc: ");
    XuatDaThuc(da3);
    return 0;
}