#include <stdio.h>

int main() {
    int n, sum = 0, f = 1;

    do {
        printf("Nhap n (n>0): ");
        scanf("%d", &n);

        if (n < 1) {
            printf("Xin nhap lai!\n");
        }
    } while(n < 1);

    for (int i = 1; i <= n; i++) {
        f *= i;
        sum += f;
    }
    
    printf("Tong S(n=%d) la %d ",n, sum);

    return 0;
}



