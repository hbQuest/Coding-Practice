#include <iostream>

int main() {
    int n;

    do {
        std::cout << "Nhap so nguyen duong n: ";
        std::cin >> n;

        if (n <=0 ) {
            std::cout << "Xin nhap lai!" << std::endl;
        }
    } while (n<=0);

    std::cout << "So cac uoc so le cua n = " << n << " la: ";
    for (int i=1; i <= n; i++) {
        if (n%i == 0 && i%2 != 0) {
            std::cout << i << " ";
        }
    }
    return 0;
}