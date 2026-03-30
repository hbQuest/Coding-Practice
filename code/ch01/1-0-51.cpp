#include <iostream>

int main() {
    int n, soDu, max = 0;

    do {
        std::cout << "Nhap so nguyen duong n: ";
        std::cin >> n;

        if (n < 1) {
            std::cout << "Xin nhap lai!" << std::endl;
        }
    } while(n < 1);

    while (n >= 1) {
        soDu = n%10;
        if (max < soDu) {
            max = soDu;
        }
        n = n / 10;
    }

    std::cout << "Chu so lon nhat cua so nguyen duong n la: " << max << std::endl;
    return 0;
}