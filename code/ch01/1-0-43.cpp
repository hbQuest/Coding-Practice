#include <iostream>

int main() {
    int n, dem = 0;

    do {
        std::cout << "Nhap so nguyen duong n: ";
        std::cin >> n;

        if (n < 1) {
            std::cout << "Xin nhap lai!" << std::endl;
        }
    } while(n < 1);

    while (n >= 1) {
        dem++;
        n = n / 10;
    }

    std::cout << "So chu so nguyen duong n la: " << dem << std::endl;
    return 0;
}