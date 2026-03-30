#include <iostream>

int main() {
    int n, max = 1;

    do {
        std::cout << "Nhap so nguyen duong n: ";
        std::cin >> n;

        if (n <=0 ) {
            std::cout << "Xin nhap lai!" << std::endl;
        }
    } while (n<=0);

    for (int i=1; i <= n; i++) {
        if (n%i == 0 && i%2 != 0 && i > max) {
            max = i;
        }
    }
    std::cout << "Uoc so le lon nhat cua n = " << n << " la: " << max;
    return 0;
}