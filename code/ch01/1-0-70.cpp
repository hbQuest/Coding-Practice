#include <iostream>
#include <cmath>

int main() {
    int x, n, mau = 0;
    double tich, S = 0;

    do {
        std::cout << "Nhap so nguyen duong n: ";
        std::cin >> n;

        if (n < 1) {
            std::cout << "Xin nhap lai!" << std::endl;
        }
    } while(n < 1);

    std::cout << "Nhap x: ";
    std::cin >> x;

    for (int i = 1; i <= n; i++) {
        mau += i;
        tich = pow((-1.0), i) * (pow(x*1.0,i) / mau);
        S += tich;
    }

    std::cout << "Ket qua S: " << S << std::endl;
    return 0;
}