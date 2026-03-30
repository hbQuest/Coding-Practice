#include <stdio.h>

int main() {
    int n, s = 0, i = 1;

    printf("Nhap n: ");
    scanf("%d", &n);

    while (i <= n) {
        s += i;
        i++;
    }

    printf("Tong S = %d", s);
    return 0;
}