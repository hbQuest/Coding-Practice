#include <stdio.h>
#include <conio.h>
#include <math.h>

float tinhF(float x) {
    float f;
    if (x >= 5) {
        f = (2.0 * pow(x,2) + (5.0 * x) + 9);
    } else {
        f = (-2.0 * pow(x,2) + (4.0 * x) - 9);
    }
    return f;
}

int main() {
    float x;
    printf("Nhap x: ");
    cscanf("%f", &x);
    float f = tinhF(x);
    printf("Gia tri ham so f khi x = %.1f la %f", x, f);
    return 0;
}