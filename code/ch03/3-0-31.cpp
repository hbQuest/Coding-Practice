#include <stdio.h>

void printHCN(int a, int b){
    printf("Hinh chu nhat dac \n");
    for (int i = 1; i <= b; i++) {
        for (int j = 1; j <= a; j++) {
            printf("%c  ", 42);
        }
        putchar('\n');
    }

    printf("Hinh chu nhat rong \n");
    for (int i = 1; i <= b; i++) {
        for (int j = 1; j <= a; j++) {
            printf((j == 1 || j == a || i == 1 || i == b) ? "%c  " : "   ", 42);
        }
        putchar('\n');
    }
}

int main() {
    int a,b;
    printf("Nhap chieu dai a: ");
    scanf("%d", &a);
    printf("Nhap chieu rong b: ");
    scanf("%d", &b);

    printHCN(a,b);
    return 0;
}