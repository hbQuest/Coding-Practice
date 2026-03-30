#include <stdio.h>

int main() {
    int n, tong = 0;

    do {
        printf("Nhap so nguyen duong n (n>0): ");
        scanf("%d", &n);

        if (n < 1) {
            printf("Xin nhap lai!\n");
        }
    } while(n < 1);
    
    for (int i=1; i <= n; i++) {
        if (n%i == 0) {
            tong += i;
        }
    }
    printf("Tong cua cac uoc so cua %d la %d", n, tong);

    return 0;
}

