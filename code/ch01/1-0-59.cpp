#include <iostream>

int main() {
    long long n, temp;
    bool checkGiam = true;

    do {
        std::cout << "Nhap so nguyen duong n: ";
        std::cin >> n;

        if (n < 1) {
            std::cout << "Xin nhap lai!" << std::endl;
        }
    } while(n < 1);

    temp = n%10;
    while(n /= 10) {
        int soDu = n%10;
        if (soDu > temp) {
            checkGiam = false;
            break;
        }
        temp = soDu;
    }

    if (checkGiam) {
        std::cout << "Cac chu so nguyen duong n tang dan tu trai qua phai" << std::endl;
    } else {
        std::cout << "Cac chu so nguyen duong n KHONG tang dan tu trai qua phai" << std::endl;
    }

    return 0;
}