#include <iostream>
#include <cmath>

int main() {
    int a, b, c, delta;
    double x1, x2, x3, x4;

    std::cout << "Phuong trinh trung phuong" << std::endl;
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
        x1 = x3 = ((-1.0) * b) / (2*a);
    } else {
        x1 = (((-1.0) * b) + pow(delta, (1.0/2))) / (2*a);
        x3 = (((-1.0) * b) - pow(delta, (1.0/2))) / (2*a);
    }

    if (x1 < 0 && x3 < 0) {
        std::cout << "Phuong trinh vo nghiem" << std::endl;
    } else {
        std::cout << "Nghiem cua phuong trinh la: ";
        if (x1 >= 0) {
            x1 = pow(x1, (1.0/2));
            x2 = (-1) * x1;
            std::cout << x1 << ", " << x2 << ", "; 
        }
        if (x3 >= 0) {
            x3 = pow(x1, (1.0/2));
            x4 = (-1) * x3;
            std::cout << x3 << ", " << x4; 
        }
    }

    return 0;
}