#include <stdio.h>
#include <math.h>

int main() {
    int x, y, S=1;
    printf("Nhap x = ");
    scanf("%d", &x);
    printf("Nhap y(>=0) = ");
    scanf("%d", &y);
    
    if (y == 0 && x != 0) {
        S = 1;
    } else if (x == 0) {
        S = 0;
    } else {
        for (int i = 1; i <= y; i++) {
            S *= x;
        } 
    }
    
    printf("Ket qua S = %d^%d = %d", x, y, S);

    return 0;
}