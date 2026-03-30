#include <stdio.h>
#include <math.h>

double tinhSin(int n, double x) {
    double giaithua = 1.0, t;
    double sum = 0;
    for (int i = 0; i <= n; i++) {
        if (i == 0) {
            giaithua = 1;
            t = 1;
        } else {
            t = 2*i + 1;
            giaithua *= (t - 1) * t;
        }
        sum += (pow(-1.0,i) * (pow(x, t) / giaithua));
    }
    return sum;
}

int main() {
    int n;
    double x, sum;

    printf("Nhap so nguyen n: ");
    scanf("%d", &n);
    printf("Nhap x(radian): ");
    scanf("%lf", &x);

    sum = tinhSin(n,x);

    printf("Cong thuc Taylor Sin(x) = %.5lf\n", sum);
    printf("Theo math.h Sin(x) = %.5lf", sin(x));

    return 0;
}