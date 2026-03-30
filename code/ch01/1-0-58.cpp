#include <stdio.h>

int main() {
    int n, soDu, soDao = 0;

    do {
        printf("Nhap so nguyen duong n: ");
        scanf("%d", &n);
        if (n < 1) {
            printf("Xin nhap lai!");
        }
    } while(n < 1);

    int temp = n;
    do {
        soDu = temp%10;
        soDao = soDao * 10 + soDu;
    } while (temp /= 10);

    printf("So nghich dao cua %d la %d\n",n, soDao);
    if (soDao == n) {
        printf("So nguyen duong n la so doi xung ");
    } else {
        printf("So nguyen duong n KHONG la so doi xung ");
    }

    return 0;
}