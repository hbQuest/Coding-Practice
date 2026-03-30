#include <stdio.h>
#include <math.h>
#include "mang.h"

int main() {
    int a[100];
    int n;
    // printf("Cac so nguyen to be hon 100 gom: ");
    // lietKeSoNguyenToBeHon100();

    nhapMang(a,n);
    xuatMang(a,n);
    int r = timGiaTriLonNhat(a,n);
    printf("%d", r);
    return 0;
}