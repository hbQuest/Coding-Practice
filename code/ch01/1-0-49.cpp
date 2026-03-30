#include <iostream>

int main() {
    int n, chuSoDau;

    do {
        std::cout << "Nhap so nguyen duong n: ";
        std::cin >> n;

        if (n < 1) {
            std::cout << "Xin nhap lai!" << std::endl;
        }
    } while(n < 1);

    while (n >= 1) {
        chuSoDau = n%10;
        n = n / 10;
    }

    std::cout << "Chu so dau tien cua so nguyen duong n la: " << chuSoDau << std::endl;
    return 0;
}