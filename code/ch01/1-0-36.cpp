#include <stdio.h>
#include <math.h>

int main() {
    double sum = 0.0;
    int n, giaithua=1;

    do {
        printf("Nhap n (n >= 1): ");
        scanf("%d", &n);

        if (n < 1) {
            printf("Xin nhap lai!");
        }
    } while(n < 1);
    
    for (int i = 1; i <= n; i++) {
        giaithua *= i;
        sum = sqrt(sum + giaithua);
    }

    printf("Ket qua S(n=%d): %.4lf",n, sum);
    return 0;
}
