#include <iostream>

int main() {
    int a, b, BCNN, max, min;

    do {
        std::cout << "Nhap so nguyen duong a: ";
        std::cin >> a;

        if (a < 1) {
            std::cout << "Xin nhap lai!" << std::endl;
        }
    } while(a < 1);

    do {
        std::cout << "Nhap so nguyen duong b: ";
        std::cin >> b;

        if (b < 1) {
            std::cout << "Xin nhap lai!" << std::endl;
        }
    } while(b < 1);

    if (a > b) {
        max = a;
        min = b;
    } else {
        max = b;
        min = a;
    }

   for (int i = max; i <= (max*min); i += max) {
        if (i%max == 0 && i%min == 0) {
            BCNN = i;
            break;
        }
    }

    std::cout << "BCNN cua a va b la: " << BCNN <<  std::endl;

    //Cach 3
    // while (a != b) {
    //     if (a > b) {
    //         a = a - b;
    //     } else {
    //         b = b - a;
    //     }
    // }
    // std::cout << "BCNN cua a va b la: " << a <<  std::endl;

    return 0;
}