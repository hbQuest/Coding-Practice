#include <iostream>

int main() {
    int n, soDu, soDao = 0;

    do {
        std::cout << "Nhap so nguyen duong n: ";
        std::cin >> n;

        if (n < 1) {
            std::cout << "Xin nhap lai!" << std::endl;
        }
    } while(n < 1);

    do {
        soDu = n%10;
        soDao = soDao * 10 + soDu;
    } while (n /= 10); // tuong duong n = n/10 hoac n != 0  

    std::cout << "Chu so dao nguoc cua so nguyen duong n la: " << soDao << std::endl;

    // Hoac co the viet
    // std::cout << "Chu so dao nguoc cua so nguyen duong n la: ";
    // do {
    //     std::cout << n%10;
    // } while (n /= 10);

    return 0;
}