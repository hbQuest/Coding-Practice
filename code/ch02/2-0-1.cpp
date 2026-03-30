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

    for (int i = 1; i <= n; i++) {
        tong += i;
    }

    printf("Tong cua S(n=%d) la %d", n, tong);
    return 0;
}