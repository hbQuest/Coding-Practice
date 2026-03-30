#include <iostream>

int main() {
    int n, tichLe = 1, soDu, demLe = 0;

    do {
        std::cout << "Nhap so nguyen duong n: ";
        std::cin >> n;

        if (n < 1) {
            std::cout << "Xin nhap lai!" << std::endl;
        }
    } while(n < 1);

    while (n >= 1) {
        soDu = n%10;
        if (soDu%2 != 0) {
            demLe++;
            tichLe *= soDu;
        }
        n = n / 10;
    }

    if (demLe == 0) {
        tichLe = 0;
    }

    std::cout << "Tich cac chu so le cua so nguyen duong n la: " << tichLe << std::endl;
    return 0;
}