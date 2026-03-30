#include <iostream>

int main() {
    int n;
    bool soChinhPhuong = false;

    do {
        std::cout << "Nhap so nguyen duong n: ";
        std::cin >> n;

        if (n <=0 ) {
            std::cout << "Xin nhap lai!" << std::endl;
        }
    } while (n<=0);

    for (int i = 1; i*i <= n; i++) {
        if ((i*i) == n) {
            soChinhPhuong = true;
        }
    }

    if (soChinhPhuong) {
        std::cout << n << " la so chinh phuong" << std::endl;
    } else {
        std::cout << n << " khong la so chinh phuong" << std::endl;
    }

    return 0;
}