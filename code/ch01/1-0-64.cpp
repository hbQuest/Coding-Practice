#include <iostream>
#include <cmath>

int main() {
    int a, b, c, delta;
    double x1, x2;

    std::cout << "Phuong trinh bac 2" << std::endl;
    do {
        std::cout << "Nhap so he so a (a khac 0): ";
        std::cin >> a;

        if (a == 0) {
            std::cout << "Xin nhap lai!" << std::endl;
        }
    } while(a == 0);

    std::cout << "Nhap he so b: ";
    std::cin >> b;
    std::cout << "Nhap he so c: ";
    std::cin >> c;

    delta = (b*b) - (4*a*c);

    if (delta < 0) {
        std::cout << "Phuong trinh vo nghiem" << std::endl;
    } else if (delta == 0) {
        x1 = x2 = ((-1.0) * b) / (2*a);
        std::cout << "Phuong tring co nghiem kep: " << x1 << std::endl;
    } else {
        x1 = (((-1.0) * b) + pow(delta, (1.0/2))) / (2*a);
        x2 = (((-1.0) * b) - pow(delta, (1.0/2))) / (2*a);
        std::cout << "Phuong trinh co 2 nghiem" << std::endl;
        std::cout << "Nghiem x1: " << x1 << std::endl;
        std::cout << "Nghiem x2: " << x2 << std::endl;
    }

    return 0;
}