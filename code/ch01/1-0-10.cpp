#include <iostream>

int main() {
    int n, x, result = 1;

    do {
        std::cout << "Nhap n (n>=0): ";
        std::cin >> n;
    } while (n < 0);
    std::cout << "Nhap x: ";
    std::cin >> x;

    if (n == 0 && x != 0) {
        result = 1;
    } else {
        for (int i = 1; i <= n; i++) {
            result *= x;
        }
    }

    std::cout << "Ket qua tich T(n = " << n << ", x = " << x << "): " << result << std::endl;
    
    return 0;
}