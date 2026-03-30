#include <stdio.h>

int main() {
    int n;

    do {
        printf("Nhap so nguyen duong n: ");
        scanf("%d", &n);

        if (n < 1) {
            printf("Xin nhap lai!\n");
        }
    } while(n < 1);
    
    printf("Uoc cua %d la: ", n);
    for (int i=1; i <= n; i++) {
        if (n%i == 0) {
            printf("%3d", i);
        }
    }

    return 0;
}

