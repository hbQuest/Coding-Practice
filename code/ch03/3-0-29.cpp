#include <stdio.h>
#include <conio.h>

int main() {
    const int a = 1000, b = 2000, c = 5000, tong = 200000; 
    int count = 0;
    for (int i = 0; i <= 200; i++) {
        for (int j = 0; j <= 100; j++) {
            for (int k = 0; k <= 40; k++) {
                if (i*a + j*b + k*c == tong) {
                    printf("%d to 1000 dong, %d to 2000 dong, %d to 5000 dong\n", i, j, k);
                    count++;
                }
            }
        }
    }

    printf("Tong cong %d phuong an", count);
    return 0;
}