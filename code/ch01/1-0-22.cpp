#include <iostream>

int main() {
    int n, tich = 1;

    do {
        std::cout << "Nhap so nguyen duong n: ";
        std::cin >> n;

        if (n <=0 ) {
            std::cout << "Xin nhap lai!" << std::endl;
        }
    } while (n<=0);

    for (int i=1; i <= n; i++) {
        if (n%i == 0) {
            tich *= i;
        }
    }
    std::cout << "Tich cua cac uoc so cua n = " << n << " la: " << tich << std::endl;
    return 0;
}