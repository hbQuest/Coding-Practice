#include <stdio.h>
#include <math.h>

int main() {
    int n;
    printf("Nhap bang cuu chuong cua n = ");
    scanf("%d", &n);
    
    for (int i = 0; i <= 10; i++) {
        printf("%d * %d = %d\n", n, i, n*i);
    }

    return 0;
}