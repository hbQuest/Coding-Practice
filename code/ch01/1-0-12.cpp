#include <iostream>

int main() {
    int n, x, sum = 0, expo = 1;
    std::cout << "Nhap n: ";
    std::cin >> n;
    std::cout << "Nhap x: ";
    std::cin >> x;

    for (int i = 1; i <= n; i++) {
        expo *= x;
        sum += expo;
    }

    std::cout << "Ket qua tong S(n = " << n << ", x = " << x << "): " << sum << std::endl;
    
    return 0;
}