#include <iostream>

int main() {
    long long n, soDu;
    bool le = false;

    do {
        std::cout << "Nhap so nguyen duong n: ";
        std::cin >> n;

        if (n < 1) {
            std::cout << "Xin nhap lai!" << std::endl;
        }
    } while(n < 1);

    do {
        soDu = n%10;
        if (soDu%2 != 0) {
            le = true;
            break;
        } 
    } while (n /= 10);

    if (le) {
        std::cout << "So nguyen duong n khong chua toan chu so chan" << std::endl;
    } else {
        std::cout << "So nguyen duong n chua toan chu so chan" << std::endl;
    }
    return 0;
}