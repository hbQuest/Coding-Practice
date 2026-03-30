#include <stdio.h>
#include <math.h>

double sqrt3(double n) {
    if (n == 0) {
        return 0;
    } else if ( n > 0) {
        return pow(n, 1.0/3);
    } else {
        return -pow(abs(n), 1.0/3);
    }
}

int main() {
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);

    printf("%.2lf", sqrt3(n));

    return 0;
}