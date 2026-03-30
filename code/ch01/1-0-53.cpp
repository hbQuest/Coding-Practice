#include <iostream>

int main() {
    long long n, soDu, max, dem = 0;

    do {
        std::cout << "Nhap so nguyen duong n: ";
        std::cin >> n;

        if (n < 1) {
            std::cout << "Xin nhap lai!" << std::endl;
        }
    } while(n < 1);

    max = n%10;

    do {
        soDu = n%10;
        if (max < soDu) {
            max = soDu;
            dem = 1;
        } else if (max == soDu) {
            dem++;
        }
    } while (n /= 10);

    std::cout << "Chu so lon nhat la: " << max << std::endl;
    std::cout << "So luong chu so lon nhat cua so nguyen duong n la: " << dem << std::endl;
    return 0;
}