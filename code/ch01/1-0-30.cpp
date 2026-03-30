#include <iostream>

int main() {
    int n, tong = 0;

    do {
        std::cout << "Nhap so nguyen duong n: ";
        std::cin >> n;

        if (n <=0 ) {
            std::cout << "Xin nhap lai!" << std::endl;
        }
    } while (n<=0);

    for (int i=1; i < n; i++) {
        if (n%i == 0) {
            tong += i;
        }
    }
    
    if (n == tong) {
        std::cout << "n = " << n << " la so hoan thien";
    } else {
        std::cout << "n = " << n << " khong la so hoan thien";
    }
    return 0;
}