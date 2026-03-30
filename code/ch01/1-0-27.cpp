#include <iostream>

int main() {
    int n, demChan = 0;

    do {
        std::cout << "Nhap so nguyen duong n: ";
        std::cin >> n;

        if (n <=0 ) {
            std::cout << "Xin nhap lai!" << std::endl;
        }
    } while (n<=0);

    for (int i=1; i <= n; i++) {
        if (n%i == 0 && i%2 == 0) {
            demChan++;
        }
    }
    std::cout << "So luong cac uoc so chan cua n = " << n << " la: " << demChan << std::endl;
    return 0;
}