#include <stdio.h>
#include <math.h>

int main() {
    int n;
    bool soNguyenTo = true;

    do {
        printf("Nhap so nguyen duong n (n>0): ");
        scanf("%d", &n);

        if (n <=0 ) {
            printf("Xin nhap lai!\n");
        }
    } while (n<=0);

    if (n < 2) {
        soNguyenTo = false;
    } else if (n == 2) {
        soNguyenTo = true;
    } else if (n%2 == 0) {
        soNguyenTo = false;
    } else {
        for (int i = 3; i <= sqrt(n); i+=2) {
            if (n%i == 0) {
                soNguyenTo = false;
                break;
            }
        }
    }

    if (soNguyenTo) {
        printf("%d la so nguyen to", n);
    } else {
        printf("%d KHONG la so nguyen to", n);
    }

    return 0;
}