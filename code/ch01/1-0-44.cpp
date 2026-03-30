#include <stdio.h>

int main() {
    int n, tong = 0;

    do {
        printf("Nhap so nguyen duong n: ");
        scanf("%d", &n);
        if (n < 1) {
            printf("Xin nhap lai!\n");
        }
    } while(n < 1);

    int temp = n;
    while (temp > 0) {
        tong += (temp % 10);
        temp /= 10;
    }

    printf("Tong chu so nguyen duong n=%d la: %d ", n, tong);
    return 0;
}