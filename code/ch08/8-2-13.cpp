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
double TinhGiaTri(DaThuc d, double x) {
    double s = 0.0;
    for (int i = 0; i <= d.bac; i++) {
        s += (d.heSo[i]*pow(x,i));
    }
    return s;
}

void TimNghiem(DaThuc d, double a, double b, double buocNhay) {
    double fa = TinhGiaTri(d,a);
    double fb = TinhGiaTri(d,b);

    if (fabs(fa) < 1e-9) {
        printf("Nghiem xap xi tim duoc la: %.2lf\n", a);
        return;
    }
    if (fabs(fb) < 1e-9) {
        printf("Nghiem xap xi tim duoc la: %.2lf\n", b);
        return;
    }
    if (fa*fb > 0) {
        printf("Khong the chac chan co nghiem trong doan [%.2lf, %.2lf]", a,b);
        return;
    }
    double m;
    while ((b-a) > buocNhay) {
        m = (a+b) / 2.0;
        double fm = TinhGiaTri(d,m);

        if (fabs(fm) < 1e-9) {
            a=m;
            b=m;
            break;
        }

        if (fa*fm < 0) {
            b = m;
        } else {
            a = m;
            fa = fm;
        }
    }

    printf("Nghiem xap xi tim duoc co trong doan [%.2lf, %.2lf] la: %.2lf\n", a,b,(a+b)/2.0);
}

int main() {
    DaThuc d1;
    // DaThuc d2;

    printf("Da thuc 1:\n");
    NhapDaThuc(d1);
    XuatDaThuc(d1);
    // printf("Da thuc 2:\n");
    // NhapDaThuc(d2);
    // XuatDaThuc(d2);

    TimNghiem (d1,2,4,0.2);

    return 0;
}