#include <stdio.h>
#include <math.h>

struct DaThuc {
    int bac;
    double heSo[50] = {0};
};

void nhapDaThuc(DaThuc &da) {
    printf("Nhap bac cua da thuc: ");
    scanf("%d", &da.bac);
    for (int i = 0; i <= da.bac; i++) {
        printf("Nhap he so bac %d: ", i);;
        scanf("%lf", &da.heSo[i]);
    }
}
    
void xuatDaThuc(DaThuc da) {
    bool soDauTien = true;
    for (int i = da.bac; i >= 0; i--) {
        if (da.heSo[i] == 0) {
            continue;
        }
        if (!soDauTien && da.heSo[i] > 0) {
            printf(" + ");
        } else if (da.heSo[i] < 0) {
            if (soDauTien) {
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
        soDauTien = false;
    }
    if (soDauTien) {
        printf("0");
    }
    printf("\n");
}   

DaThuc operator-(DaThuc da1, DaThuc da2) {
    DaThuc da3;
    int max = (da1.bac > da2.bac ? da1.bac : da2.bac);
    da3.bac = max;
    for (int i = 0; i <= max; i++) {
        double h1, h2;
        if (i <= da1.bac) {
            h1 = da1.heSo[i];
        } else {
            h1 = 0;
        }
        if (i <= da2.bac) {
            h2 = da2.heSo[i];
        } else {
            h2 = 0;
        }
        da3.heSo[i] = h1 - h2;
    }

    // Cập nhật lại bậc của da3
    while (da3.bac > 0 && da3.heSo[da3.bac] == 0) {
        da3.bac--;
    }
    return da3;
}

int main() {
    DaThuc da1;
    DaThuc da2;

    printf("Nhap da thuc 1:\n");
    nhapDaThuc(da1);
    xuatDaThuc(da1);
    printf("Nhap da thuc 2:\n");
    nhapDaThuc(da2);
    xuatDaThuc(da2);

    printf("Hieu 2 da thuc da1 - da2 = ");
    DaThuc da3 = da1-da2;
    xuatDaThuc(da3);

    return 0;
}