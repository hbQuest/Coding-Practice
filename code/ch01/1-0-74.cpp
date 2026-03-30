#include <iostream>

int main() {
    int n;
    bool check = true;

    std::cout << "Nhap so nguyen n: ";
    std::cin >> n;

    if (n <= 0) {
        check = false;
    } else if (n < 2) {
        check = true;
    } else {
        while (n > 1) {
            if (n%2) {
                check = false;
                break;
            }
            n /= 2;
        }
    }
    
    if (check) {
        std::cout << "So n la so co dang 2^k" << std::endl;
    } else {
        std::cout << "So n KHONG co dang 2^k" << std::endl;
    }
    return 0;
}