#include <stdio.h>

void inSoLe(int n) {
    int i = 1;
    while (i < n) {
        printf("%d ", i);
        i += 2;
    }
}

int main() {
    const int N = 100;
    inSoLe(N);
    
    return 0;
}
