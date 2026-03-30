#include <stdio.h>
#include <math.h>
#include "soNguyenTo.h"

// Dinh nghia ham
void lietKeSoNguyenToBeHon100() {
    for (int i = 1 ; i < 100; i++) {
        if (kiemTraSoNguyenTo(i)) {
            printf("%d ", i);
        }
    }
}
bool kiemTraSoNguyenTo(int n) {
    if (n == 2 || n == 3) {
        return true;
    }
    if (n <= 1 || n%2 == 0 || n%3 == 0) {
        return false;
    }
    for (int i = 5; i*i <= n; i+=6) {
        if (n%i == 0 || n%(i+2) == 0) {
            return false;
        }
    }
    return true;
}

