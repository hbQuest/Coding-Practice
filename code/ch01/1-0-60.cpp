#include <iostream>

int main() {
    long long n, i, soDu;
    bool check = true;

    do {
        std::cout << "Nhap so nguyen duong n: ";
        std::cin >> n;

        if (n < 1) {
            std::cout << "Xin nhap lai!" << std::endl;
        }
    } while(n < 1);

    i = n%10;
    while(n /= 10) {
        soDu = n%10;
        if (soDu < i) {
            check = false;
            break;
        }
        i = soDu;
    }

    if (check) {
        std::cout << "Cac chu so nguyen duong n giam dan tu trai qua phai" << std::endl;
    } else {
        std::cout << "Cac chu so nguyen duong n KHONG giam dan tu trai qua phai" << std::endl;
    }

    return 0;
}