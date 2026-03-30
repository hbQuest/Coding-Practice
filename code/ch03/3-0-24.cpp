#include <stdio.h>
#include <math.h>

void docSoNguyen(int x) {
    int n = abs(x), s, i=1;

    if (x < 0) {
        printf("Am ");
    }

    while (i <= 10) {
        s = (((n*i)/10) % 10);

        if (s == 1) {
            if (i == 1) {
                printf("muoi ");
            } else {
                printf("mot ");
            }
        } else if (s == 2) {
            printf("hai ");
        } else if (s == 3) {
            printf("ba ");
        } else if (s == 4) {
            printf("bon ");
        } else if (s == 5) {
            if (i == 10) {
                printf("lam ");
            } else {
                printf("nam ");
            }
        } else if (s == 6) {
            printf("sau ");
        } else if (s == 7) {
            printf("bay ");
        } else if (s == 8) {
            printf("tam ");
        } else if (s == 9) {
            printf("chin ");
        }
  

        if (i == 1 && s != 1) {
            printf("muoi ");
        } 

        if (n % 10 == 0) {
            break;
        }

        i *= 10;
    }   
}

int main() {
    int x;
    
    do {
        printf("Nhap so nguyen co hai chu so x = ");
        scanf("%d", &x);
        if (abs(x) < 10) {
            printf("So khong hop le! Xin nhap lai!\n");
        }
    } while (abs(x) < 10);

    docSoNguyen(x);
    return 0;
}