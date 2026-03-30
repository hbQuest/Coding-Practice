#include <stdio.h>
#include <conio.h>

bool checkSoNguyenTo(int n) {
    if (n == 2 || n == 3) {
        return true;
    } 
    if (n == 1 || n % 2 == 0 || n % 3 == 0) {
        return false;
    } 
    for (int i = 5; i*i < n; i += 6) {
        if (n%i == 0 || n%(i + 2) == 0) {
            return false;
        }
    }
    return true;
}

int sumOfPrime(int n) {
    int sum = 0;
    for (int i = 1; i < n; i++) {
        if (checkSoNguyenTo(i)) {
            sum += i;
        }
    }
    return sum;
}

int main() {
    int n;
    do {
        printf("Nhap so nguyen duong n: ");
        scanf("%d", &n);
        if (n < 1) {
            printf("Xin nhap lai!");
        }
    } while (n < 1);

    int S = sumOfPrime(n);

    printf("Tong cac so nguyen to nho hon n: %d", S);

    return 0;
}