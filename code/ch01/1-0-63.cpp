#include <iostream>
#include <cmath>

int main() {
    int a, b;
    double x;

    std::cout << "Phuong trinh bac 1" << std::endl;
    do {
        std::cout << "Nhap so he so a (a khac 0): ";
        std::cin >> a;

        if (a == 0) {
            std::cout << "Xin nhap lai!" << std::endl;
        }
    } while(a == 0);

    std::cout << "Nhap he so b: ";
    std::cin >> b;

    if (b == 0) {
        x = 0;
    } else {
        x = (-1.0 * b) / a;
    }
    std::cout << "Phuong trinh co 1 nghiem" << std::endl;
    std::cout << "Nghiem x = " << x << std::endl;
       
    return 0;
}