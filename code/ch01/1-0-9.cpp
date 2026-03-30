#include <iostream>

int main() {
    int n, multi = 1;
    std::cout << "Nhap n: ";
    std::cin >> n;

    if (n == 0) {
        multi = 0;
    } else {
        for (int i = 1; i <= n; i++) {
            multi *= i;
        }
    }

    std::cout << "Ket qua tich T(n = " << n << "): " << multi << std::endl;
    
    return 0;
}