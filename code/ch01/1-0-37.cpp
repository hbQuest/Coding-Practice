#include <stdio.h>
#include <math.h>

int main() {
    double sum = 0.0;
    int n;

    do {
        printf("Nhap n (n >= 2): ");
        scanf("%d", &n);

        if (n < 2) {
            printf("Xin nhap lai!");
        }
    } while(n < 2);
    
    for (int i = 2; i <= n; i++) {
        sum = pow(sum + i, (1.0/i));
    }

    printf("Ket qua S(n=%d): %.4lf",n, sum);
    return 0;
}
