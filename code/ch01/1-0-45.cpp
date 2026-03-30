#include <iostream>

int main() {
    int n, tich = 1;

    do {
        std::cout << "Nhap so nguyen duong n: ";
        std::cin >> n;

        if (n < 1) {
            std::cout << "Xin nhap lai!" << std::endl;
        }
    } while(n < 1);

    while (n >= 1) {
        tich *= (n % 10);
        n = n / 10;
    }

    std::cout << "Tich chu so nguyen duong n la: " << tich << std::endl;
    return 0;
}