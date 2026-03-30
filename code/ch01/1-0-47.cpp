#include <iostream>

int main() {
    int n, tongChan = 0, soDu;

    do {
        std::cout << "Nhap so nguyen duong n: ";
        std::cin >> n;

        if (n < 1) {
            std::cout << "Xin nhap lai!" << std::endl;
        }
    } while(n < 1);

    while (n >= 1) {
        soDu = n%10;
        if (soDu%2 == 0) {
            tongChan += soDu;
        }
        n = n / 10;
    }

    std::cout << "Tong cac chu so chan cua so nguyen duong n la: " << tongChan << std::endl;
    return 0;
}