#include <stdio.h>

void inSoLe(int n) {
    int i = 1;
    while (i < n) {
        if (i == 5 || i == 7 || i == 93) {
            i += 2;
        } else {
            printf("%d ", i);
            i += 2;
        }
    }
}

int main() {
    const int N = 100;
    inSoLe(N);
    
    return 0;
}
