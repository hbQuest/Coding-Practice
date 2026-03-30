#include <iostream>

int main() {
    int n = 0;
    double sum = 0.0;
    std::cout << "Nhap n: ";
    std::cin >> n;

    for (int i = 1; i <= n; i++) {
        sum += ((i*1.0) / (i + 1));
    }

    std::cout << "Ket qua tong S(n = " << n << "): " << sum << std::endl;
    
    return 0;
}