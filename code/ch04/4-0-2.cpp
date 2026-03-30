#include <stdio.h>
#include <math.h>

void lietKeSoChinhPhuong(int n) {
    for (int i = 1 ; i*i < n; i++) {
        printf("%d ", i*i);
    }
}

int main() {
    int n;

    do {
        printf("Nhap so nguyen n: ");
        scanf("%d", &n);
        if (n < 1) {
            printf("Xin nhap lai!\n");
        }
    } while (n < 1);

    lietKeSoChinhPhuong(n);
    return 0;
}