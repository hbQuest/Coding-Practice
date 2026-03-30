#include <iostream>

int main() {
    long long n;
    int soDu, min, dem = 0;

    do {
        std::cout << "Nhap so nguyen duong n: ";
        std::cin >> n;

        if (n < 1) {
            std::cout << "Xin nhap lai!" << std::endl;
        }
    } while(n < 1);

    min = n%10;

    do {
        soDu = n%10;
        if (min > soDu) {
            min = soDu;
            dem = 1;
        } else if (min == soDu) {
            dem++;
        }
    } while (n /= 10);

    std::cout << "Chu so nho nhat la: " << min << std::endl;
    std::cout << "So luong chu so nho nhat cua so nguyen duong n la: " << dem << std::endl;
    return 0;
}