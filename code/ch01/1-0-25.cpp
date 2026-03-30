#include <iostream>

int main() {
    int n, tongChan = 0;

    do {
        std::cout << "Nhap so nguyen duong n: ";
        std::cin >> n;

        if (n <=0 ) {
            std::cout << "Xin nhap lai!" << std::endl;
        }
    } while (n<=0);

    for (int i=1; i <= n; i++) {
        if (n%i == 0 && i%2 == 0) {
            tongChan += i;
        }
    }
    std::cout << "Tong cac uoc so chan cua n = " << n << " la: " << tongChan << std::endl;
    return 0;
}