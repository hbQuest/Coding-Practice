#include <stdio.h>
#include <conio.h>

int tinhTongLe(int n) {
    int sum = 0;
    for (int i = 1; i < n; i+=2) {
        sum += i;
    }
    return sum;
}
int main() {
    int n;
    do {
        printf("Nhap so nguyen duong n: ");
        scanf("%d", &n);
        if (n < 1) {
            printf("Xin nhap lai!\n");
        }
    } while (n < 1);

    int sum = tinhTongLe(n);
    printf("Tong cac so nguyen le nho hon n: %d", sum);
    return 0;
}

