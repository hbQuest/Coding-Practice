#include <stdio.h>
#define MAX 50

struct DaThuc {
    int bac;
    double heSo[MAX] = {0};
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
    for (int i = 0; i <= da.bac; i++) {
        printf("%.2lfx^%d", da.heSo[i], i);
        if (i < da.bac) {
            printf(" + ");
        }
    }
    printf("\n");
}   

DaThuc operator-(DaThuc da1, DaThuc da2) {
    DaThuc da3;
    int max = (da1.bac > da2.bac ? da1.bac : da2.bac);
    da3.bac = max;
    for (int i = 0; i <= max; i++) {
        da3.heSo[i] = da1.heSo[i] - da2.heSo[i];   
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

    printf("Hieu 2 da thuc la: ");
    DaThuc da3 = da1-da2;
    xuatDaThuc(da3);

    return 0;
}