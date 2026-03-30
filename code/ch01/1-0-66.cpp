#include <iostream>
#include <cmath>

int main() {
    int x, n, tich, tong = 0;

    do {
        std::cout << "Nhap so nguyen duong n: ";
        std::cin >> n;

        if (n < 1) {
            std::cout << "Xin nhap lai!" << std::endl;
        }
    } while(n < 1);

    std::cout << "Nhap x: ";
    std::cin >> x;

    for (int i = 1; i <= n; i++) {
        tich = pow((-1), i+1) * pow(x, i);
        tong += tich;
    }

    std::cout << "Ket qua S: " << tong << std::endl;
    return 0;
}