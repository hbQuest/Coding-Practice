#include <iostream>

int main() {
    long long n, i, soDauTien, dem = 0;

    do {
        std::cout << "Nhap so nguyen duong n: ";
        std::cin >> n;

        if (n < 1) {
            std::cout << "Xin nhap lai!" << std::endl;
        }
    } while(n < 1);

    i = n;
    while (i >= 10) {
        i /= 10;
    }
    soDauTien = i;
    
    do {
        if (soDauTien == n%10) {
            dem++;
        }
    } while (n /= 10);

    std::cout << "So chu so dau tien cua so nguyen duong n la: " << dem << std::endl;
    
    return 0;
}