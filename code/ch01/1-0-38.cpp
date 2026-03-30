#include <iostream>
#include <cmath>

int main() {
    double sum = 0.0;
    int n;
    
    do {
        std::cout << "Nhap n (n >= 1): ";
        std::cin >> n;

        if (n < 1) {
            std::cout << "Xin nhap lai!" << std::endl;
        }
    } while(n < 1);

    for (int i = 1; i <= n; i++) {
        sum = pow(sum + i, (1.0/(i+1)));
    }

    std::cout << "Ket qua S(n = " << n << "): " << sum;
    return 0;
}