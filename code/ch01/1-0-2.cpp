#include <iostream>

int main() {
    int n,sum = 0;
    std::cout << "Nhap n: ";
    std::cin >> n;

    for (int i = 1; i <= n; i++) {
        sum += (i * i);
    }

    std::cout << "Ket qua tong S(n = " << n << "): " << sum;
    
    return 0;
}