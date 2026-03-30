#include <stdio.h>
#include <conio.h>

void xuatKiTu() {
    char a = 'A';
    for(a; a <= 'Z'; a++) {
        printf("%c ", a);
    }
}

int main() {
    xuatKiTu();

    return 0;
}
