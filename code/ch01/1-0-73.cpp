#include <iostream>
#include <cmath>

int main() {
    int x, n, t, mau = 1;
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
        mau *= (2*i + 1) * (2*i);
        t = pow((-1.0), i+1);
        tich = t * (pow(x,(i*2)+1) / mau);
        S += tich;
    }

    S += 1 - x;
    
    std::cout << "Ket qua S: " << S << std::endl;
    return 0;
}