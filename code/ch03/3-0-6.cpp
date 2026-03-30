#include <stdio.h>
#include <conio.h>

int timN() {
    int sum = 0, n = 0;
    while (sum <= 10000) {
        n++;
        sum += n;
    }
    return n;
}

int main() {
    int n = timN();
    printf("So nguyen duong n nho nhat la %d", n);

    return 0;
}
