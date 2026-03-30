#include <iostream>

int main() {
    int n, dem = 0;

    do {
        std::cout << "Nhap so nguyen duong n: ";
        std::cin >> n;

        if (n <=0 ) {
            std::cout << "Xin nhap lai!" << std::endl;
        }
    } while (n<=0);

    for (int i=1; i <= n; i++) {
        if (n%i == 0) {
            dem++;
        }
    }
    std::cout << "So luong uoc so cua n = " << n << " la: " << dem << std::endl;
    return 0;
}