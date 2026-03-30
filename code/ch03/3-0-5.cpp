#include <stdio.h>
#include <conio.h>

int tinhS(int n) {
   int sum = 0, t;
   for (int  i = 0; i <= n; i++) {
        t = i*i*i;
        sum += t;
   }
   return sum;
}

int main() {
    int n;
    do {
        printf("Nhap so nguyen n: ");
        scanf("%d", &n);
        if (n < 0) {
            printf("Xin nhap lai!");
        }
    } while (n < 0);

    int sum = tinhS(n);
    printf("Ket qua S(n) = %d", sum);

    return 0;
}