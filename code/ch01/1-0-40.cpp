#include <iostream>
#include <cmath>

int main() {
    double sum = 0.0;
    int n, x, expo = 1;

    do {
        std::cout << "Nhap x (x >= 0): ";
        std::cin >> x;

        if (x < 0) {
            std::cout << "Xin nhap lai!" << std::endl;
        }
    } while(n < 0);
    
    
    do {
        std::cout << "Nhap n (n >= 1): ";
        std::cin >> n;

        if (n < 1) {
            std::cout << "Xin nhap lai!" << std::endl;
        }
    } while(n < 1);

    for (int i = 1; i <= n; i++) {
        expo *= x;
        sum = sqrt(sum + expo);
    }

    std::cout << "Ket qua S(n = " << n << "): " << sum;
    return 0;
}