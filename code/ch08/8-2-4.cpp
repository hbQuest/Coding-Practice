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

DaThuc TinhThuong2DaThuc(DaThuc da1, DaThuc da2, DaThuc &du) {
    DaThuc thuong;
    thuong.bac = 0;

    du = da1;

    if (da2.bac == 0 && da2.heSo[0] == 0) {
        printf("Khong the chia cho 0\n");
        return thuong;
    }

    while (du.bac >= da2.bac) 
    {
        int bacCuaThuong = du.bac - da2.bac;
        double heSoThuong = du.heSo[du.bac] / da2.heSo[da2.bac];
        if (bacCuaThuong > thuong.bac) {
            thuong.bac = bacCuaThuong;
        }
        thuong.heSo[bacCuaThuong] = heSoThuong;

        for (int i = 0; i <= da2.bac; i++) {
            du.heSo[i+bacCuaThuong] -= (heSoThuong * da2.heSo[i]);
        }

        while (du.bac > 0 && fabs(du.heSo[du.bac]) < 1e-9) {
            du.bac--;
        }

        if (fabs(du.heSo[du.bac]) < 1e-9 && du.bac == 0) {
            break;
        }
    }
    
    return thuong;
}

int main() {
    DaThuc da1;
    DaThuc da2;

    NhapDaThuc(da1);
    XuatDaThuc(da1);
    NhapDaThuc(da2);
    XuatDaThuc(da2);

    DaThuc du;
    DaThuc thuong = TinhThuong2DaThuc(da1,da2,du);
    printf("Thuong 2 da thuc: ");
    XuatDaThuc(thuong);
    printf("So du la: ");
    XuatDaThuc(du);

    return 0;
}