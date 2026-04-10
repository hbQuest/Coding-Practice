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

DaThuc operator/(DaThuc d1, DaThuc d2) {
    DaThuc d3;
    d3.bac = 0;
    DaThuc dtDu = d1;
    if (d2.bac == 0 && d2.heSo[0] == 0) {
        printf("Khong the chia cho 0\n");
        return d3;
    }
    while (dtDu.bac >= d2.bac) {
        int bacThuong = dtDu.bac - d2.bac;
        double heSoThuong = dtDu.heSo[dtDu.bac] / d2.heSo[d2.bac];

        if (bacThuong > d3.bac) {
            d3.bac = bacThuong;
        }
        d3.heSo[bacThuong] = heSoThuong;

        for (int i = 0; i <= d2.bac; i++) {
            dtDu.heSo[i+bacThuong] -= heSoThuong * d2.heSo[i];
        }

        while (dtDu.bac > 0 && fabs(dtDu.heSo[dtDu.bac]) < 1e-9) {
            dtDu.bac--;
        }
        if (dtDu.bac == 0 && fabs(dtDu.heSo[dtDu.bac]) < 1e-9) {
            break;
        }
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

    DaThuc d3 = d1 / d2;
    printf("d1 / d2 = ");
    XuatDaThuc(d3);

    return 0;
}