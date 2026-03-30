#include <stdio.h>

int main() {
    int n, dem = 0;

    do {
        printf("Nhap so nguyen duong n: ");
        scanf("%d", &n);
        if (n < 1) {
            printf("Xin nhap lai!\n");
        }
    } while(n < 1);

    int temp = n;
    while (temp > 0) {
        dem++;
        temp /= 10;
    }

    printf("So luong chu so cua so nguyen duong n=%d la: %d ", n, dem);
    return 0;
}