#include <stdio.h>
#include <conio.h>

int timUCLN(int a, int b) {
    int max, min;
    if (a == b) {
        return a;
    }
    while (a != b) {
        if (a < b) {
            b = b - a;
        } else {
            a = a - b;
        }
    }
    return a;
}

int main() {
    int a,b;
    do {
        printf("Nhap a: ");
        scanf("%d", &a);
        if (a < 1) {
            printf("Xin nhap lai!\n");
        }
    } while (a < 1);

    do {
        printf("Nhap b: ");
        scanf("%d", &b);
        if (a < 1) {
            printf("Xin nhap lai!\n");
        }
    } while (b < 1);

    int UCLN = timUCLN(a,b);
    printf("Uoc chung lon nhat cua a va b la %d", UCLN);
    return 0;
}