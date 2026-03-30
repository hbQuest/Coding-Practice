#include <iostream>

int main() {
    int n, x, sum = 0, expo = 1;
    std::cout << "Nhap n: ";
    std::cin >> n;
    std::cout << "Nhap x: ";
    std::cin >> x;

    for (int i = 1; i <= (2*n + 1); i++) {
        expo *= x;
        if ((i%2) != 0) {
            sum += expo;
        }
    }

    std::cout << "Ket qua tong S(n = " << n << ", x = " << x << "): " << sum << std::endl;
    
    return 0;
}