#include <stdio.h>
#include <math.h>

bool kiemTraSoNguyenTo(int n) {
    if (n == 2 || n == 3) {
        return true;
    }
    if (n < 2 || n%2 == 0 || n%3 == 0) {
        return false;
    }
    for (int i = 5; i*i <= n; i+=6) {
        if (n%i == 0 || n%(i+2) == 0) {
            return false;
        }
    }
    return true;
}

void lietKeSoNguyenTo(int n) {
    for (int i = 1 ; i <= n; i++) {
        if (kiemTraSoNguyenTo(i)) {
            printf("%d ", i);
        }
    }
}

int main() {
    int n;
    
    do {
        printf("Nhap so nguyen n: ");
        scanf("%d", &n);
        if (n < 1) {
            printf("Xin nhap lai!\n");
        }
    } while (n < 1);

    lietKeSoNguyenTo(n);
    return 0;
}