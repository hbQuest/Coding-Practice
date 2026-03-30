#include <iostream>

int main() {
    int n = 0, sum2 = 0;
    double sum1 = 0.0;
    std::cout << "Nhap n: ";
    std::cin >> n;

    for (int i = 1; i <= n; i++) {
        sum2 += i;
        sum1 += (1.0/sum2);
    }

    std::cout << "Ket qua tong S(n = " << n << "): " << sum1 << std::endl;
    
    return 0;
}