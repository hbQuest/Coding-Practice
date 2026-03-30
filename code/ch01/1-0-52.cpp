#include <iostream>

int main() {
    int n, soDu, min = 10;

    do {
        std::cout << "Nhap so nguyen duong n: ";
        std::cin >> n;

        if (n < 1) {
            std::cout << "Xin nhap lai!" << std::endl;
        }
    } while(n < 1);

    while (n >= 1) {
        soDu = n%10;
        if (min > soDu) {
            min = soDu;
        }
        n = n / 10;
    }

    std::cout << "Chu so nho nhat cua so nguyen duong n la: " << min << std::endl;
    return 0;
}