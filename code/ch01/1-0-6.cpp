#include <iostream>

int main() {
    int n = 0;
    double sum = 0.0, multi;
    std::cout << "Nhap n: ";
    std::cin >> n;

    for (int i = 1; i <= n; i++) {
        multi = (1.0 / i) * (i + 1);
        sum += multi;
    }

    std::cout << "Ket qua tong S(n = " << n << "): " << sum << std::endl;
    
    return 0;
}