#include <iostream>

int main() {
    int n;
    double S = 1.0;

    do {
        std::cout << "Nhap n (n >= 1): ";
        std::cin >> n;

        if (n < 1) {
            std::cout << "Xin nhap lai!" << std::endl;
        }
    } while(n < 1);

    for (int i = 1; i <= n; i++) {
        S = 1 + (1.0/S);
    }

    S = 1.0 / S;
    std::cout << "Ket qua S(n = " << n << "): " << S << std::endl;
    return 0;
}