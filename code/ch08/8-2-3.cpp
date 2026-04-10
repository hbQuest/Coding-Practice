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

DaThuc TinhTich2DaThuc(DaThuc da1, DaThuc da2) {
    DaThuc da3;
    da3.bac = da1.bac + da2.bac;
    for (int i = 0; i <= da1.bac; i++) {
        for (int j = 0; j <= da2.bac; j++) {
            da3.heSo[i+j] += da1.heSo[i] * da2.heSo[j]; 
        }
    }
    return da3;
}

int main() {
    DaThuc da1;
    DaThuc da2;

    NhapDaThuc(da1);
    XuatDaThuc(da1);
    NhapDaThuc(da2);
    XuatDaThuc(da2);

    DaThuc da3 = TinhTich2DaThuc(da1,da2);
    printf("Tich 2 da thuc: ");
    XuatDaThuc(da3);
    return 0;
}