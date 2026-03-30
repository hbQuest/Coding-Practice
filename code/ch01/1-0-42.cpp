#include <iostream>

int main() {
    int n, k = 0, tong = 0;

    do {
        std::cout << "Nhap so nguyen duong n: ";
        std::cin >> n;

        if (n < 1) {
            std::cout << "Xin nhap lai!" << std::endl;
        }
    } while(n < 1);

    while (tong <= n) {
        k++;
        tong += k; // tong += ++k;
    }

    if (tong == n) {
        std::cout << "k la: " << k << std::endl;
    } else {
        std::cout << "k la: " << --k << std::endl;
    }

    return 0;
}