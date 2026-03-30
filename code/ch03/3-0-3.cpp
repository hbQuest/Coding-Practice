#include <stdio.h>
#include <conio.h>

void giaiPT(float a, float b){
    if (a == 0) {
        if (b == 0) {
            printf("Phuong trinh co vo so nghiem");
        } else {
            printf("Phuong trinh vo nghiem");
        }
    } else {
        float x = (-b * 1.0) / a;
        printf("Phuong trinh co mot nghiem la: %f", x);
    }
}

int main() {
    float a,b;
    printf("Nhap co so a: ");
    scanf("%f", &a);
    printf("Nhap co so b: ");
    scanf("%f", &b);

    giaiPT(a,b);

    return 0;
}
