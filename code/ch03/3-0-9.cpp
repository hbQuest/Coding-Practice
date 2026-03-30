#include <stdio.h>
#include <conio.h>

int timM(int n) {
    int sum = 0, m = 0;
    while (sum < n) {
        m++;
        sum += m;
    }
    return --m;
}

int main() {
    int n;
    do {
        printf("Nhap so nguyen duong n: ");
        scanf("%d", &n);
        if (n < 1) {
            printf("Xin nhap lai!\n");
        }
    } while (n < 1);

    int m = timM(n);
    printf("So nguyen duong n nho nhat la %d", m);

    return 0;
}
