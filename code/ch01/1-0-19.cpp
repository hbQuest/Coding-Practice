#include <iostream>

int main() {
    int n, x, expo = 1, giaithua = 1;
    double sum1 = 0.0;
    std::cout << "Nhap n: ";
    std::cin >> n;
    std::cout << "Nhap x: ";
    std::cin >> x;

    for (int i = 0; i <= (2*n); i++) {
        if (i == 0) {
            expo = 1;
            giaithua = 1;
        } else {
            expo *= x;
            giaithua *= i;
        }
        if (i%2 == 0) {
            sum1 += ((expo * 1.0) / giaithua);
        }
    }

    std::cout << "Ket qua tong S(n = " << n << "): " << sum1 << std::endl;
    
    return 0;
}