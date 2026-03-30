#include <iostream>

int main() {
    int a, b, UCLN, max, min;

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

    for (int i = min; i >= 1; i--) {
        if (max%i == 0 && min%i == 0) {
            UCLN = i;
            break;
        }
    }

    // cach 2
    // if (max%min == 0) {
    //     UCLN = min;
    // } else {
    //     for (int i = min / 2; i >= 1; i--) {
    //         if (max%i == 0 && min%i == 0) {
    //             UCLN = i;
    //             break;
    //         }
    //     }
    // }

    std::cout << "UCLN cua a va b la: " << UCLN <<  std::endl;

    //Cach 3
    // while (a != b) {
    //     if (a > b) {
    //         a = a - b;
    //     } else {
    //         b = b - a;
    //     }
    // }
    // std::cout << "UCLN cua a va b la: " << a <<  std::endl;

    return 0;
}