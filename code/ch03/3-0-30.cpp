#include <stdio.h>
#include <conio.h>

void printTamGiac(int n) {
    printf("Tam giac can dac\n");
    for (int  i = 1; i <= n; i++) {
        for (int j = 1; j <= n + i - 1; j++) {
            if (j < n - i + 1) {
                printf(" ");
            } else {
                printf("*");
            }
        }
        printf("\n");
    }
    
    printf("Tam giac can rong\n");
    for (int  i = 1; i <= n; i++) {
        for (int j = 1; j <= n + i - 1; j++) {
            if (j == n - i  + 1 || j == n + i - 1 || i == n) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    
    printf("Tam giac vuong can dac\n");
    for (int  i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
    
    printf("Tam giac vuong can rong\n");
    for (int  i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (j == 1 || j == i || i == n) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);

    printTamGiac(n);

    return 0;
}